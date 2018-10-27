
#include "CConfig.h"
#include <typeinfo>


void CConfig::config() {


	CTableCollector *collector = new CTableCollector();

	CClearScreen *clearScreen = new CClearScreen();
	CMenuCommand *clearScreenmenu = new CMenuCommand("wyczysc ekran", "cls", clearScreen);

	// MENU USUWANIA	--------------------------------------------------------------
	// @ TWORZENIE METOD

	CDeleteChosenElement *deleteChosenElement = new CDeleteChosenElement(collector);
	CMenuCommand *deleteChosenElementMenu = new CMenuCommand("usun wybrane ctable", "usun", deleteChosenElement);

	CDeleteAll *deleteAll = new CDeleteAll(collector);
	CMenuCommand *deleteAllMenu = new CMenuCommand("usun wszystkie", "usun wszy", deleteAll);




	vector<CMenuItem*> vectorDeleteMenu;

	vectorDeleteMenu.push_back(deleteChosenElementMenu);
	vectorDeleteMenu.push_back(deleteAllMenu);
	vectorDeleteMenu.push_back(clearScreenmenu);

	CMenu *deleteMenu = new CMenu("menu usuwania", "usuwanie", &vectorDeleteMenu);




	// MENU ZMIAN ---------------------------------------------------------------
	// @ TWORZENIE METOD

	CChangeTableSize *changeTableSize = new CChangeTableSize(collector);
	CMenuCommand *changeTableSizeMenu = new CMenuCommand("zmien dlugosc tablicy", "zmien dl", changeTableSize);

	CChangeName *changeName = new CChangeName(collector);
	CMenuCommand *changeNameMenu = new CMenuCommand("zmien nazwe wybranego ctable", "zmien nazwe", changeName);

	CChangeOneField *changeField = new CChangeOneField(collector);
	CMenuCommand *changeFieldMenu = new CMenuCommand("zmien jedna wartosc w tabeli", "zmien wartosc", changeField);




	vector<CMenuItem*> vectorChangeMenu;

	vectorChangeMenu.push_back(changeTableSizeMenu);
	vectorChangeMenu.push_back(changeNameMenu);
	vectorChangeMenu.push_back(changeFieldMenu);
	vectorChangeMenu.push_back(clearScreenmenu);

	CMenu *changeMenu = new CMenu("menu zmian", "zmiana", &vectorChangeMenu);



	// MAIN MENU	------------------------------------------------------------------
	// @ TWORZENIE METOD

	CMakeNewCTables *makeNewCtables = new CMakeNewCTables(collector);
	CMenuCommand *makeNewCtablesMenu = new CMenuCommand("dodaj nowe ctables", "dodaj", makeNewCtables);

	CGiveInfo *giveInfo = new CGiveInfo(collector);
	CMenuCommand *giveInfoMenu = new CMenuCommand("wyswietl informacje o objekcie", "info", giveInfo);

	CCloneElem *clone = new CCloneElem(collector);
	CMenuCommand *cloneMenu = new CMenuCommand("klonuj i dodaj element", "klonuj", clone);





	vector<CMenuItem*> vectorMainMenu;

	vectorMainMenu.push_back(deleteMenu);
	vectorMainMenu.push_back(changeMenu);

	vectorMainMenu.push_back(makeNewCtablesMenu);
	vectorMainMenu.push_back(giveInfoMenu);
	vectorMainMenu.push_back(cloneMenu);
	vectorMainMenu.push_back(clearScreenmenu);




	CMenu *mainMenu = new CMenu("Main Menu", "main", &vectorMainMenu);


	mainMenu->run();


}//koniec metody config




























