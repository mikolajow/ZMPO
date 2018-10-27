#pragma once

#include "CTableCollector.h"
#include "CCommand.h"


#define S_GIVE_INDEX_TO_CLONE  "Podaj index objektu do sklonowania"



class CCloneElem : public CCommand {

public:

	CCloneElem(CTableCollector *collector);

	void runCommand();

	void cloneAndAdd(int index);

private:

	CTableCollector *collector;

};



