#include "CGeneticAlgorithm.h"



CGeneticAlgorithm::CGeneticAlgorithm(double mutProb, double crossProb, int popSize, CKnapsackProblem *problem)
{
	populationSize = (popSize % 2 == 0) ? popSize : popSize + 1;
	mutationProbability = mutProb;
	crossProbability = crossProb;
	knapsackProblem = problem;

	generateStartingPopulation();
}


CGeneticAlgorithm::~CGeneticAlgorithm()
{
	deletePopulation();
	//cout << population.size() << endl;
}


void CGeneticAlgorithm::generateStartingPopulation()
{
	for (int i = 0; i < populationSize; i++)
	{
		population.push_back(new CIndividual(knapsackProblem));
	}
	//cout << "population size = " << population.size() << endl;
}



CIndividual* CGeneticAlgorithm::run(int iterationNumber)
{
	CIndividual* bestOne = NULL;








	return bestOne;
}



void CGeneticAlgorithm::deletePopulation()
{
	for (unsigned int i = 0; i < population.size(); i++)
	{
		delete population[i];
	}
	population.clear();
}













