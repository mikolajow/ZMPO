#pragma once

#include <string>
#include "CMenuItem.h"
#include "CCommand.h"

using namespace std;

class CMenuCommand : public CMenuItem {

public:

	CMenuCommand(string name, string command,  string info, CCommand *worker = NULL);

	~CMenuCommand();

	void run();

	string getDescription();

	string saveToString(string save = "");

private:

	CCommand *worker;

	string s_description;

};











































