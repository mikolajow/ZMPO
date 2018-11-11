#include "CMenuCommand.h"
#include <string>
#include <iostream>


using namespace std;


CMenuCommand::CMenuCommand(string name, string command, string info, CCommand *work ) {
	worker = work;
	s_name = name;
	s_command = command;
	s_description = info;
}

CMenuCommand::CMenuCommand(string save)
{
	loadFromString(save);
}


CMenuCommand::~CMenuCommand() {
	delete worker;
}


void CMenuCommand::run() {

	if (worker) 
	{
		worker->runCommand();
	}
	else
	{
		cout << "komenda domyslna" << endl;
	}
}//koniec run


string CMenuCommand::getDescription() {
	return s_description;
}


string CMenuCommand::saveToString(string save)
{

	save = save + "['" + getName() + "','" + getCommand() + "','" + getDescription() + "']";
	return save;
}//koniec save to string


int CMenuCommand::loadFromString(string save)
{

	int posOfFirstUpper = save.find("'");
	if (posOfFirstUpper == -1)
	{
		cout << "nie znaleziono otwierajacego ' przy tworzeniu nazwy " << endl;
		return 0;
	}

	int posOfSecondUpper = save.find("'", posOfFirstUpper + 1);
	if (posOfSecondUpper == -1)
	{
		cout << "nie znaleziono zamykajacego ' przy tworzeniu nazwy " << endl;
		return 0;
	}
	int length = posOfSecondUpper - posOfFirstUpper - 1;
	string name = save.substr(posOfFirstUpper + 1, length);

	save.erase(0, posOfSecondUpper + 1);

	posOfFirstUpper = save.find("'");
	if (posOfFirstUpper == -1)
	{
		cout << "nie znaleziono otwierajacego ' przy tworzeniu komendy " << endl;
		return 0;
	}
	posOfSecondUpper = save.find("'", posOfFirstUpper + 1);
	if (posOfSecondUpper == -1)
	{
		cout << "nie znaleziono zamykajacego ' przy tworzeniu komendy " << endl;
		return 0;
	}
	length = posOfSecondUpper - posOfFirstUpper - 1;

	string command = save.substr(posOfFirstUpper + 1, length);

	save.erase(0, posOfSecondUpper + 1);	//wymazuje drugi ' i dodatkowo ;



	posOfFirstUpper = save.find("'");
	if (posOfFirstUpper == -1)
	{
		cout << "nie znaleziono otwierajacego ' przy tworzeniu komendy " << endl;
		return 0;
	}
	posOfSecondUpper = save.find("'", posOfFirstUpper + 1);
	if (posOfSecondUpper == -1)
	{
		cout << "nie znaleziono zamykajacego ' przy tworzeniu komendy " << endl;
		return 0;
	}
	length = posOfSecondUpper - posOfFirstUpper - 1;

	string description = save.substr(posOfFirstUpper + 1, length);

	save.erase(0, posOfSecondUpper + 1);

	s_name = name;
	s_command = command;
	s_description = description;

}

















