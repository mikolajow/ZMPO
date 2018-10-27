#pragma once
#include <string>
	using namespace std;

#define S_PARAMETR "parametr: "
#define S_COPY "_copy"
#define S_KOPJUJ "kopiuj: "
#define S_USOWAM "usuwam "
#define S_CLONE "_clone"
#define S_LEN " len: " 
#define S_VALUES " values: "
#define C_COMA ","
#define S_DEFAULT "default"
#define S_BEZP "bezp: "



class CTable {
	const int I_MAX_INT = 2147483647;
	const int I_MIN_INT = -2147483647;

public:
	//konstruktory
	CTable();//
	CTable(string name, int tableLength);//
	CTable(CTable &original);//

	//destruktor
	~CTable();//

	//wymagane metody
	bool setValueOnIndex(int index, int newValue);//
	int getValueFromIndex(int index , bool *succes);	//jesli podamy z³y index to succes = false i domyœlnie zwrócone zostanie 0
	bool setTableSize(int newSize);		// zwraca false jak index < 0 lub gdy index przekracza inta
	void coppyTableFromObjectCTable(CTable &original);	//
	void setName(string newName);//
	CTable* clone();	//klonuje objekt i zwraca referencje na nowy
	string toString();//

	//dodatkowe metody
	void fillWithZero();//
	int* getTable();//
	string getName();//
	int getSize();//
	void makeDefault();//


private:
	string s_name;
	int* pi_table;
	int i_size;
};












