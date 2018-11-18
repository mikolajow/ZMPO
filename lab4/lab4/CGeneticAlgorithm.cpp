#include "CGeneticAlgorithm.h"



CGeneticAlgorithm::CGeneticAlgorithm(double mutProb, double crossProb, int popSize, CKnapsackProblem *problem)
{
	mutationProbability = mutProb;
	crossProbability = crossProb;
	populationSize = popSize;
	knapsackProblem = problem;

	generateStartingPopulation();
}


CGeneticAlgorithm::~CGeneticAlgorithm()
{
	for (unsigned int i = 0; i < population.size(); i++)
	{
		delete population[i];
		i--;
	}
}


void CGeneticAlgorithm::generateStartingPopulation()
{
	for (int i = 0; i < populationSize; i++)
	{
		population.push_back(new CIndividual(knapsackProblem));
	}
}



CIndividual* CGeneticAlgorithm::run(int iterationNumber)
{

}
















