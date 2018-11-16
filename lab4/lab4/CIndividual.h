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

private:
	//SKLADOWE
	int numberOfGenes;
	int *genotype;
	double fitness;
	CKnapsackProblem *knapsackProblem;


	//METODY
	void mutate(int index);//

	vector<CIndividual*>* crossWith(CIndividual &secondParent);



	void updateFitness();//

	void generateRandomGenotype();//

	int giveRandomNumber(int from, int to);//
};

