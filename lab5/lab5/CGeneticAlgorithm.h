#include "CIndividual.h"
#include <ctime>

#define S_GIVE_ITERATION_NUMBER "wprowadz liczbe iteracji "
#define S_BEST_ONE_IS "najlepszy wynik to"
#define S_GIVE_ZERO_TO_FINISH "wprowadz 1 aby zakonczyc" 
#define I_BIG_NUMBER_FOR_PROBABILITY 100000



template <class T>
class CGeneticAlgorithm
{

public:

	CGeneticAlgorithm(double mutProb, double crossProb, int popSize, CKnapsackProblem *problem);

	~CGeneticAlgorithm();

	CIndividual<T>* run(int time);

private:

	CIndividual<T> *currentBest;

	double mutationProbability;
	double crossProbability;
	int populationSize;

	CKnapsackProblem *knapsackProblem;
	vector<CIndividual<T>*> *population;


	//METODY

	void generateStartingPopulation();

	int giveRandomIndex();

	double giveRandomProbability();

	void deletePopulation();

	void mutatePopulation();

	CIndividual<T>* findBestOne();

};

// definicje --------------------------------------------------------------------------------------------------------------------------



template <class T>
CGeneticAlgorithm<T>::CGeneticAlgorithm(double mutProb, double crossProb, int popSize, CKnapsackProblem *problem)
{
	populationSize = (popSize % 2 == 0) ? popSize : popSize + 1;
	mutationProbability = mutProb;
	crossProbability = crossProb;
	knapsackProblem = problem;

	population = new vector<CIndividual<T>*>;
	generateStartingPopulation();
}


template <class T>
CGeneticAlgorithm<T>::~CGeneticAlgorithm()
{
	deletePopulation();
}

template <class T>
void CGeneticAlgorithm<T>::generateStartingPopulation()
{
	for (int i = 0; i < populationSize; i++)
	{
		population->push_back(new CIndividual<T>(knapsackProblem, mutationProbability));
	}
}





template <class T>
CIndividual<T>* CGeneticAlgorithm<T>::run(int iterationTime)
{

	CIndividual<T> *bestOne;
	CIndividual<T> *firstParent;
	CIndividual<T> *secondParent;

	CIndividual<T> *firstCandidate;
	CIndividual<T> *secondCandidate;

	vector<CIndividual<T>*> *newPopulation;

	double startTime = time(nullptr);
	double currentTime = 0;


		while(currentTime < iterationTime)
		{
			newPopulation = new vector<CIndividual<T>*>;

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
					newPopulation->push_back(&((*firstParent) + (*secondParent)));
					newPopulation->push_back(&((*secondParent) + (*firstParent)));
				}
				else
				{
					//TRZEBA ZROBIC KOPIE BO ORGINALY USUWANE PO STWORZENIU NOWEJ POPULACJI
						newPopulation->push_back(new CIndividual<T>(*firstParent));
						newPopulation->push_back(new CIndividual<T>(*secondParent));
				}

			}//koniec while - wypelnianie nowej populacji

			deletePopulation();

			population = newPopulation;

			//MUTOWANIE NOWEJ POPULACJI
			mutatePopulation();

			currentTime = time(nullptr) - startTime;
		}//while(finish < iterationTime)

		bestOne = findBestOne();

		cout << S_BEST_ONE_IS << endl;
		cout << bestOne->toString() << endl;

	currentBest = bestOne;
	return bestOne;
}




template <class T>
int CGeneticAlgorithm<T>::giveRandomIndex()
{
	random_device rd;  //Will be used to obtain a seed for the random number engine
	mt19937 generator(rd()); //Standard mersenne_twister_engine seeded with rd()
	uniform_int_distribution<> generuj(0, populationSize - 1);
	return generuj(generator);
}

template <class T>
double CGeneticAlgorithm<T>::giveRandomProbability()
{
	double prob = 0;
	random_device rd;  //Will be used to obtain a seed for the random number engine
	mt19937 generator(rd()); //Standard mersenne_twister_engine seeded with rd()
	uniform_int_distribution<> generuj(0, I_BIG_NUMBER_FOR_PROBABILITY);
	prob = generuj(generator);
	return prob / I_BIG_NUMBER_FOR_PROBABILITY;
}

template<class T>
void CGeneticAlgorithm<T>::deletePopulation()
{
	for (unsigned int i = 0; i < population->size(); i++)
	{
		delete (*population)[i];
	}
	population->clear();
	delete population;
}

template <class T>
CIndividual<T>* CGeneticAlgorithm<T>::findBestOne()
{
	CIndividual<T> *bestOne = (*population)[0];
	for (int i = 0; i < population->size(); i++)
	{
		CIndividual<T> *current = (*population)[i];
		if (current->getFitness() > bestOne->getFitness())
		{
			bestOne = current;
		}
	}
	return bestOne;
}

template <class T>
void CGeneticAlgorithm<T>::mutatePopulation()
{
	double mutationProb;

	for (unsigned int i = 0; i < population->size(); i++)
	{
		CIndividual<T> *currentIndividual = (*population)[i];
		mutationProb = giveRandomProbability();

		if (mutationProb <= mutationProbability)
			currentIndividual++;
	}//koniec mutowania osobnikow
}































