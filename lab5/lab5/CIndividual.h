#include <vector>
#include "typeinfo.h"
#include "CKnapsackProblem.h"

#define S_CHOSEN_ITEM_IS "wybrano objekty o numerach: "
#define S_NAME_IS_EQUAL_TO "name = "
#define S_WEIGHT_IS_EQUAL_TO " weight = "
#define S_VALUE_IS_EQUAL_TO " value = "
#define S_TOTAL_VALUE_IS " o lacznej wartosci "
#define S_COMA ", "


using namespace std;

template <class T>
class CIndividual
{
public:
	CIndividual(CKnapsackProblem *knapsackP);

	CIndividual(const CIndividual &orginal);

	~CIndividual();

	T* getGenotype() const;	

	double getFitness() const;
	int getNumberOfGenes() const;
	CKnapsackProblem* getKnapsackProblem() const;



	void mutate(int index);													//opretator++ postfixowy
	vector<CIndividual<T>*>* crossWith(CIndividual<T> &secondParent);		//przerobic na operator+ dodatkowo z template

	string toString();

private:
	//SKLADOWE
	int numberOfGenes;



	T *genotype;												


	double fitness;
	CKnapsackProblem *knapsackProblem;

	//konstruktor prywatny
	CIndividual(CKnapsackProblem *knapsackP, T *gen);

	//METODY
	void updateFitness();

	void generateRandomGenotype();

	int giveRandomNumber(int from, int to);
};










template<class T>
CIndividual<T>::CIndividual(CKnapsackProblem *knapsackP)
{
	knapsackProblem = knapsackP;
	numberOfGenes = knapsackP->getItemList()->size();
	genotype = new T[numberOfGenes];
	generateRandomGenotype();
	updateFitness();
}

//konstruktor prywatny
template<class T>
CIndividual<T>::CIndividual(CKnapsackProblem *knapsackP, T *gen)
{
	knapsackProblem = knapsackP;
	numberOfGenes = knapsackP->getItemList()->size();
	//tablica tworzona przez krzyzowanie
	genotype = gen;
	updateFitness();
}


template <class T>
CIndividual<T>::CIndividual(const CIndividual &orginal)
{
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





//mutacja dla boola

void CIndividual<bool>::mutate(int index)
{
	if (genotype[index] == false)
	{
		genotype[index] = true;
	}
	else
	{
		genotype[index] = false;
	}
	updateFitness();
}//koniec mutacji






//mutacja dla inta
template <class T>
void CIndividual<T>::mutate(int index)
{
	if (genotype[index] == 0)
	{
		genotype[index] = 1;
	}
	else
	{
		genotype[index] = 0;
	}
	updateFitness();
}//koniec mutacji












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
		totalWeig = totalWeig + currentItem->getWeight()*genotype[i];
	}//	for (unsigned int = 0; i < numberOfGenes; i++)

	fitness = (totalWeig > bagCapacity) ? 0 : totalVal;
}


//	CZY TRZEBA COS ZMIENIAC? CZEMU POCZATKOWA POPULACJA NIE MIALABY WYGLADAC W TEN SPOSOB?

template<class T>
void CIndividual<T>::generateRandomGenotype()
{

	for (int i = 0; i < numberOfGenes; i++)
	{
		genotype[i] = giveRandomNumber(0, 1);
	}//koniec for
}//koniec generate random genotype







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



template <class T>
vector<CIndividual<T>*>* CIndividual<T>::crossWith(CIndividual &secondParent)
{

	vector<CIndividual<T>*> *childrens = new vector<CIndividual<T>*>;

	CIndividual<T> *firstParent = this;
	CKnapsackProblem *currentKnProblem = this->knapsackProblem;

	int cutPlace = giveRandomNumber(1, numberOfGenes - 1);

	T *firstChildGenothype = new T[numberOfGenes];
	T *secondChildGenothype = new T[numberOfGenes];

	//first genotype part
	for (int i = 0; i < cutPlace; i++)
	{
		firstChildGenothype[i] = firstParent->getGenotype()[i];
		secondChildGenothype[i] = secondParent.getGenotype()[i];
	}

	//second genotype part
	for (int i = cutPlace; i < numberOfGenes; i++)
	{
		firstChildGenothype[i] = secondParent.getGenotype()[i];
		secondChildGenothype[i] = firstParent->getGenotype()[i];
	}

	CIndividual<T> *fstChild = new CIndividual<T>(this->knapsackProblem, firstChildGenothype);
	CIndividual<T> *sndChild = new CIndividual<T>(this->knapsackProblem, secondChildGenothype);

	childrens->push_back(fstChild);
	childrens->push_back(sndChild);

	//cout << "cut place = " << cutPlace << endl;

	return childrens;
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
			cout << S_NAME_IS_EQUAL_TO << currentItem->getName() << S_WEIGHT_IS_EQUAL_TO << currentItem->getWeight() << S_VALUE_IS_EQUAL_TO << currentItem->getValue() << endl;
			description = description + currentItem->getName() + S_COMA;
		}
	}
	description = description + S_TOTAL_VALUE_IS + to_string(fitness);
	return description;
}















