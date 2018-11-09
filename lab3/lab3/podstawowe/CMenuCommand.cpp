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




















