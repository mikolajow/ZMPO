#include "CMenuCommand.h"
#include <string>
#include <iostream>
#include "Windows.h"

using namespace std;


CMenuCommand::CMenuCommand(string name, string command, string info, CCommand *work ) {
	worker = work;
	s_name = name;
	s_command = command;
	s_description = info;
}

CMenuCommand::CMenuCommand(string save, string original)
{
	int success = loadFromString(save, original);
	if ( success== 0)
	{
		s_name = "ERROR";
		s_command = "ERROR";
		s_description = "ERROR";
	 }
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

int CMenuCommand::loadFromString(string save, string original)
{
	string saveCoppy = save;

	int posOfFirstUpper = save.find("'");
	if (posOfFirstUpper == -1)
	{
		showError(saveCoppy, original);
		return 0;
	}

	int posOfSecondUpper = save.find("'", posOfFirstUpper + 1);
	if (posOfSecondUpper == -1)
	{
		showError(saveCoppy, original);
		return 0;
	}
	int length = posOfSecondUpper - posOfFirstUpper - 1;
	string name = save.substr(posOfFirstUpper + 1, length);

	save.erase(0, posOfSecondUpper + 1);

	posOfFirstUpper = save.find("'");
	if (posOfFirstUpper == -1)
	{
		showError(saveCoppy, original);
		return 0;
	}
	posOfSecondUpper = save.find("'", posOfFirstUpper + 1);
	if (posOfSecondUpper == -1)
	{
		showError(saveCoppy, original);
		return 0;
	}
	length = posOfSecondUpper - posOfFirstUpper - 1;

	string command = save.substr(posOfFirstUpper + 1, length);

	save.erase(0, posOfSecondUpper + 1);	//wymazuje drugi ' i dodatkowo ;

	posOfFirstUpper = save.find("'");
	if (posOfFirstUpper == -1)
	{
		showError(saveCoppy, original);
		return 0;
	}
	posOfSecondUpper = save.find("'", posOfFirstUpper + 1);

	if (posOfSecondUpper == -1)
	{
		showError(saveCoppy, original);
		return 0;
	}
	length = posOfSecondUpper - posOfFirstUpper - 1;

	string description = save.substr(posOfFirstUpper + 1, length);

	save.erase(0, posOfSecondUpper + 1);

	s_name = name;
	s_command = command;
	s_description = description;

	return 1;
}




void CMenuCommand::showError(string save, string saveCoppy)
{
	cout << "blednie zapisana komenda, program oczekiwal ' " << endl;

	string firstPart = saveCoppy.substr(0, saveCoppy.find(save));

	cout << firstPart;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	cout << save;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

	cout << saveCoppy.substr(firstPart.length() + save.length() + 1, string::npos) << endl;
}











