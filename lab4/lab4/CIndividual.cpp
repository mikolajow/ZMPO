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

CIndividual::CIndividual(CKnapsackProblem *knapsackP, int *gen)
{
	knapsackProblem = knapsackP;
	numberOfGenes = knapsackP->getItemList()->size();
	genotype = gen;
	updateFitness();
}


CIndividual::~CIndividual()
{
	delete genotype;
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

int* CIndividual::getGenotype() { return genotype; }


vector<CIndividual*>* CIndividual::crossWith(CIndividual &secondParent)
{
	CIndividual *firstParent = this;
	CKnapsackProblem *currentKnProblem = this->knapsackProblem;

	vector<CIndividual*> *childrens = new vector<CIndividual*>;

	int cutPlace = giveRandomNumber(1, numberOfGenes - 1);

	int *firstChildGenothype = new int[numberOfGenes];
	int *secondChildGenothype = new int[numberOfGenes];

	for (int i = 0; i < cutPlace; i++)
	{

	}


	
	return childrens;
}































