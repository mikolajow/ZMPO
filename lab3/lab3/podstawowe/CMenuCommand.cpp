#include "CMenuCommand.h"
#include <string>


using namespace std;


CMenuCommand::CMenuCommand(string name, string command, CCommand *work) {
	worker = work;
	s_name = name;
	s_command = command;
}

CMenuCommand::~CMenuCommand() {
	delete worker;
}


void CMenuCommand::run() {

	worker->runCommand();

}//koniec run


























