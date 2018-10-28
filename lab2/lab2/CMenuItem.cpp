#include<string>
#include "CMenuItem.h"
#include<iostream>

using namespace std;



CMenuItem::~CMenuItem() {
	//cout << "usunieto: "<<s_name << endl;
	}


	string CMenuItem::toString() {
		return  s_name + " ( " + s_command + " )";
	}

	string CMenuItem::getCommand() {
		return s_command;
	}

	string CMenuItem::getName() {
		return s_name;
	}















