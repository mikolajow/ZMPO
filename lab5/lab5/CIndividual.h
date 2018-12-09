#include <vector>
#include "typeinfo.h"
#include "CKnapsackProblem.h"
#include <random>

#define S_CHOSEN_ITEM_IS "wybrano objekty o numerach: "
#define S_NAME_IS_EQUAL_TO "name = "
#define S_WEIGHT_IS_EQUAL_TO " weight = "
#define S_VALUE_IS_EQUAL_TO " value = "
#define S_TOTAL_VALUE_IS " o lacznej wartosci "
#define S_COMA ", "
#define I_BIG_NUMBER_FOR_PROBABILITY 100000


using namespace std;

template <class T>
class CIndividual
{
public:
	CIndividual(CKnapsackProblem *knapsackP, double mutProb);

	CIndividual(const CIndividual &orginal);

	~CIndividual();

	T* getGenotype() const;	

	double getFitness() const;
	int getNumberOfGenes() const;
	CKnapsackProblem* getKnapsackProblem() const;


	CIndividual<T>& operator+(CIndividual<T> &secondParent);
	void operator++(int);

	string toString();

private:
	//SKLADOWE
	int numberOfGenes;
	T *genotype;												
	double fitness;
	double mutationProbability;
	CKnapsackProblem *knapsackProblem;

	//konstruktor prywatny
	CIndividual(CKnapsackProblem *knapsackP, T *gen, double mutProb);

	//METODY
	void updateFitness();
	void generateRandomGenotype();
	int giveRandomNumber(int from, int to);
	double giveRandomProbability();
};



//definicje -----------------------------------------------------------------------------------------------------


template<class T>
CIndividual<T>::CIndividual(CKnapsackProblem *knapsackP, double mutProb)
{
	mutationProbability = mutProb;
	knapsackProblem = knapsackP;
	numberOfGenes = knapsackP->getItemList()->size();
	genotype = new T[numberOfGenes];
	generateRandomGenotype();
	updateFitness();
}

//konstruktor prywatny
template<class T>
CIndividual<T>::CIndividual(CKnapsackProblem *knapsackP, T *gen, double mutProb)
{
	mutationProbability = mutProb;
	knapsackProblem = knapsackP;
	numberOfGenes = knapsackP->getItemList()->size();
	//tablica tworzona przez krzyzowanie
	genotype = gen;
	updateFitness();
}


template <class T>
CIndividual<T>::CIndividual(const CIndividual &orginal)
{
	mutationProbability = orginal.mutationProbability;
	numberOfGenes = orginal.getNumberOfGenes();
	knapsackProblem = orginal.getKnapsackProblem();
	genotype = new T[numberOfGenes];
	T *orginalGenothype = orginal.getGenotype();
	for (int i = 0; i < numberOfGenes; i++)
	{
		genotype[i] = orginalGenothype[i];
	}
	updateFitness();
}

template <class T>
CIndividual<T>::~CIndividual()
{
	delete[] genotype;
}

template <class T>
int CIndividual<T>::giveRandomNumber(int from, int to)
{
	random_device rd;  //Will be used to obtain a seed for the random number engine
	mt19937 generator(rd()); //Standard mersenne_twister_engine seeded with rd()
	uniform_int_distribution<> generuj(from, to);
	return generuj(generator);
}

template <class T> T* CIndividual<T>::getGenotype() const { return genotype; }
template <class T> double CIndividual<T>::getFitness() const { return fitness; }
template <class T> int CIndividual<T>::getNumberOfGenes() const { return numberOfGenes; }
template <class T> CKnapsackProblem* CIndividual<T>::getKnapsackProblem() const { return knapsackProblem; }

template<class T>
void CIndividual<T>::updateFitness()
{
	double totalVal = 0;
	double totalWeig = 0;
	double 	bagCapacity = knapsackProblem->getBagCapacity();
	vector<CItem*> *itemList = knapsackProblem->getItemList();

	for (unsigned int i = 0; i < numberOfGenes; i++)
	{
		CItem *currentItem = ((*itemList)[i]);
		totalVal = totalVal + (currentItem->getValue())*genotype[i];
		totalWeig = totalWeig + (currentItem->getWeight())*genotype[i];
	}//	for (unsigned int = 0; i < numberOfGenes; i++)

	fitness = (totalWeig > bagCapacity) ? 0 : totalVal;
}

template <class T>
string CIndividual<T>::toString()
{
	string description = S_CHOSEN_ITEM_IS;
	CItem *currentItem;

	for (int i = 0; i < numberOfGenes; i++)
	{
		if (genotype[i] != 0)
		{
			currentItem = (*knapsackProblem->getItemList())[i];
			cout << S_NAME_IS_EQUAL_TO << currentItem->getName() << S_WEIGHT_IS_EQUAL_TO << currentItem->getWeight() << S_VALUE_IS_EQUAL_TO << currentItem->getValue() << " ilosc = " << genotype[i] << endl;
			description = description + currentItem->getName() + S_COMA;
		}
	}
	description = description + S_TOTAL_VALUE_IS + to_string(fitness);
	return description;
}

template <class T>
double CIndividual<T>::giveRandomProbability()
{
	double prob = 0;
	random_device rd;  //Will be used to obtain a seed for the random number engine
	mt19937 generator(rd()); //Standard mersenne_twister_engine seeded with rd()
	uniform_int_distribution<> generuj(0, I_BIG_NUMBER_FOR_PROBABILITY);
	prob = generuj(generator);
	return prob / I_BIG_NUMBER_FOR_PROBABILITY;
}


//krzyzowanie operatorem
template <class T>
CIndividual<T>& CIndividual<T>::operator+(CIndividual<T> &secondParent)
{

	CIndividual<T> *firstParent = this;
	CKnapsackProblem *currentKnProblem = this->knapsackProblem;

	int cutPlace = giveRandomNumber(1, numberOfGenes - 1);

	T *firstChildGenothype = new T[numberOfGenes];

	//first genotype part
	for (int i = 0; i < cutPlace; i++)
		firstChildGenothype[i] = firstParent->getGenotype()[i];

	//second genotype part
	for (int i = cutPlace; i < numberOfGenes; i++)
		firstChildGenothype[i] = secondParent.getGenotype()[i];

	CIndividual<T> *child = new CIndividual<T>(this->knapsackProblem, firstChildGenothype, this->mutationProbability);

	return (*child);
}


//mutacja dla boola
template <class T>
void CIndividual<T>::operator++(int)
{
	for (int i = 0; i < numberOfGenes; i++)
	{
		double probability = giveRandomProbability();
		if (probability <= mutationProbability)
		{
			if (genotype[i] == 0)
				genotype[i] = 1;

			else
				genotype[i] = 0;
		}//koniec if - czy mutowac
	}//koniec for
	updateFitness();
}

//mutacja dla inta
void CIndividual<int>::operator++(int)
{
	for (int i = 0; i < numberOfGenes; i++)
	{
		double probability = giveRandomProbability();
		if (probability <= mutationProbability)
		{
			if (genotype[i] == 0)
				genotype[i] = 1;
			else
			{
				//cout << "genotyp przed mutacja = " << genotype[index] << endl;

				//jak nie jest zerem to 50% szans na wziecie dodatkowej sztuki danego przedmiotu
				//i  50% na od這瞠nie jednej sztuki danego przedmiotu
				int prob = giveRandomNumber(0, 1);
				if (prob == 0)
					genotype[i]++;
				else
					genotype[i]--;
				//cout << "genotyp po mutacji = " << genotype[index] << endl;
			}
		}//koniec if - czy mutowac
	}//koniec for
	updateFitness();
}

//mutacja dla doublea
void CIndividual<double>::operator++(int)
{
	for (int i = 0; i < numberOfGenes; i++)
	{
		double probability = giveRandomProbability();
		if (probability <= mutationProbability)
		{
			if (genotype[i] <= 0.51)
				genotype[i] = 1;
			else
			{
				//jak nie jest zerem to 50% szans na wziecie dodatkowej po這wy sztuki danego przedmiotu
				//i  50% na od這瞠nie po這wy jednej sztuki danego przedmiotu
				int prob = giveRandomNumber(0, 1);
				if (prob == 0)
					genotype[i] = genotype[i] - 0.5;
				else
					genotype[i] = genotype[i] + 0.5;
			}
		}//koniec if - czy mutowac
	}//koniec for
	updateFitness();
}









//	CZY TRZEBA COS ZMIENIAC? CZEMU POCZATKOWA POPULACJA NIE MIALABY WYGLADAC W TEN SPOSOB?
// ALBO ZMIENIC METODY ALBO ZDEFINIOWAC MAGICZNE NUMERKI

// dla boola
template<class T>
void CIndividual<T>::generateRandomGenotype()
{

	for (int i = 0; i < numberOfGenes; i++)
	{
		genotype[i] = giveRandomNumber(0, 1);
	}//koniec for
}//koniec generate random genotype


// dla inta
void CIndividual<int>::generateRandomGenotype()
{
	for (int i = 0; i < numberOfGenes; i++)
	{
		int number = giveRandomNumber(0, 3);
		genotype[i] = number;
	}//koniec for
}//koniec generate random genotype


// dla doubla
void CIndividual<double>::generateRandomGenotype()
{
	for (int i = 0; i < numberOfGenes; i++)
	{
		int number = giveRandomNumber(0, 30);
		double howMuch = ((double)number) / 10;
		genotype[i] = howMuch;
	}//koniec for
}//koniec generate random genotype














































