#include "CIndividual.h"




class CGeneticAlgorithm
{

public:

	CGeneticAlgorithm(double mutProb, double crossProb, int popSize, CKnapsackProblem *problem);

	~CGeneticAlgorithm();

	CIndividual* run(int iterationNumber);

private:

	double mutationProbability;
	double crossProbability;
	int populationSize;

	CKnapsackProblem *knapsackProblem;
	vector<CIndividual*> population;


	//METODY

	void generateStartingPopulation();

};

