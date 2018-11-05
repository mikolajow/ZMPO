#include "CConfig.h"
#include <typeinfo>


void CConfig::config() {


	CTableCollector *collector = new CTableCollector();



	// MENU USUWANIA	--------------------------------------------------------------
	// @ TWORZENIE METOD

	CDeleteChosenElement *deleteChosenElement = new CDeleteChosenElement(collector);
	CMenuCommand *deleteChosenElementMenu = new CMenuCommand("usun wybrane ctable", "usun", deleteChosenElement);

	CDeleteAll *deleteAll = new CDeleteAll(collector);
	CMenuCommand *deleteAllMenu = new CMenuCommand("usun wszystkie", "usun wszy", deleteAll);




	vector<CMenuItem*> vectorDeleteMenu;

	CMenu *deleteMenu = new CMenu("menu usuwania", "usuwanie", &vectorDeleteMenu);

	deleteMenu->addNewItem(deleteChosenElementMenu);
	deleteMenu->addNewItem(deleteAllMenu);
	deleteMenu->addNewItem(makeClearScreenCommand());


	// MENU ZMIAN ---------------------------------------------------------------
	// @ TWORZENIE METOD

	CChangeTableSize *changeTableSize = new CChangeTableSize(collector);
	CMenuCommand *changeTableSizeMenu = new CMenuCommand("zmien dlugosc tablicy", "zmien dl", changeTableSize);

	CChangeName *changeName = new CChangeName(collector);
	CMenuCommand *changeNameMenu = new CMenuCommand("zmien nazwe wybranego ctable", "zmien nazwe", changeName);

	CChangeOneField *changeField = new CChangeOneField(collector);
	CMenuCommand *changeFieldMenu = new CMenuCommand("zmien jedna wartosc w tabeli", "zmien wartosc", changeField);




	vector<CMenuItem*> vectorChangeMenu;

	CMenu *changeMenu = new CMenu("menu zmian", "zmiana", &vectorChangeMenu);

	changeMenu->addNewItem(changeTableSizeMenu);
	changeMenu->addNewItem(changeNameMenu);
	changeMenu->addNewItem(changeFieldMenu);
	changeMenu->addNewItem(makeClearScreenCommand());


	// MAIN MENU	------------------------------------------------------------------
	// @ TWORZENIE METOD

	CMakeNewCTables *makeNewCtables = new CMakeNewCTables(collector);
	CMenuCommand *makeNewCtablesMenu = new CMenuCommand("dodaj nowe ctables", "dodaj", makeNewCtables);

	CGiveInfo *giveInfo = new CGiveInfo(collector);
	CMenuCommand *giveInfoMenu = new CMenuCommand("wyswietl informacje o objekcie", "info", giveInfo);

	CCloneElem *clone = new CCloneElem(collector);
	CMenuCommand *cloneMenu = new CMenuCommand("klonuj i dodaj element", "klonuj", clone);





	vector<CMenuItem*> vectorMainMenu;

	CMenu *mainMenu = new CMenu("Main Menu", "main", &vectorMainMenu);

	mainMenu->addNewItem(deleteMenu);
	mainMenu->addNewItem(changeMenu);

	mainMenu->addNewItem(makeNewCtablesMenu);
	mainMenu->addNewItem(giveInfoMenu);
	mainMenu->addNewItem(cloneMenu);

	mainMenu->addNewItem(makeClearScreenCommand());


	mainMenu->run();




	// DELETE ELEMENTS

	delete mainMenu;


}//koniec metody config



CMenuCommand* CConfig::makeClearScreenCommand() {
	CClearScreen *clearScreen = new CClearScreen();
	CMenuCommand *clearScreenMenu = new CMenuCommand("wyczysc ekran", "cls", clearScreen);
	return clearScreenMenu;
}






















