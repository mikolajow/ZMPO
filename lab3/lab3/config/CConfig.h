#pragma once
#include <iostream>
#include <vector>
#include <string>

#include "../podstawowe/CCommand.h"
#include "../podstawowe/CMenuItem.h"
#include "../podstawowe/CMenu.h"
#include "../podstawowe/CMenuCommand.h"


#include "../config/CConfig.h"
#include "../podstawowe/CTableCollector.h"
#include "../komendy/CChangeName.h"
#include "../komendy/CChangeOneField.h"
#include "../komendy/CChangeTableSize.h"
#include "../komendy/CClearScreen.h"
#include "../komendy/CCloneElem.h"
#include "../komendy/CDeleteAll.h"
#include "../komendy/CDeleteChosenElement.h"
#include "../komendy/CGetInfo.h"
#include "../komendy/CMakeNewCTables.h"


////do modyfikacji
//#define S_MENU_TO_LOAD "('Main Menu','main';6('menu usuwania','usuwanie';3['usun wybrane ctable','usun','wybierz tablice ktora ma zostac usunieta wprowadzajac jej index'],['usun wszystkie','usun wszy','usun wszystkie tabele, po wybraniu metody nalezy potwierdzic wpisujac 1'],['wyczysc ekran','cls','czysci ekran i wyswietla menu w ktorym aktualnie sie znajdujesz']),('menu zmian','zmiana';5('testowe','test';1['wyczysc ekran','cls','czysci ekran i wyswietla menu w ktorym aktualnie sie znajdujesz']),['zmien dlugosc tablicy','zmien dl','wybierz objekt ktoremu chcesz zmienic dlugosc tablicy, dlugosc mozna jedynie zwiekszyc, co ma uniemozliwic ewentualna utrate danych'],['zmien nazwe wybranego ctable','zmien nazwe','wubierz tabele ktorej chcesz zmienic nazwe poprzez podanie indexu i nowej nazwy'],['zmien jedna wartosc w tabeli','zmien wartosc','wybierz objekt wpisujac jego index nastepnie wybierz komorke w ktorej chcesz wprowadzic nowa wartosc'],['wyczysc ekran','cls','czysci ekran i wyswietla menu w ktorym aktualnie sie znajdujesz']),['dodaj nowe ctables','dodaj','utworz nowe tabele, zostana one domyslnie wypelnione zerami'],['wyswietl informacje o objekcie','info','wyswietl informacje o wybranej tablicy'],['klonuj i dodaj element','klonuj','podaj index tabeli ktora chcesz zklonowac, nazwa klona bedzie konczyc sie na _copy'],['wyczysc ekran','cls','czysci ekran i wyswietla menu w ktorym aktualnie sie znajdujesz'])"


#define S_MENU_TO_LOAD "('Main Menu','main';('menu usuwania','usuwanie';['usun wybrane ctable','usun','wybierz tablice ktora ma zostac usunieta wprowadzajac jej index'],['usun wszystkie','usun wszy','usun wszystkie tabele, po wybraniu metody nalezy potwierdzic wpisujac 1'],['wyczysc ekran','cls','czysci ekran i wyswietla menu w ktorym aktualnie sie znajdujesz']),('menu zmian','zmiana';('testowe','test';['wyczysc ekran','cls','czysci ekran i wyswietla menu w ktorym aktualnie sie znajdujesz']),['zmien dlugosc tablicy','zmien dl','wybierz objekt ktoremu chcesz zmienic dlugosc tablicy, dlugosc mozna jedynie zwiekszyc, co ma uniemozliwic ewentualna utrate danych'],['zmien nazwe wybranego ctable','zmien nazwe','wubierz tabele ktorej chcesz zmienic nazwe poprzez podanie indexu i nowej nazwy'],['zmien jedna wartosc w tabeli','zmien wartosc','wybierz objekt wpisujac jego index nastepnie wybierz komorke w ktorej chcesz wprowadzic nowa wartosc'],['wyczysc ekran','cls','czysci ekran i wyswietla menu w ktorym aktualnie sie znajdujesz']),['dodaj nowe ctables','dodaj','utworz nowe tabele, zostana one domyslnie wypelnione zerami'],['wyswietl informacje o objekcie','info','wyswietl informacje o wybranej tablicy'],['klonuj i dodaj element','klonuj','podaj index tabeli ktora chcesz zklonowac, nazwa klona bedzie konczyc sie na _copy'],['wyczysc ekran','cls','czysci ekran i wyswietla menu w ktorym aktualnie sie znajdujesz'])"


class CConfig {

public:

	void config();

private:


	CMenuCommand* makeClearScreenCommand();
};





























