#pragma once

#include <string>
#include "CMenuItem.h"
#include "CCommand.h"

using namespace std;

class CMenuCommand : public CMenuItem {

public:

	CMenuCommand(string name, string command, CCommand *worker);

	~CMenuCommand();

	void run();


private:

	CCommand *worker;

};











































