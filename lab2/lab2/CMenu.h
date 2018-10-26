#pragma once

#include <string>
#include <vector>
#include "CMenuItem.h"

using namespace std;

class CMenu : public CMenuItem {
public:

	CMenu(string name, string command, vector <CMenuItem*> *list);

	~CMenu();

	void run(); // pobiera komende i jesli poprawna to wykonuje



private:

	vector <CMenuItem*> *list;


	int executeCommand();

	void showMenu();

};














































