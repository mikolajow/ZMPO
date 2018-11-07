#include <string>
#include <iostream>
#include <vector>
#include "CMenu.h"
#include "CMenuItem.h"


CMenu::CMenu(string name, string command, vector <CMenuItem*> *list): list(list) {
	s_name = name;
	s_command = command;
	parent = NULL;
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
			string commandName = chosenCommand.substr(5, string::npos);

			chosenWorker = findWorker(commandName);

			CMenuCommand *chosenCommand;
			CMenu *chosenMenu;

			chosenCommand = dynamic_cast<CMenuCommand*>(chosenWorker);
			chosenMenu = dynamic_cast<CMenu*>(chosenWorker);

			if (chosenCommand)
			{
				cout << chosenCommand->getDescription() << endl;
			}//if chosen command
			else if (chosenMenu)
			{
				cout << "Wybrany objekt nie jest komenda tylko menu" << endl;
			}//else chosen command
			else
			{
				cout << "brak komendy" << endl;
			}//ani menu ani komenda - brak komendy
		}//else if help







		else if (chosenCommand.find("search ") == 0)
		{

			CMenu *main = findMain();

			main->search();

			cout << "glownym menu jest: " <<main->getName() << endl;
		}//if search

						








		else
		{
			chosenWorker = findWorkerWithFlag(chosenCommand, showMenuAgain);

			if (chosenWorker)
			{
				(*chosenWorker).run();
			}
			else if (!showMenuAgain)
			{
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
	CMenu *newMenu;
	newMenu = dynamic_cast<CMenu*>(newOne);
	if (newMenu)
	{
		newMenu->setParent(this);
	}

	(*list).push_back(newOne);
}

void CMenu::setParent(CMenu *par) {
	this->parent = par;
}

CMenu* CMenu::getParent() {
	return parent;
}

void CMenu::deleteOneMneuItem(int index) {
	(*list).erase((*list).begin() + index);
}


CMenuItem* CMenu::findWorkerWithFlag(string chosenCommand, bool &showMenuAgain) {
	CMenuItem *chosenWorker = NULL;
	for (unsigned int i = 0; i < list->size(); i++) {
		if (chosenCommand == (*(*list)[i]).getCommand()) {
			chosenWorker = &(*(*list)[i]);
			showMenuAgain = true;
		}//koniec if
	}//koniec for
	return chosenWorker;
}

CMenuItem* CMenu::findWorker(string chosenCommand) {
	CMenuItem *chosenWorker = NULL;
	for (unsigned int i = 0; i < list->size(); i++) {
		if (chosenCommand == (*(*list)[i]).getCommand()) {
			chosenWorker = &(*(*list)[i]);
		}//koniec if
	}//koniec for
	return chosenWorker;
}



CMenu* CMenu::findMain() {

	CMenu *main = parent;

	if (!(main == NULL))
	{
		while ((*main).getParent())
		{
			main = (*main).getParent();
		}
	}// if (main)
	else
	{
		main = this;
	}//jesli parent jest nullem na wejsciu to zmajdujemy sie w mainie

	return main;

}


void CMenu::search() {





}
















