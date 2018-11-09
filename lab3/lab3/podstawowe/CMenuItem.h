#pragma once

#include<string>

using namespace std;

class CMenuItem {

public:

	virtual ~CMenuItem();

	virtual void run() = 0;

	virtual string saveToString(string save = "") = 0;

	string toString();

	string getCommand();

	string getName();

protected:
	string s_name;
	string s_command;

};

























