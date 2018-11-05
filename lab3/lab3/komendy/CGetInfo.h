#pragma once

#include "../podstawowe/CTableCollector.h"
#include "../podstawowe/CCommand.h"

#define S_GIVE_INDEX_OF_OBJECT_U_WANT_KNOW  "wprowadz index objektu o ktorym chcesz dostac informacje"
#define S_EMPTY_LIST "Pusta lista nic sie nie zadzialo"


class CGiveInfo : public CCommand {

public:

	CGiveInfo(CTableCollector *collector);

	void runCommand();

	void printCTable(int index);

private:

	CTableCollector *collector;

};











