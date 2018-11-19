#include "CIndividual.h"




class CGeneticAlgorithm
{

public:

	CGeneticAlgorithm(double mutProb, double crossProb, int popSize, CKnapsackProblem *problem);

	~CGeneticAlgorithm();

	CIndividual* run();

private:

	double mutationProbability;
	double crossProbability;
	int populationSize;

	CKnapsackProblem *knapsackProblem;
	vector<CIndividual*> *population;


	//METODY

	void generateStartingPopulation();

	int giveRandomIndex();

	double giveRandomProbability();

	void deletePopulation();

	void mutatePopulation();

	CIndividual* findBestOne();

};

