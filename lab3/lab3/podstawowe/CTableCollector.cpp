#include "CTableCollector.h"
#include <iostream>




vector <CTable*>* CTableCollector::getVector() {
	return &list;
}



	int CTableCollector::giveMeAnIndex() 
{
	int index = giveMeANumber();

	while ((unsigned int)index >= list.size() || index < 0) {
		cout << S_WRONG_INDEX << endl;
		index = giveMeANumber();
	}
	return index;
}

	bool CTableCollector::isNumber(string data) {
		int signCounter = 0;
		for (unsigned int i = 0; i < data.length(); i++) {
			int asciiValue = (int)data[i];

			if (asciiValue > I_ASCII_NINE || asciiValue < I_ASCII_ZERO) { //jesli wynikiem if jest true to znaczy ze dany znak nie jest cyfr¹ - 0 w ascii to 48 a 9 w ascii to 57
				if (asciiValue == I_ASCII_PLUS || asciiValue == I_ASCII_MINUS) {//sprawdzam czy jest znakiem +/- ,jesli jest to zwiekszam counter
					signCounter++;
				}
				else return false;//jesli nie jest cyfra ani znakiem to zwracam false
			}//koniec if

		}//koniec for

		switch (signCounter)
		{
		case 0: return true;	//jak nie ma znakow =/- a reszta to cyfry to jest liczba
		case 1: {
			if (data[0] == '+' || data[0] == '-') {
				return true; //jesli znak jest tylko na pierwszej pozycji
			}//koniec if
		}//koniec case 1
		default:
			return false;
		}//koniec switch

	}//koniec metody is number


	int CTableCollector::giveMeANumber() {
		string data;
		bool isANumber;
		do
		{
			getline(cin, data);
			isANumber = isNumber(data);
			if (!isANumber) {
				cout << S_NOT_A_NUMBER << endl;
			}
		} while (!isANumber);
		return stoi(data);		//stoi - string to int
	}//koniec give  me a number

















