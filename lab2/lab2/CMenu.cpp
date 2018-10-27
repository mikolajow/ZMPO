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


		if (chosenCommand == S_BACK ) {
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
			cout << S_WRONG_COMMAND << endl;
		}//koniec else

		if (flag) {
			showMenu();
			flag = false;
		}


	}//koniec while
}//koniec execute command


void CMenu::showMenu() {
	cout << endl;
	cout << S_YOU_ARE_IN << getName() << endl;

	for (unsigned int i = 0; i < list->size(); i++) {
		CMenuItem *current = (*list)[i];

		if (typeid(*current).name() == typeid(CMenu).name() ) {
			cout << S_MENU_PREFIX << (*current).toString() << endl;
		}//koniec if
		else {
			cout << S_COMMAND_PREFIX << (*current).toString() << endl;
		}//koniec else

	}//koniec for
}//koniec show menu






























