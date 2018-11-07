#pragma once

#include <string>
#include <vector>
#include "CMenuItem.h"
#include "CMenuCommand.h"


#define S_BACK "back"
#define S_WRONG_COMMAND "Zla komenda wprowadz ponownie"
#define S_YOU_ARE_IN "Jestes w " 
#define S_MENU_PREFIX  "  => "
#define S_COMMAND_PREFIX "    -- "

using namespace std;

class CMenu : public CMenuItem {
public:

	CMenu(string name, string command, vector <CMenuItem*> *list);

	~CMenu();

	void run(); // pobiera komende i jesli poprawna to wykonuje

	void addNewItem(CMenuItem *newOne);

	void deleteOneMneuItem(int index);


private:

	CMenu *parent;
	void setParent(CMenu *par);
	CMenu* getParent();

	vector <CMenuItem*> *list;


	int executeCommand();

	void showMenu();

	CMenuItem* findWorkerWithFlag(string chosenCommand, bool &showMenuAgain);

	CMenuItem* findWorker(string chosenCommand);

	void search();

	CMenu* findMain();
};














































