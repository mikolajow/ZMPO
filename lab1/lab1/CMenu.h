#pragma once
#include<string>
#include<vector>
#include"CTable.h"

	using namespace std;

#define S_MENU "---------Menu----------"
#define S_MENU_0 "0 - metoda statyczna (modyfikacja)"
#define S_MENU_1 "1 - utworz objekty CTable"
#define S_MENU_2 "2 - zmien dlugosc tablicy dla okreslonego objektu"
#define S_MENU_3 "3 - skasuj wybrany element"
#define S_MENU_4 "4 - skasuj wszystkie elementy"
#define S_MENU_5 "5 - nadaj lub zmien nazwe wybranego objektu"
#define S_MENU_6 "6 - wyswietl informacje o wybranym objekcie"
#define S_MENU_7 "7 - wybierz objekt i zmien wartosc wybranej komorki"
#define S_MENU_8 "8 - klonuj i dodaj do puli"
#define S_MENU_9 "9 - zakoncz dzialanie programu"
#define S_NO_OBJECT_CREATE_NEW  "nie ma zadnych objektow, mozesz jedynie stworzyc nowe"

#define C_MENU_CASE_0 '0'
#define C_MENU_CASE_1 '1'
#define C_MENU_CASE_2 '2'
#define C_MENU_CASE_3 '3'
#define C_MENU_CASE_4 '4'
#define C_MENU_CASE_5 '5'
#define C_MENU_CASE_6 '6'
#define C_MENU_CASE_7 '7'
#define C_MENU_CASE_8 '8'
#define C_MENU_CASE_9 '9'

#define S_WRONG_INDEX "Podano zly index, nie ma tylu objektow lub podana wartosc jest ujemna, wprowadz ja jeszcze raz"
#define S_NOT_A_NUMBER "Podana wartosc nie jest prawidlowa liczba, wprowadz wartosc jeszcze raz"
#define S_WRONG_VALUE "podano zla wartosc, sprobuj ponownie"
#define S_GIVE_INDEX_TO_CLONE  "Podaj index objektu do sklonowania"
#define S_GIVE_OJECT_INDEX_FOR_NEW_VALUE "Podaj index objektu ktoremu chcesz zmienic wartosc w komorce"
#define S_GIVE_INDEX_OF_FIELD_IN_TABLE_TO_CHANGE "Podaj index komorki ktora chcesz zmienic"
#define S_GIVE_NEW_VALUE "Podaj nowa wartosc"
#define S_GIVE_INDEX_OF_OBJECT_U_WANT_KNOW  "wprowadz index objektu o ktorym chcesz dostac informacje"
#define S_GIVE_NEW_NAME "Wprowadz nowa nazwe dla wybranego elementu"
#define S_GIVE_INDEX_TO_NAME_CHANGE "Wprowadz index elementu ktoremu chcesz zmienic nazwe"
#define S_SURE_WANA_DELETE_ALL  "Na pewno chcesz skasowac wszystkie elementy? wprowadz 1 jesli tak"
#define S_GIVE_INDEX_TO_DELETE "Podaj index elementu do skasowania"
#define S_WRONG_VALUE_NOTHING_HAPPENED "Podano zla wartosc operacja nie zostala przeprowadzona"
#define S_GIVE_INDEX  "Podaj index objektu"
#define S_GIVE_NEW_TABLE_SIZE "Podaj nowa dlugosc tablicy"
#define S_HOW_MANY_WANA_CREATE "ile objektow chcesz stworzyc?" 

#define I_ASCII_ZERO 48
#define I_ASCII_NINE 57
#define I_ASCII_PLUS 43
#define I_ASCII_MINUS 45



class CMenu {

private:
	vector <CTable *> list;
	bool b_schould_i_run;
public:
	CMenu();

	void run();

	~CMenu();//

	void makeCTables(int howMany);//
	void deleteCTable(int index);//
	void deleteAll();//
	void changeName(int index, string newName);//
	void cloneAndAdd(int index);//
	void printCTable(int index);//

	int howBigIsYoursTable(int index);//

	//zwraca true jak index wartosci bedzie poprawny
	bool changeOneValueOfCTable(int cTableIndex, int valueIndex, int newValue);
	
	//dodatkowe metody
	void showMenu();
	void executeAction(char choice);
	bool isNumber(string data);
	int giveMeANumber();
	int giveMeAnIndex();


	//modyfikacja
	void test(CTable chosen);
	void test2(CTable *chosen);

};






































