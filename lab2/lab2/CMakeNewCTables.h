#pragma once

#include "CTableCollector.h"
#include "CCommand.h"

#define S_HOW_MANY_WANA_CREATE "ile objektow chcesz stworzyc?" 

class CMakeNewCTables : public CCommand{

public:

	void makeCTables(int howMany);


	CMakeNewCTables(CTableCollector *collector);

	void runCommand();

private:

	CTableCollector *collector;

};














