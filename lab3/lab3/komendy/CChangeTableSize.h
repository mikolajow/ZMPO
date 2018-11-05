#pragma once

#include "../podstawowe/CTableCollector.h"
#include "../podstawowe/CCommand.h"

#define S_WRONG_VALUE_NOTHING_HAPPENED "Podano zla wartosc operacja nie zostala przeprowadzona"
#define S_GIVE_INDEX  "Podaj index objektu"
#define S_GIVE_NEW_TABLE_SIZE "Podaj nowa dlugosc tablicy"
#define S_EMPTY_LIST "Pusta lista nic sie nie zadzialo"

class CChangeTableSize : public CCommand {

public:

	CChangeTableSize(CTableCollector *collector);

	void runCommand();

private:

	CTableCollector *collector;

};
































