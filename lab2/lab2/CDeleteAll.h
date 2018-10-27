#pragma once

#include "CTableCollector.h"
#include "CCommand.h"


#define S_SURE_WANA_DELETE_ALL  "Na pewno chcesz skasowac wszystkie elementy? wprowadz 1 jesli tak"
#define S_EMPTY_LIST "Pusta lista nic sie nie zadzialo"



class CDeleteAll : public CCommand {

public:

	CDeleteAll(CTableCollector *collector);

	void runCommand();

	void deleteAll();

private:

	CTableCollector *collector;

};







