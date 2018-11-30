#include <vector>
#include "CKnapsackProblem.h"

using namespace std;

class CIndividual
{
public:
	CIndividual(CKnapsackProblem *knapsackP);

	CIndividual(const CIndividual &orginal);

	~CIndividual();

	int* getGenotype() const;
	double getFitness() const;
	int getNumberOfGenes() const;
	CKnapsackProblem* getKnapsackProblem() const;

	void mutate(int index);//

	string toString();

	vector<CIndividual*>* crossWith(CIndividual &secondParent);//

private:
	//SKLADOWE
	int numberOfGenes;
	int *genotype;
	double fitness;
	CKnapsackProblem *knapsackProblem;

	//konstruktor prywatny
	CIndividual(CKnapsackProblem *knapsackP, int *gen);


	//METODY


	void updateFitness();//

	void generateRandomGenotype();//

	int giveRandomNumber(int from, int to);//
};

