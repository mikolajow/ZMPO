#include <iostream>
#include "CTable.h"

using namespace std;



CTable::CTable() {
	makeDefault();
}//koniec domyœlnego

CTable::CTable(string name, int tableLenght) {
	if (tableLenght >= 0 && tableLenght < I_MAX_INT) {
		i_size = tableLenght;
		s_name = name;
		pi_table = new int[i_size];
		fillWithZero();
		cout << S_PARAMETR << s_name << endl;
	}
	else
	{
		//MOGE TU COUT ?
		//cout << "z³e wartoœci, utworzono domyœlnie" << endl;
		makeDefault();
	}
}//koniec konstruktora z parametrem

CTable::CTable(CTable &original) {
	i_size = original.getSize();
	s_name = original.getName() + S_COPY;
	pi_table = new int[i_size];
	//wype³niam now¹ tabele
	for (int i = 0; i < i_size; i++) {
		pi_table[i] = original.getTable()[i];
	}//koniec for
	cout << S_KOPJUJ << s_name << endl;
}//koniec kopjuj¹cego konstruktora

CTable::~CTable() {
	delete[] pi_table;
	cout << S_USOWAM << s_name << endl;
}//koniec destruktora


bool CTable::setValueOnIndex(int index, int newValue) {
	if (index >= 0 && index < i_size && newValue < I_MAX_INT && newValue > I_MIN_INT) {
		pi_table[index] = newValue;
		return true;
	}
	else
	{
		return false;
	}
}//koniec setValueOnIndex

// do zmiany - wywalic cout
int CTable::getValueFromIndex(int index , bool *succes) {
	if (index >= 0 && index < i_size) {
		*succes = true;
		return pi_table[index];
	}
	else
	{
		*succes = false;

		//	CZY MOGE W TEJ METODZIE WYSWIETLIC COUT`EM?

		//cout << "podano zly index, domyslnie zwrocono 0 " << endl;

		return 0;
	}
}//koniec getValueFromIndex


bool CTable::setTableSize(int newSize) {
	if (newSize < 0 || newSize < i_size) {
		return false;
	}
	else if (newSize == i_size) { return true; } //jak sa równe to nie trzeba nic zmieniac i jest ok

	else {
		int *newPiTable = new int[newSize];
		for (int i = 0; i < newSize; i++) {
			newPiTable[i] = 0;
		}//koniec for


		for (int i = 0; i < i_size; i++) {
			newPiTable[i] = pi_table[i];
		}//koniec for

		i_size = newSize;
		delete[] pi_table;	//usówam star¹ tablice
		pi_table = newPiTable;
		return true;


	}//koniec else
}//koniec metody


void CTable::coppyTableFromObjectCTable(CTable &original) {

	delete[] pi_table;
	i_size = original.getSize();
	pi_table = new int[i_size];
	for (int i = 0; i < i_size; i++) {
		pi_table[i] = (original.getTable())[i];
	}//koniec for
}

void CTable::setName(string newName) {
	s_name = newName;
}

//jak wykorzystac konstruktor kopiuj¹cy??? CTable *clone = new CTable(&this);
CTable *CTable::clone() {
	CTable *clone = new CTable();
	clone->setName(s_name + S_CLONE);
	clone->setTableSize(i_size);
	clone->setTableSize(i_size);
	for (int i = 0; i < i_size; i++) {
		(clone->getTable())[i] = pi_table[i];
	}
	return clone;
}


string CTable::toString() {
	string info = s_name + S_LEN + to_string(i_size) + S_VALUES;
	for (int i = 0; i < i_size; i++) {
		info = info + to_string(pi_table[i]) + C_COMA;
	}
	return info;
}

void CTable::fillWithZero() {
	for (int i = 0; i < i_size; i++) {
		pi_table[i] = 0;
	}//koniec for
}//koniec metody

int* CTable::getTable() {
	return pi_table;
}

int CTable::getSize() {
	return i_size;
}

string CTable::getName() {
	return s_name;
}

void CTable::makeDefault() {
	s_name = S_DEFAULT;
	i_size = 10;
	pi_table = new int[i_size];
	fillWithZero();
	cout << S_BEZP << s_name << endl;
}

























