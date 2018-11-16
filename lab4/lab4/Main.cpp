#include <string>
#include <iostream>
//#include "CKnapsackProblem.h"
#include <random>
#include "CIndividual.h"

using namespace std;



int main()
{

	cout << "main" << endl;

	CItem *banana = new CItem("banan", 22.2, 33.2);
	CItem *a = new CItem("a", 1, 1);
	CItem *b = new CItem("b", 2, 2);
	CItem *c = new CItem("c", 3, 3);



	vector<CItem*> itemList;
	itemList.push_back(banana);
	itemList.push_back(a);
	itemList.push_back(b);
	itemList.push_back(c);

	CKnapsackProblem *problem = new CKnapsackProblem(&itemList, 40.);

	CIndividual *fstOsobnik = new CIndividual(problem);

	int *genotyp = fstOsobnik->getGenotype();

	cout << genotyp[0] << endl;
	cout << genotyp[1] << endl;
	cout << genotyp[2] << endl;
	cout << genotyp[3] << endl;

	string n;
	cin >> n;

	return 0;
}//koniec main




















