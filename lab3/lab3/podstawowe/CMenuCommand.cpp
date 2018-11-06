#include "CMenuCommand.h"
#include <string>


using namespace std;


CMenuCommand::CMenuCommand(string name, string command, CCommand *work, string info) {
	worker = work;
	s_name = name;
	s_command = command;
	s_description = info;
}

CMenuCommand::~CMenuCommand() {
	delete worker;
}


void CMenuCommand::run() {

	worker->runCommand();

}//koniec run


string CMenuCommand::getDescription() {
	return s_description;
}























