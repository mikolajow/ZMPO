#include<string>
#include "CMenuItem.h"


using namespace std;



	CMenuItem::~CMenuItem() = default;


	string CMenuItem::toString() {
		return  s_name + " ( " + s_command + " )";
	}

	string CMenuItem::getCommand() {
		return s_command;
	}

	string CMenuItem::getName() {
		return s_name;
	}















