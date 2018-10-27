#include <string>
#include <iostream>
#include <vector>
#include "CMenu.h"
#include "CMenuItem.h"


CMenu::CMenu(string name, string command, vector <CMenuItem*> *list): list(list) {
	s_name = name;
	s_command = command;
}//koniec konstruktora

CMenu::~CMenu() = default;


void CMenu::run() {

	showMenu();

	executeCommand();

}//koniec run


int CMenu::executeCommand() {

	string chosenCommand;

	while (true)
	{
		bool flag = false;		//jak flaga wynosi true to znaczy ze weszlismy w podmenu, jak z niego wyjdziemy to wyswietl tresc aktualnego menu ponownie
		CMenuItem *chosenWorker = NULL;
		getline(cin, chosenCommand);


		if (chosenCommand == "back") {
			return 0;
		}

		for (unsigned int i = 0; i < list->size(); i++) {
			if (chosenCommand == (*(*list)[i]).getCommand()) {
				chosenWorker = &(*(*list)[i]);
				flag = true;
			}//koniec if
		}//koniec for

		if (chosenWorker) {
			(*chosenWorker).run();
		}
		else if (!flag){
			cout << "Zla komenda wprowadz ponownie" << endl;
		}//koniec else

		if (flag) {
			showMenu();
			flag = false;
		}


	}//koniec while
}//koniec execute command


void CMenu::showMenu() {
	cout << endl;
	cout << "Jestes w " << getName() << endl;

	for (unsigned int i = 0; i < list->size(); i++) {
		cout << "  -- " << (*(*list)[i]).toString() << endl;
	}
}//koniec show menu






























