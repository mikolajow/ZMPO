#include <string>
#include <iostream>
#include <vector>
#include "CMenu.h"
#include "CMenuItem.h"


CMenu::CMenu(string name, string command, vector <CMenuItem*> *list): list(list) {
	s_name = name;
	s_command = command;
}//koniec konstruktora

CMenu::~CMenu() {
	//cout << "ununiento menu o nazwie: " << s_name << endl;
	for (unsigned int i = 0; i < (*list).size(); i++) {
		delete  (*list)[i];
	}
}


void CMenu::run() {

	showMenu();

	executeCommand();

}//koniec run


int CMenu::executeCommand() {

	string chosenCommand;

	while (true)
	{
		bool showMenuAgain = false;		//jak flaga wynosi true to znaczy ze weszlismy w podmenu, jak z niego wyjdziemy to wyswietl tresc aktualnego menu ponownie
		CMenuItem *chosenWorker = NULL;
		getline(cin, chosenCommand);




		if (chosenCommand == S_BACK ) 
		{
			return 0;
		}// if back










		else if (chosenCommand.find("help ") == 0)
		{

			cout << "pomyslne help" << endl;
		}//if help
		else if (chosenCommand.find("search ") == 0)
		{

			cout << "pomyslne search" << endl;
		}//if search










		else
		{
			chosenWorker = findWorker(chosenCommand, showMenuAgain);

			if (chosenWorker) {
				(*chosenWorker).run();
			}
			else if (!showMenuAgain) {
				cout << S_WRONG_COMMAND << endl;
			}//koniec else

			if (showMenuAgain)
			{
				showMenu();
				showMenuAgain = false;
			}//if show menu
		}//else - default


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


void CMenu::addNewItem(CMenuItem *newOne) {
	(*list).push_back(newOne);
}

void CMenu::deleteOneMneuItem(int index) {
	(*list).erase((*list).begin() + index);
}


CMenuItem* CMenu::findWorker(string chosenCommand, bool &showMenuAgain) {
	CMenuItem *chosenWorker = NULL;
	for (unsigned int i = 0; i < list->size(); i++) {
		if (chosenCommand == (*(*list)[i]).getCommand()) {
			chosenWorker = &(*(*list)[i]);
			showMenuAgain = true;
		}//koniec if
	}//koniec for
	return chosenWorker;
}






















