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

	CMenu(string save);

	~CMenu();

	void run(); // pobiera komende i jesli poprawna to wykonuje

	void addNewItem(CMenuItem *newOne);

	void deleteOneMneuItem(int index);

	vector <CMenuItem*>* getVector();

	//modyfikacja 2
	void printMenu(vector<CMenu*> *vec );
	//-----

	string saveToString(string save = "");

private:

	CMenu *parent;
	void setParent(CMenu *par);
	CMenu* getParent();

	vector <CMenuItem*> *list;


	int executeCommand();

	void exectuteHelp(string chosenCommand);

	void showMenu();

	CMenuItem* findWorkerWithFlag(string chosenCommand, bool &showMenuAgain);

	CMenuItem* findWorker(string chosenCommand);

	bool search(string command, bool found = false, string patch = "");

	CMenu* findMain();

	void loadFromString(string save);
};














































