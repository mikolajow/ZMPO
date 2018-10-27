#pragma once

#include "CTable.h"
#include <vector>

using namespace std;

#define S_WRONG_INDEX "Podano zly index, nie ma tylu objektow lub podana wartosc jest ujemna, wprowadz ja jeszcze raz"
#define S_NOT_A_NUMBER "Podana wartosc nie jest prawidlowa liczba, wprowadz wartosc jeszcze raz"
#define I_ASCII_ZERO 48
#define I_ASCII_NINE 57
#define I_ASCII_PLUS 43
#define I_ASCII_MINUS 45


class CTableCollector {


public:

	 bool isNumber(string data);
	 int giveMeANumber();
	 int giveMeAnIndex();

	 vector<CTable*>* getVector();

private:

	vector<CTable*> list;

};































