#include <iostream>
#include <string>
#include "CDynaTable.h"

using namespace std;

int main()
{

	CDynaTable dynaTable0;
	CDynaTable dynaTable1;

	bool success = dynaTable0.setValueOnIndex(0, 3);
	cout << success << endl;

	dynaTable0.add(4);

	success = dynaTable0.setValueOnIndex(2, 9);
	cout << success << endl;

	dynaTable0.add(5);

	dynaTable1.add(11);
	dynaTable1.add(12);

	dynaTable0.addValues(dynaTable1);

	cout << "zawartosc tablicy 0 po sklejeniu" << endl;

	for (int i = 0; i < dynaTable0.size; i++)
		cout << *(dynaTable0.getValueFromIndex(i)) << ", ";

	cout << endl;
	cout << "zawartosc tablicy 0 po operatorze =" << endl;

	dynaTable0 = dynaTable1;

	for (int i = 0; i < dynaTable0.size; i++)
		cout << *(dynaTable0.getValueFromIndex(i))<< ", ";


	int *getTest = dynaTable0.getValueFromIndex(-3);
	cout << getTest << endl;


	CDynaTable *test = new CDynaTable();
	delete test;


	string s;
	cin >> s;

	return 0;
}//koniec main































