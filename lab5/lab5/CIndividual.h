#include <vector>
#include "CKnapsackProblem.h"

#define S_CHOSEN_ITEM_IS "wybrano objekty o numerach: "
#define S_NAME_IS_EQUAL_TO "name = "
#define S_WEIGHT_IS_EQUAL_TO " weight = "
#define S_VALUE_IS_EQUAL_TO " value = "
#define S_TOTAL_VALUE_IS " o lacznej wartosci "
#define S_COMA ", "


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



















