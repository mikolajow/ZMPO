#include <string>
#include <iostream>
//#include "CKnapsackProblem.h"
#include <random>
//#include "CIndividual.h"
#include "CGeneticAlgorithm.h"

using namespace std;



int main()
{

	// TEST 2

	CItem *a = new CItem("1", 3, 5);
	CItem *b = new CItem("2", 10, 12);
	CItem *c = new CItem("3", 8, 10);
	CItem *d = new CItem("4", 6, 7);
	CItem *e = new CItem("5", 2, 1);
	CItem *f = new CItem("6", 9, 11);



	vector<CItem*> itemList;
	itemList.push_back(a);
	itemList.push_back(b);
	itemList.push_back(c);
	itemList.push_back(d);
	itemList.push_back(e);
	itemList.push_back(f);






	CKnapsackProblem *problem = new CKnapsackProblem(&itemList, 20.);

	CGeneticAlgorithm *alg = new CGeneticAlgorithm(0.3, 0.3, 15, problem);

	alg->run();














	////TEST 1

	//CItem *banana = new CItem("1", 4, 5);
	//CItem *a = new CItem("2", 1, 1);
	//CItem *b = new CItem("3", 3, 4);
	//CItem *c = new CItem("4", 2, 3);

	//vector<CItem*> itemList;
	//itemList.push_back(banana);
	//itemList.push_back(a);
	//itemList.push_back(b);
	//itemList.push_back(c);

	//CKnapsackProblem *problem = new CKnapsackProblem(&itemList, 5.);


	//CGeneticAlgorithm *alg = new CGeneticAlgorithm(0.3, 0.3, 24, problem);



	//alg->run();




















	//CIndividual *fstOsobnik = new CIndividual(problem);

//int *genotyp = fstOsobnik->getGenotype();

//cout << "genotyp pierwszego: " << genotyp[0] << genotyp[1] << genotyp[2] << genotyp[3] << endl;

//CIndividual *sndOsobnik = new CIndividual(problem);

//int *drugiGenotyp = sndOsobnik->getGenotype();

//cout << "genotyp drugiego: " << drugiGenotyp[0] << drugiGenotyp[1] << drugiGenotyp[2] << drugiGenotyp[3] << endl;





	//delete alg;


	//double prob = 0;

	//random_device rd;  //Will be used to obtain a seed for the random number engine
	//mt19937 generator(rd()); //Standard mersenne_twister_engine seeded with rd()
	//uniform_int_distribution<> generuj(0, 100000);
	//prob = generuj(generator);

	//cout << "prawdopodobienstwo wynosi = " << prob  <<"podzielone na 100000" << endl;
	//cout << prob / 100000 << endl;

	//vector<CIndividual*> *vec = fstOsobnik->crossWith(*sndOsobnik);

	//CIndividual *child1 = (*vec)[0];
	//CIndividual *child2 = (*vec)[1];

	//int *child1geno = child1->getGenotype();
	//int *child2geno = child2->getGenotype();

	//cout << "genotyp dziecka 1: " << child1geno[0] << child1geno[1] << child1geno[2] << child1geno[3] << endl;
	//cout << "genotyp dziecka 2: " << child2geno[0] << child2geno[1] << child2geno[2] << child2geno[3] << endl;






	//string n;
	//cin >> n;

	//return 0;
}//koniec main




















