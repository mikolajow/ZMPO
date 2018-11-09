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

CMenu::CMenu(string save)
{
	loadFromString(save);
}//konstruktor z save

CMenu::~CMenu() {
	//cout << "ununiento menu o nazwie: " << s_name << endl;
	for (unsigned int i = 0; i < (*list).size(); i++) {
		delete  (*list)[i];
		delete list;
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

			exectuteHelp(chosenCommand);

		}//else if help

		else if (chosenCommand.find("search ") == 0)
		{
			CMenu *main = findMain();

			chosenCommand = chosenCommand.substr(7, string::npos);

			bool found = main->search(chosenCommand);

			if (!found)
			{
				cout << "brak komendy " << endl;
			}//if (!found)
		}//else if search

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

void CMenu::exectuteHelp(string givenCommand) {

	string commandName = givenCommand.substr(5, string::npos);

	CMenuItem *chosenWorker = findWorker(commandName);

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
}//koniec execute help

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

bool CMenu::search(string command, bool found, string patch) {

	CMenuItem *current;
	CMenu *currentIsMenu;

	for (unsigned int i = 0; i < list->size(); i++)
	{
		current = &(*(*list)[i]);
		currentIsMenu = dynamic_cast<CMenu*>(current);
		if (currentIsMenu)
		{
			found = currentIsMenu->search(command, found, patch + this->getName() + " -> ");
		}//if (isMenu)
		else
		{
			if (current->getCommand() == command)
			{
				found = true;
				cout << patch << this->getName() << " -> " << command << endl;
			}
		}// else -> if (isMenu)
	}//for (unsigned int i = 0; i < list->size(); i++)

	return found;
}//koniec search


vector <CMenuItem*>* CMenu::getVector()
{
	return list;
}


//modyfikacja 2
void CMenu::printMenu(vector<CMenu*> *vec)
{
	CMenu *first = (*vec)[0];

	if (first->getParent() == NULL)
	{
		cout << first->getName() << endl;
	}

	vector<CMenu*> leftMenus;

		for (unsigned int i = 0; i < vec->size(); i++)
		{
			vector<CMenuItem*> *menusVec = (*((*vec)[i])).getVector();

			for (unsigned int j = 0; j < menusVec->size(); j++)
			{
				CMenuItem *currentMenuItem;
				CMenu *currentMenu;

				currentMenuItem = (*menusVec)[j];
				currentMenu = dynamic_cast<CMenu*>(currentMenuItem);

				if (currentMenu)
				{
					leftMenus.push_back(currentMenu);
				}//if (currentMenu)


				cout << currentMenuItem->getName() << " -- ";
			}

		}//for (unsigned int = 0; i < list->size(); i++ )  for do wypisywania pierwszego rzedu

		cout << endl;
		

		if (!leftMenus.empty())
		{
			printMenu(&leftMenus);
		}

}//koniec print menu
//--------2 


string CMenu::saveToString(string save)
{

	save = save + "(" + "'" + getName() + "'" + "," + "'" + getCommand() + "';";

	for (unsigned int i = 0; i < list->size(); i++)
	{
		save = (*(*list)[i]).saveToString(save) + ",";
	}//for wypisywanie dzieci 

	return save + ")";
}//koniec save to sttring


void CMenu::loadFromString(string save)
{

	string saveCoppy = save;

	int posOfFirstUpper = save.find("'");
	int posOfSecondUpper = save.find("'", posOfFirstUpper + 1);
	int length = posOfSecondUpper - posOfFirstUpper - 1;
	string name = save.substr(posOfFirstUpper + 1, length);

	cout << "menu name: " << name ;

	save.erase(0, posOfSecondUpper + 1);

	posOfFirstUpper = save.find("'");
	posOfSecondUpper = save.find("'", posOfFirstUpper + 1);
	length = posOfSecondUpper - posOfFirstUpper - 1;

	string command = save.substr(posOfFirstUpper + 1, length);
	
	cout << "   menu command: " <<  command << endl;

	save.erase(0, posOfSecondUpper + 2);	//wymazuje drugi ' i dodatkowo ;

	vector<CMenuItem*> *vec = new vector <CMenuItem*>;

	while (!save.empty())
	{






		if (save[0] == '(')
		{



			int posOfNextOpenBracket = save.find("(", 1);

			int posOfCloseBracket = save.find(")", 1);		//jak menu ma w sobie menu to znajde pierwszy zamykajacy wiec lipa :(

			do
			{

			} while (posOfCloseBracket > posOfNextOpenBracket);



			string subSave = save.substr(0, posOfCloseBracket + 1);
			
			CMenu *child = new CMenu(subSave);

			vec->push_back(child);

			save.erase(0, posOfCloseBracket + 1);

		}//if dziecko to menu







		else if (save[0] == '[')
		{
			int posOfSecondBracket = save.find("]", 1);
			string subSave = save.substr(0, posOfSecondBracket + 1);

			CMenuCommand *child = new CMenuCommand(subSave);

			vec->push_back(child);

			save.erase(0, posOfSecondBracket + 1);

		}
		else if (save[0] == ',')
		{
			save.erase(0, 1);
		}
		else
		{
			cout << "zly string: " << save[0] << endl;
			s_name = "blad stringa";
			s_command = "blad stringa";
			list = NULL;
			save = "";
		}
	}//while save empty


	s_name = name;
	s_command = command;
	list = vec;

}//koniec load from string





























