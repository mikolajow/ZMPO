#pragma once

#include "CTableCollector.h"
#include "CCommand.h"


#define S_GIVE_INDEX_TO_DELETE "Podaj index elementu do skasowania"
#define S_EMPTY_LIST "Pusta lista nic sie nie zadzialo"

class CDeleteChosenElement : public CCommand {

public:

	CDeleteChosenElement(CTableCollector *collector);

	void runCommand();

	void deleteCTable(int index);

private:

	CTableCollector *collector;

};










