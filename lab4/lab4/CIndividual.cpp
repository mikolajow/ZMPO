#include "CIndividual.h"
#include <random>


CIndividual::CIndividual(CKnapsackProblem *knapsackP)
{
	knapsackProblem = knapsackP;
	numberOfGenes = knapsackP->getItemList()->size();
	genotype = new int[ numberOfGenes ];
	generateRandomGenotype();
	updateFitness();
}

//konstruktor prywatny
CIndividual::CIndividual(CKnapsackProblem *knapsackP, int *gen)
{
	knapsackProblem = knapsackP;
	numberOfGenes = knapsackP->getItemList()->size();
	//tablica tworzona przez krzyzowanie
	genotype = gen;
	updateFitness();
}


CIndividual::CIndividual(const CIndividual &orginal)
{
	numberOfGenes = orginal.getNumberOfGenes();
	knapsackProblem = orginal.getKnapsackProblem();
	genotype = new int[numberOfGenes];
	int *orginalGenothype = orginal.getGenotype();
	for (int i = 0; i < numberOfGenes; i++)
	{
		genotype[i] = orginalGenothype[i];
	}
	updateFitness();
}


CIndividual::~CIndividual()
{
	delete[] genotype;
}


void CIndividual::mutate(int index)
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

void CIndividual::updateFitness()
{
	double totalVal = 0;
	double totalWeig = 0;
	double 	bagCapacity = knapsackProblem->getBagCapacity();
	vector<CItem*> *itemList = knapsackProblem->getItemList();


	for (unsigned int i= 0; i < numberOfGenes; i++)
	{
		if (genotype[i] ==1)
		{
			CItem *currentItem = ((*itemList)[i]);
			totalVal = totalVal + currentItem->getValue();
			totalWeig = totalWeig + currentItem->getWeight();
		}
	}//	for (unsigned int = 0; i < numberOfGenes; i++)

	fitness = (totalWeig > bagCapacity) ? 0 : totalVal;
}

void CIndividual::generateRandomGenotype()
{
	for (int i = 0; i < numberOfGenes; i++)
	{
		genotype[i] = giveRandomNumber(0, 1);
	}//koniec for
}//koniec generate random genotype

int CIndividual::giveRandomNumber(int from, int to)
{
	random_device rd;  //Will be used to obtain a seed for the random number engine
	mt19937 generator(rd()); //Standard mersenne_twister_engine seeded with rd()
	uniform_int_distribution<> generuj(from, to);
	return generuj(generator);
}

int* CIndividual::getGenotype() const { return genotype; }
double CIndividual::getFitness() const { return fitness; }
int CIndividual::getNumberOfGenes() const { return numberOfGenes; }
CKnapsackProblem* CIndividual::getKnapsackProblem() const { return knapsackProblem; }

vector<CIndividual*>* CIndividual::crossWith(CIndividual &secondParent)
{

	vector<CIndividual*> *childrens = new vector<CIndividual*>;

	CIndividual *firstParent = this;
	CKnapsackProblem *currentKnProblem = this->knapsackProblem;

	int cutPlace = giveRandomNumber(1, numberOfGenes -1);

	int *firstChildGenothype = new int[numberOfGenes];
	int *secondChildGenothype = new int[numberOfGenes];

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

	CIndividual *fstChild = new CIndividual(this->knapsackProblem, firstChildGenothype);
	CIndividual *sndChild = new CIndividual(this->knapsackProblem, secondChildGenothype);
	
	childrens->push_back(fstChild);
	childrens->push_back(sndChild);

	//cout << "cut place = " << cutPlace << endl;

	return childrens;
}



string CIndividual::toString()
{
	string description = S_CHOSEN_ITEM_IS;
	CItem *currentItem;

	for (int i = 0; i < numberOfGenes; i++)
	{
		if (genotype[i] == 1)
		{
			currentItem = (*knapsackProblem->getItemList())[i];
			cout << S_NAME_IS_EQUAL_TO << currentItem->getName() << S_WEIGHT_IS_EQUAL_TO  <<currentItem->getWeight() << S_VALUE_IS_EQUAL_TO << currentItem->getValue() << endl;
			description = description + currentItem->getName() + S_COMA;
		}
	}
	description = description + S_TOTAL_VALUE_IS + to_string(fitness);
	return description;
}





























