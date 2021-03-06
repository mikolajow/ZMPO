#include <string>
#include <iostream>
#include <vector>
#include "CMenu.h"
#include "CMenuItem.h"
#include "Windows.h"
#include <limits>

CMenu::CMenu(string name, string command, vector <CMenuItem*> *list): list(list) {
	s_name = name;
	s_command = command;
	parent = NULL;
}//koniec konstruktora

CMenu::CMenu(string save, string original)
{
	int success = loadFromString(save, original);
	if (success == 0)
	{
		s_name = S_ERROR;
		s_command = S_ERROR;
		list = new vector<CMenuItem*>;
		save = "";
	}
}//konstruktor z save

CMenu::~CMenu() {
	//cout << "ununiento menu o nazwie: " << s_name << endl;
	for (unsigned int i = 0; i < (*list).size(); i++) {
		delete  (*list)[i];
	}

	delete list;
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
		if (i < list->size() - 1)
		{
			save = (*(*list)[i]).saveToString(save) + ",";
		}
		else
		{
			save = (*(*list)[i]).saveToString(save);
		}
	}//for wypisywanie dzieci 

	return save + ")";
}//koniec save to sttring

int CMenu::loadFromString(string save, string saveCoppy)
{
	if (save[0] != '(')
	{
		showError(save[0], "(", save, saveCoppy);
		return 0;
	}
	save.erase(0, 1);

	string name = loadNameOrComm(save ,saveCoppy);
	if (name == S_ERROR)
		return 0;

	if (save[0] != ',')
	{
		showError(save[0], ",", save, saveCoppy);
		return 0;
	}
	save.erase(0, 1);

	string command = loadNameOrComm(save, saveCoppy);
	if (command == S_ERROR)
		return 0;

	if (save[0] != ';')
	{
		showError(save[0], ";", save, saveCoppy);
		return 0;
	}
	save.erase(0, 1);



	////@@@@@@@@@@@@@ MODYFIKACJA ile dzieci
	//int noumberOfChilds = ((int)save[0]) - 48;
	//save.erase(0, 1);
	////@@@@@@@@@@@@@ MODYFIKACJA ile dzieci



	vector<CMenuItem*> *vec = new vector <CMenuItem*>;

	while (!save.empty())
	{

		if (save[0] == '(')
		{
			int numberOfOpen = 1;
			int numberOfClose = 0;

			int posOfCurrentOpen = 0;

			int posOfLastClose = save.find(")", 1);

			int posOfNextOpenBracket = save.find("(", posOfCurrentOpen + 1);


			if (posOfNextOpenBracket == -1)
				posOfNextOpenBracket = INT_MAX;

			do
			{

				if (posOfNextOpenBracket < posOfLastClose)
				{
					numberOfOpen++;

					posOfCurrentOpen = posOfNextOpenBracket;
					posOfNextOpenBracket = save.find("(", posOfCurrentOpen + 1);

					if (posOfNextOpenBracket == -1)
						posOfNextOpenBracket = INT_MAX;

					posOfLastClose = save.find(")", posOfLastClose + 1);
				}
				else 
				{
					numberOfClose++;
				}
				 
			} while (numberOfOpen != numberOfClose);
			
			string subSave = save.substr(0, posOfLastClose + 1);

			CMenu *child = new CMenu(subSave, saveCoppy);

			vec->push_back(child);

			save.erase(0, posOfLastClose + 1);

		}//if dziecko to menu

		else if (save[0] == '[')
		{
			int posOfSecondBracket = save.find("]", 1);
			string subSave = save.substr(0, posOfSecondBracket + 1);

			CMenuCommand *child = new CMenuCommand(subSave, saveCoppy);

			vec->push_back(child);

			save.erase(0, posOfSecondBracket + 1);

		}
		else if (save[0] == ',' || save[0] == ')' || save[0] == ' ' || save[0] == '	')
		{
			save.erase(0, 1);
		}
		else
		{
			showError(save[0], S_EXPECTED_OPEN_BRACKET, save, saveCoppy);
			return 0;
		}
	}//while save empty





	//	//@@@@@@@@@@@@@ MODYFIKACJA ile dzieci
	//int elemsInVec = vec->size();

	//if (noumberOfChilds == elemsInVec)
	//{
	//	cout << "tyle samo dzieci " << name << endl;
	//}
	//else
	//{
	//	cout << "inna liczba dzieci " << name << endl;
	//}
	////@@@@@@@@@@@@@ MODYFIKACJA ile dzieci





	s_name = name;
	s_command = command;
	list = vec;

	return 1;
}//koniec load from string

string CMenu::loadNameOrComm(string &save, string original)
{
	string saveCoppy = save;

	if (save[0] != '\'')
	{
		showError(save[0], "'", save, original);
		return S_ERROR;
	}

	int posOfFirstUpper = 0;

	int posOfSecondUpper = save.find("'", posOfFirstUpper + 1);

	if (posOfSecondUpper == -1 )
	{
		cout << S_NO_CLOSE_UPPER << endl;
		showError(save[0], "'", save, original);
		return S_ERROR;
	}

	int length = posOfSecondUpper - posOfFirstUpper - 1;
	string name = save.substr(posOfFirstUpper + 1, length);

	save.erase(0, posOfSecondUpper + 1);

	return name;
}

void CMenu::showError(char wrong, string expected, string save, string saveCoppy)
{
	cout << S_WRONG_CHAR;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	cout << wrong;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

	cout << S_PROGRAM_EXPECTED;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	cout << expected;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

	cout << endl;

	string firstPart = saveCoppy.substr(0, saveCoppy.find(save));

	cout << firstPart;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	cout << save[0];
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

	cout << saveCoppy.substr(firstPart.length() + 1, string::npos) << endl;

}





void CMenu::changePlaces(CMenu* first, CMenu* second)
{
	CMenu* firstParent = first->getParent();
	cout << firstParent->getName() << endl;
	CMenu* secondParent = second->getParent();
	vector <CMenuItem*>* firstVector = first->getVector();
	vector <CMenuItem*>* secondVector = second->getVector();
	firstParent->addNewItem(second);
	secondParent->getVector()->push_back(first);
	firstParent->getVector()->erase(firstParent->getVector()->begin());
	secondParent->getVector()->erase(secondParent->getVector()->begin());
	CMenu *currentMenu;
	vector<CMenuItem*> temp1;
	vector<CMenuItem*> temp2;

	// dodaje dzieci z first do temp1
	for (int i = 0; i < firstVector->size(); i++)
	{
		CMenuItem *current = (*firstVector)[i];
		currentMenu = dynamic_cast<CMenu*> (current);
		if (currentMenu)
		{
			temp1.push_back(currentMenu);
		}
	}//koniec for

	//dodaje dzieci z second do temp2
	for (int i = 0; i < secondVector->size(); i++)
	{
		CMenuItem *current = (*secondVector)[i];
		currentMenu = dynamic_cast<CMenu*> (current);
		if (currentMenu)
		{
			temp2.push_back(currentMenu);
		}
	}//koniec for

	for (int i = 0; i < temp2.size(); i++)
	{
		firstVector->push_back(temp2[i]);
	}

	for (int i = 0; i < temp1.size(); i++)
	{
		secondVector->push_back(temp1[i]);
	}
	firstVector->erase(firstVector->begin(), firstVector->begin() + temp1.size());
	secondVector->erase(secondVector->begin(), secondVector->begin() + temp2.size());
}//koniec change places

































