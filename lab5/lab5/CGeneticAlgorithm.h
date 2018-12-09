#include "CIndividual.h"

#define S_GIVE_ITERATION_NUMBER "wprowadz liczbe iteracji "
#define S_BEST_ONE_IS "najlepszy wynik to"
#define S_GIVE_ZERO_TO_FINISH "wprowadz 0 dla zatrzymania dzialania inna liczbe dla ponownego przebiegu " 
#define I_BIG_NUMBER_FOR_PROBABILITY 100000



template <class T>
class CGeneticAlgorithm
{

public:

	CGeneticAlgorithm(double mutProb, double crossProb, int popSize, CKnapsackProblem *problem);

	~CGeneticAlgorithm();

	CIndividual<T>* run();

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





