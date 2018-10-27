#pragma once

#include "CTableCollector.h"
#include "CCommand.h"


#define S_SURE_WANA_DELETE_ALL  "Na pewno chcesz skasowac wszystkie elementy? wprowadz 1 jesli tak"




class CDeleteAll : public CCommand {

public:

	CDeleteAll(CTableCollector *collector);

	void runCommand();

	void deleteAll();

private:

	CTableCollector *collector;

};







