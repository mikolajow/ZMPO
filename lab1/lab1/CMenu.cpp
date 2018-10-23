#include<string>
#include<vector>
#include <iostream>
#include"CTable.h"
#include"CMenu.h"

using namespace std;

CMenu::CMenu() {
	b_schould_i_run = true;
}

void CMenu::run() {
	
	while (b_schould_i_run) {
		showMenu();

		string s_choice; //zmienna wprowadzana przez uzytkownika
		cin >> s_choice;

		char choice = s_choice[0];

		if (list.size() == 0) {
			cout << S_NO_OBJECT_CREATE_NEW << endl;
			choice = C_MENU_CASE_1;
		}

		executeAction(choice);
	}//koniec while

}//koniec metody run


void CMenu::showMenu() {
	cout << S_MENU << endl;
	cout << S_MENU_0 << endl;
	cout << S_MENU_1 << endl;
	cout << S_MENU_2 << endl;
	cout << S_MENU_3 << endl;
	cout << S_MENU_4 << endl;
	cout << S_MENU_5 << endl;
	cout << S_MENU_6 << endl;
	cout << S_MENU_7 << endl;
	cout << S_MENU_8 << endl;
	cout << S_MENU_9 << endl;
}

void CMenu::executeAction(char choice) {
	switch (choice)
	{

	case C_MENU_CASE_0: {
		cout << S_GIVE_INDEX << endl;
		int index = giveMeAnIndex();
		CTable chosen = *list[index];
		test(chosen);
		//test2(list[index]);
		break;
	}

	case C_MENU_CASE_1: {
		cout << S_HOW_MANY_WANA_CREATE << endl;

		int howMany;
		howMany = giveMeANumber();

		makeCTables(howMany);

		break;
	}
	case C_MENU_CASE_2: {

		cout << S_GIVE_INDEX << endl;

		int tableIndex = giveMeAnIndex();

		cout << S_GIVE_NEW_TABLE_SIZE << endl;

		int newTableLength = giveMeANumber();

		bool success = list[tableIndex]->setTableSize(newTableLength);
		if (!success) {
			cout << S_WRONG_VALUE_NOTHING_HAPPENED << endl;
		}
		break;
	}
	case C_MENU_CASE_3: {
		cout << S_GIVE_INDEX_TO_DELETE << endl;
		int chosenIndex = giveMeAnIndex();
		deleteCTable(chosenIndex);
		break;
	}
	case C_MENU_CASE_4: {
		cout << S_SURE_WANA_DELETE_ALL << endl;
		int decision = giveMeANumber();
		if (decision == 1) {
			deleteAll();
		}//koniec if
		break;
	}
	case C_MENU_CASE_5: {
		cout << S_GIVE_INDEX_TO_NAME_CHANGE << endl;
		int chosen = giveMeAnIndex();
		cout << S_GIVE_NEW_NAME << endl;
		string newName;
		cin >> newName;
		changeName(chosen, newName);
		break;
	}
	case C_MENU_CASE_6: {
		cout << S_GIVE_INDEX_OF_OBJECT_U_WANT_KNOW << endl;
		int index = giveMeAnIndex();
		printCTable(index);
		break;
	}
	case C_MENU_CASE_7: {
		cout << S_GIVE_OJECT_INDEX_FOR_NEW_VALUE << endl;
		int cTableIndex = giveMeAnIndex();
		cout << S_GIVE_INDEX_OF_FIELD_IN_TABLE_TO_CHANGE << endl;
		int valueIndex = giveMeANumber();
		cout << S_GIVE_NEW_VALUE << endl;
		int newValue = giveMeANumber();
		bool success = changeOneValueOfCTable(cTableIndex, valueIndex, newValue);
		if(!success){
			cout << S_WRONG_INDEX << endl;
		}
		break;
	}
	case C_MENU_CASE_9: {
		b_schould_i_run = false;
		break;
	}
	case C_MENU_CASE_8: {
		cout << S_GIVE_INDEX_TO_CLONE << endl;
		int index = giveMeAnIndex();
		cloneAndAdd(index);
	}
	default: {
		system("cls");
		cout << S_WRONG_VALUE << endl;
		run();
		break;
	}//koniec default
	}//koniec switch
}//koniec metody

int CMenu::giveMeANumber() {

	string data;

	bool isANumber;

	do
	{
		cin >> data;
		isANumber = isNumber(data);
		if (!isANumber) {
			cout << S_NOT_A_NUMBER << endl;
		}
	} while (!isANumber);
	return stoi(data);		//stoi - string to int
}


bool CMenu::isNumber(string data) {
	int signCounter = 0;
	for (int i = 0; i < data.length(); i++) {
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


CMenu::~CMenu() {
	deleteAll();
}

void CMenu::makeCTables(int howMany) {
	for (int i = 0; i < howMany; i++) {
		list.push_back(new CTable());
	}
}

void CMenu::deleteCTable(int index) {
	CTable *chosen = list[index];
	list.erase(list.begin() + index);
	delete chosen;
}

void CMenu::deleteAll() {
	for ( unsigned int i = 0; i < list.size(); i++) {
		delete list[i];
	}
	list.clear();
}

void CMenu::changeName(int index, string newName) {
	list[index]->setName(newName);
}

void CMenu::cloneAndAdd(int index) {
	CTable *clone = list[index]->clone();
	list.push_back(clone);
}

void CMenu::printCTable(int index) {
	cout << list[index]->toString() << endl;
}

int CMenu::howBigIsYoursTable(int index) {
	return list[index]->getSize();
}

bool CMenu::changeOneValueOfCTable(int cTableIndex, int valueIndex, int newValue) {

	bool success = list[cTableIndex]->setValueOnIndex(valueIndex, newValue);
	return success;
}

int CMenu::giveMeAnIndex() {
	int index = giveMeANumber();

	while (index > list.size() || index < 0) {
		cout << S_WRONG_INDEX << endl;
		index = giveMeANumber();
	}
	return index;
}




void CMenu::test(CTable chosen) {
	chosen.setTableSize(1);
}

//void CMenu::test2(CTable *chosen) {
//	cout << "test2 :" << endl;
//	chosen->setTableSize(1);
//}
















