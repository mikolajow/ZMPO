#include "CGeneticAlgorithm.h"
#include <random>


CGeneticAlgorithm::CGeneticAlgorithm(double mutProb, double crossProb, int popSize, CKnapsackProblem *problem, double scal)
{
	//modyfikacja
	scale = scal;

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
		cout << S_GIVE_ITERATION_NUMBER << endl;
		cin >> iterationNumber;

		for (int i = 0; i < iterationNumber; i++)
		{
			newPopulation = new vector<CIndividual*>;


			//modyfykacja rozmiaru

			int scaledSize = (int) (populationSize * scale);

			if (scaledSize < 2)
				scaledSize = 2;

			scaledSize = (scaledSize % 2 == 0) ? scaledSize : scaledSize + 1;

			


			while (  newPopulation->size()  != scaledSize)



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


			deletePopulation();

			population = newPopulation;

			//MUTOWANIE NOWEJ POPULACJI
			mutatePopulation();



			//modyfikacja wynik

			cout << population->size() << endl;


			populationSize = scaledSize;

		}//for (int i = 0; i < iterationNumber; i++)

		bestOne = findBestOne();

		cout << S_BEST_ONE_IS << endl;
		cout << bestOne->toString() << endl;


		cout << S_GIVE_ZERO_TO_FINISH << endl;
		cin >> shallIFinish;
	} while (shallIFinish != 0);

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
	return prob/ 100000;
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


void CGeneticAlgorithm::mutatePopulation()
{
	double mutationProb;

	for (unsigned int i = 0; i < population->size(); i++)
	{
		CIndividual *currentIndividual = (*population)[i];
		for (int j = 0; j < currentIndividual->getNumberOfGenes(); j++)
		{
			mutationProb = giveRandomProbability();
			if (mutationProb <= mutationProbability)
			{
				currentIndividual->mutate(j);
			}//if (mutationProb<=mutationProbability)
		}//(int j = 0; j < currentIndividual->getNumberOfGenes(); j++)
	}//koniec mutowania osobnikow
}

CIndividual* CGeneticAlgorithm::findBestOne()
{
	CIndividual *bestOne = (*population)[0];
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













