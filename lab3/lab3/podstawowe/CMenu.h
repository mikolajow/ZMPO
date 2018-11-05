#pragma once

#include <string>
#include <vector>
#include "CMenuItem.h"


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

	vector <CMenuItem*> *list;

	int executeCommand();

	void showMenu();

};














































