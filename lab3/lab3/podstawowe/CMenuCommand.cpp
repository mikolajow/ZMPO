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


void CMenuCommand::loadFromString(string save)
{

	string saveCoppy = save;

	int posOfFirstUpper = save.find("'");
	int posOfSecondUpper = save.find("'", posOfFirstUpper + 1);
	int length = posOfSecondUpper - posOfFirstUpper - 1;
	string name = save.substr(posOfFirstUpper + 1, length);


	save.erase(0, posOfSecondUpper + 1);

	posOfFirstUpper = save.find("'");
	posOfSecondUpper = save.find("'", posOfFirstUpper + 1);
	length = posOfSecondUpper - posOfFirstUpper - 1;

	string command = save.substr(posOfFirstUpper + 1, length);

	save.erase(0, posOfSecondUpper + 1);

	posOfFirstUpper = save.find("'");
	posOfSecondUpper = save.find("'", posOfFirstUpper + 1);
	length = posOfSecondUpper - posOfFirstUpper - 1;

	string description = save.substr(posOfFirstUpper + 1, length);

	save.erase(0, posOfSecondUpper + 1);

	cout << "command name: " << name ;
	cout << "  command command: " << command ;
	cout << "  command description: " << description.substr(0,10) << endl;

	s_name = name;
	s_command = command;
	s_description = description;

}

















