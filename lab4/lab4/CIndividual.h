#include <vector>
#include "CKnapsackProblem.h"

using namespace std;

class CIndividual
{
public:
	CIndividual(CKnapsackProblem *knapsackP);
	CIndividual(CKnapsackProblem *knapsackP, int *gen);

	~CIndividual();

	int* getGenotype();
	double getFitness();
	int getNumberOfGenes();

	void mutate(int index);//

	vector<CIndividual*>* crossWith(CIndividual &secondParent);//

private:
	//SKLADOWE
	int numberOfGenes;
	int *genotype;
	double fitness;
	CKnapsackProblem *knapsackProblem;


	//METODY


	void updateFitness();//

	void generateRandomGenotype();//

	int giveRandomNumber(int from, int to);//
};

