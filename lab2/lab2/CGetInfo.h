#pragma once

#include "CTableCollector.h"
#include "CCommand.h"

#define S_GIVE_INDEX_OF_OBJECT_U_WANT_KNOW  "wprowadz index objektu o ktorym chcesz dostac informacje"



class CGiveInfo : public CCommand {

public:

	CGiveInfo(CTableCollector *collector);

	void runCommand();

	void printCTable(int index);

private:

	CTableCollector *collector;

};











