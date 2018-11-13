#pragma once

#include <string>
#include "CMenuItem.h"
#include "CCommand.h"

using namespace std;

class CMenuCommand : public CMenuItem {

public:

	CMenuCommand(string name, string command,  string info, CCommand *worker = NULL);

	CMenuCommand(string save, string original);

	~CMenuCommand();

	void run();

	string getDescription();

	string saveToString(string save = "");

private:

	CCommand *worker;

	string s_description;

	int loadFromString(string save, string original);

	void showError(string save, string saveCoppy);
};











































