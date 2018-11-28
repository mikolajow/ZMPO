#include "CConfig.h"
#include <typeinfo>


void CConfig::config() {


	CTableCollector *collector = new CTableCollector();



	// MENU USUWANIA	--------------------------------------------------------------
	// @ TWORZENIE METOD

	CDeleteChosenElement *deleteChosenElement = new CDeleteChosenElement(collector);
	CMenuCommand *deleteChosenElementMenu = new CMenuCommand("usun wybrane ctable", "usun", "wybierz tablice ktora ma zostac usunieta wprowadzajac jej index", deleteChosenElement);

	CDeleteAll *deleteAll = new CDeleteAll(collector);
	CMenuCommand *deleteAllMenu = new CMenuCommand("usun wszystkie", "usun wszy", "usun wszystkie tabele, po wybraniu metody nalezy potwierdzic wpisujac 1", deleteAll);




	vector<CMenuItem*> *vectorDeleteMenu = new vector<CMenuItem*>;

	CMenu *deleteMenu = new CMenu("menu usuwania", "usuwanie", vectorDeleteMenu);

	deleteMenu->addNewItem(deleteChosenElementMenu);
	deleteMenu->addNewItem(deleteAllMenu);
	deleteMenu->addNewItem(makeClearScreenCommand());


	// MENU ZMIAN ---------------------------------------------------------------
	// @ TWORZENIE METOD

	CChangeTableSize *changeTableSize = new CChangeTableSize(collector);
	CMenuCommand *changeTableSizeMenu = new CMenuCommand("zmien dlugosc tablicy", "zmien dl", "wybierz objekt ktoremu chcesz zmienic dlugosc tablicy, dlugosc mozna jedynie zwiekszyc, co ma uniemozliwic ewentualna utrate danych", changeTableSize);

	CChangeName *changeName = new CChangeName(collector);
	CMenuCommand *changeNameMenu = new CMenuCommand("zmien nazwe wybranego ctable", "zmien nazwe", "wubierz tabele ktorej chcesz zmienic nazwe poprzez podanie indexu i nowej nazwy", changeName);

	CChangeOneField *changeField = new CChangeOneField(collector);
	CMenuCommand *changeFieldMenu = new CMenuCommand("zmien jedna wartosc w tabeli", "zmien wartosc", "wybierz objekt wpisujac jego index nastepnie wybierz komorke w ktorej chcesz wprowadzic nowa wartosc", changeField);



	vector<CMenuItem*> *vectorTest =  new vector<CMenuItem*>;
	CMenu *test = new CMenu("testowe", "test", vectorTest);
	test->addNewItem(makeClearScreenCommand());



	vector<CMenuItem*> *vectorChangeMenu = new vector<CMenuItem*>;

	CMenu *changeMenu = new CMenu("menu zmian", "zmiana", vectorChangeMenu);


	changeMenu->addNewItem(test);

	changeMenu->addNewItem(changeTableSizeMenu);
	changeMenu->addNewItem(changeNameMenu);
	changeMenu->addNewItem(changeFieldMenu);
	changeMenu->addNewItem(makeClearScreenCommand());


	// MAIN MENU	------------------------------------------------------------------
	// @ TWORZENIE METOD

	CMakeNewCTables *makeNewCtables = new CMakeNewCTables(collector);
	CMenuCommand *makeNewCtablesMenu = new CMenuCommand("dodaj nowe ctables", "dodaj", "utworz nowe tabele, zostana one domyslnie wypelnione zerami", makeNewCtables);

	CGiveInfo *giveInfo = new CGiveInfo(collector);
	CMenuCommand *giveInfoMenu = new CMenuCommand("wyswietl informacje o objekcie", "info", "wyswietl informacje o wybranej tablicy", giveInfo);

	CCloneElem *clone = new CCloneElem(collector);
	CMenuCommand *cloneMenu = new CMenuCommand("klonuj i dodaj element", "klonuj", "podaj index tabeli ktora chcesz zklonowac, nazwa klona bedzie konczyc sie na _copy", clone);





	vector<CMenuItem*> *vectorMainMenu = new vector<CMenuItem*>;

	CMenu *mainMenu = new CMenu("Main Menu", "main", vectorMainMenu);

	mainMenu->addNewItem(deleteMenu);
	mainMenu->addNewItem(changeMenu);

	mainMenu->addNewItem(makeNewCtablesMenu);
	mainMenu->addNewItem(giveInfoMenu);
	mainMenu->addNewItem(cloneMenu);

	mainMenu->addNewItem(makeClearScreenCommand());


	//modyfikacja 2:    do zadania 2 

	//vector<CMenu*> vec;
	//vec.push_back(mainMenu);
	//mainMenu->printMenu(&vec);

	//koniec dodyfikacji 2		do zadania 2


	string save;

	cout << endl << endl;
	//save = mainMenu->saveToString();
	//cout << "To jest zais menu do stringa:" << endl;
	//cout << save << endl << endl;;


	//save = S_MENU_TO_LOAD;

	//CMenu *loaded = new CMenu(save, save);

	//loaded->changePlaces(changeMenu, deleteMenu);

	//loaded->run();
	

	mainMenu->changePlaces(deleteMenu, changeMenu);

	mainMenu->run();


	// DELETE ELEMENTS

	delete mainMenu;
	//delete loaded;

}//koniec metody config



CMenuCommand* CConfig::makeClearScreenCommand() {
	CClearScreen *clearScreen = new CClearScreen();
	CMenuCommand *clearScreenMenu = new CMenuCommand("wyczysc ekran", "cls", "czysci ekran i wyswietla menu w ktorym aktualnie sie znajdujesz", clearScreen);
	return clearScreenMenu;
}






















