#include "CGeneticAlgorithm.h"
#include <random>


CGeneticAlgorithm::CGeneticAlgorithm(double mutProb, double crossProb, int popSize, CKnapsackProblem *problem)
{
	populationSize = (popSize % 2 == 0) ? popSize : popSize + 1;
	mutationProbability = mutProb;
	crossProbability = crossProb;
	knapsackProblem = problem;

	population = new vector<CIndividual*>;
	generateStartingPopulation();
}

CGeneticAlgorithm::~CGeneticAlgorithm()
{
	deletePopulation();
}

void CGeneticAlgorithm::generateStartingPopulation()
{
	for (int i = 0; i < populationSize; i++)
	{
		population->push_back(new CIndividual(knapsackProblem));
	}
	//cout << "population size = " << population.size() << endl;
}



CIndividual* CGeneticAlgorithm::run()
{
	int iterationNumber;

	CIndividual *bestOne;
	CIndividual *firstParent;
	CIndividual *secondParent;

	CIndividual *firstCandidate;
	CIndividual *secondCandidate;

	vector<CIndividual*> *newPopulation;

	int shallIFinish = 0;

	do
	{
		cout << "wprowadz liczbe iteracji " << endl;
		cin >> iterationNumber;


		for (int i = 0; i < iterationNumber; i++)
		{
			newPopulation = new vector<CIndividual*>;

			while (newPopulation->size() != populationSize)
			{

				int indexOfFirstParent;
				int indexOfFirstCandidate = giveRandomIndex();
				int indexOfSecondCandidate;

				//ZNALEZIENIE PIERWSZEGO RODZICA
				do
				{
					indexOfSecondCandidate = giveRandomIndex();
				} while (indexOfFirstCandidate == indexOfSecondCandidate);

				firstCandidate = (*population)[indexOfFirstCandidate];
				secondCandidate = (*population)[indexOfSecondCandidate];

				if (firstCandidate->getFitness() > secondCandidate->getFitness())
				{
					firstParent = firstCandidate;
					indexOfFirstParent = indexOfFirstCandidate;
				}
				else
				{
					firstParent = secondCandidate;
					indexOfFirstParent = indexOfSecondCandidate;
				}

				//ZNALEZIENIE DRUGIEGO RODZICA

				indexOfFirstCandidate = giveRandomIndex();
				while (indexOfFirstCandidate == indexOfFirstParent)
				{
					indexOfFirstCandidate = giveRandomIndex();
				}

				do
				{
					indexOfSecondCandidate = giveRandomIndex();
				} while (indexOfFirstCandidate == indexOfSecondCandidate);

				firstCandidate = (*population)[indexOfFirstCandidate];
				secondCandidate = (*population)[indexOfSecondCandidate];

				if (firstCandidate->getFitness() > secondCandidate->getFitness())
				{
					secondParent = firstCandidate;
				}
				else
				{
					secondParent = secondCandidate;
				}

				//KRZYZOWANIE
				double crossProb = giveRandomProbability();
				if (crossProb <= crossProbability)
				{
					vector<CIndividual*> *childrens = firstParent->crossWith(*secondParent);
					newPopulation->push_back((*childrens)[0]);
					newPopulation->push_back((*childrens)[1]);
					delete childrens;
				}
				else
				{
					//TRZEBA ZROBIC KOPIE BO ORGINALY USUWANE PO STWORZENIU NOWEJ POPULACJI
					newPopulation->push_back(new CIndividual(*firstParent));
					newPopulation->push_back(new CIndividual(*secondParent));
				}
			}//koniec while - wypelnianie nowej populacji


			//MUTOWANIE NOWEJ POPULACJI
			int mutationProb;

			for (unsigned int i = 0; i < newPopulation->size(); i++)
			{
				CIndividual *currentIndividual = (*newPopulation)[i];
				for (int j = 0; j < currentIndividual->getNumberOfGenes(); j++)
				{
					mutationProb = giveRandomProbability();
					if (mutationProb<=mutationProbability)
					{
						currentIndividual->mutate(j);
					}
				}

			}//koniec mutowania osobnikow

			deletePopulation();

			population = newPopulation;

		}//for (int i = 0; i < iterationNumber; i++)


		bestOne = (*population)[0];

		//find best one
		for (int i = 0; i < population->size(); i++)
		{
			CIndividual *current = (*population)[i];
			if (current->getFitness() > bestOne->getFitness())
			{
				bestOne = current;
			}
		}

		cout << "najlepszy wynik to" << endl;
		cout << bestOne->toString() << endl;


		cout << "wprowadz 0 dla zatrzymania dzialania inna liczbe dla ponownego przebiegu " << endl;
		cin >> shallIFinish;
	} while (shallIFinish != 0);

	bestOne = (*population)[0];

	//find best one
	for (int i = 0; i < population->size(); i++)
	{
		CIndividual *current = (*population)[i];
		if (current->getFitness() > bestOne->getFitness())
		{
			bestOne = current;
		}
	}

	return bestOne;
}



int CGeneticAlgorithm::giveRandomIndex()
{
	random_device rd;  //Will be used to obtain a seed for the random number engine
	mt19937 generator(rd()); //Standard mersenne_twister_engine seeded with rd()
	uniform_int_distribution<> generuj(0, populationSize-1);
	return generuj(generator);
}

double CGeneticAlgorithm::giveRandomProbability()
{
	double prob = 0;
	random_device rd;  //Will be used to obtain a seed for the random number engine
	mt19937 generator(rd()); //Standard mersenne_twister_engine seeded with rd()
	uniform_int_distribution<> generuj(0, 100000);
	prob = generuj(generator);
	return prob/100000;
}

void CGeneticAlgorithm::deletePopulation()
{
	for (unsigned int i = 0; i < population->size(); i++)
	{
		delete (*population)[i];
	}
	population->clear();
	delete population;
}


















