#pragma once

#include <string>
#include "CMenuItem.h"
#include "CCommand.h"

using namespace std;

class CMenuCommand : public CMenuItem {

public:

	CMenuCommand(string name, string command, CCommand *worker, string info);

	~CMenuCommand();

	void run();

	string getDescription();

private:

	CCommand *worker;

	string s_description;

};











































