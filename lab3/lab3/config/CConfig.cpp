#include "CConfig.h"
#include <typeinfo>


void CConfig::config() {


	CTableCollector *collector = new CTableCollector();



	// MENU USUWANIA	--------------------------------------------------------------
	// @ TWORZENIE METOD

	CDeleteChosenElement *deleteChosenElement = new CDeleteChosenElement(collector);
	CMenuCommand *deleteChosenElementMenu = new CMenuCommand("usun wybrane ctable", "usun", deleteChosenElement, "wybierz tablice ktora ma zostac usunieta wprowadzajac jej index");

	CDeleteAll *deleteAll = new CDeleteAll(collector);
	CMenuCommand *deleteAllMenu = new CMenuCommand("usun wszystkie", "usun wszy", deleteAll, "usun wszystkie tabele, po wybraniu metody nalezy potwierdzic wpisujac 1");




	vector<CMenuItem*> vectorDeleteMenu;

	CMenu *deleteMenu = new CMenu("menu usuwania", "usuwanie", &vectorDeleteMenu);

	deleteMenu->addNewItem(deleteChosenElementMenu);
	deleteMenu->addNewItem(deleteAllMenu);
	deleteMenu->addNewItem(makeClearScreenCommand());


	// MENU ZMIAN ---------------------------------------------------------------
	// @ TWORZENIE METOD

	CChangeTableSize *changeTableSize = new CChangeTableSize(collector);
	CMenuCommand *changeTableSizeMenu = new CMenuCommand("zmien dlugosc tablicy", "zmien dl", changeTableSize, "wybierz objekt ktoremu chcesz zmienic dlugosc tablicy, dlugosc mozna jedynie zwiekszyc, co ma uniemozliwic ewentualna utrate danych");

	CChangeName *changeName = new CChangeName(collector);
	CMenuCommand *changeNameMenu = new CMenuCommand("zmien nazwe wybranego ctable", "zmien nazwe", changeName, "wubierz tabele ktorej chcesz zmienic nazwe poprzez podanie indexu i nowej nazwy");

	CChangeOneField *changeField = new CChangeOneField(collector);
	CMenuCommand *changeFieldMenu = new CMenuCommand("zmien jedna wartosc w tabeli", "zmien wartosc", changeField, "wybierz objekt wpisujac jego index nastepnie wybierz komorke w ktorej chcesz wprowadzic nowa wartosc");



	vector<CMenuItem*> vectorTest;
	CMenu *test = new CMenu("testowe", "test", &vectorTest);
	test->addNewItem(makeClearScreenCommand());



	vector<CMenuItem*> vectorChangeMenu;

	CMenu *changeMenu = new CMenu("menu zmian", "zmiana", &vectorChangeMenu);


	changeMenu->addNewItem(test);

	changeMenu->addNewItem(changeTableSizeMenu);
	changeMenu->addNewItem(changeNameMenu);
	changeMenu->addNewItem(changeFieldMenu);
	changeMenu->addNewItem(makeClearScreenCommand());


	// MAIN MENU	------------------------------------------------------------------
	// @ TWORZENIE METOD

	CMakeNewCTables *makeNewCtables = new CMakeNewCTables(collector);
	CMenuCommand *makeNewCtablesMenu = new CMenuCommand("dodaj nowe ctables", "dodaj", makeNewCtables, "utworz nowe tabele, zostana one domyslnie wypelnione zerami");

	CGiveInfo *giveInfo = new CGiveInfo(collector);
	CMenuCommand *giveInfoMenu = new CMenuCommand("wyswietl informacje o objekcie", "info", giveInfo, "wyswietl informacje o wybranej tablicy");

	CCloneElem *clone = new CCloneElem(collector);
	CMenuCommand *cloneMenu = new CMenuCommand("klonuj i dodaj element", "klonuj", clone, "podaj index tabeli ktora chcesz zklonowac, nazwa klona bedzie konczyc sie na _copy");





	vector<CMenuItem*> vectorMainMenu;

	CMenu *mainMenu = new CMenu("Main Menu", "main", &vectorMainMenu);

	mainMenu->addNewItem(deleteMenu);
	mainMenu->addNewItem(changeMenu);

	mainMenu->addNewItem(makeNewCtablesMenu);
	mainMenu->addNewItem(giveInfoMenu);
	mainMenu->addNewItem(cloneMenu);

	mainMenu->addNewItem(makeClearScreenCommand());


	//modyfikacja 2:

	//vector<CMenu*> vec;
	//vec.push_back(mainMenu);

	//mainMenu->printMenu(&vec);



	
	mainMenu->run();



	


	// DELETE ELEMENTS

	delete mainMenu;


}//koniec metody config



CMenuCommand* CConfig::makeClearScreenCommand() {
	CClearScreen *clearScreen = new CClearScreen();
	CMenuCommand *clearScreenMenu = new CMenuCommand("wyczysc ekran", "cls", clearScreen, "czysci ekran i wyswietla menu w ktorym aktualnie sie znajdujesz");
	return clearScreenMenu;
}






















