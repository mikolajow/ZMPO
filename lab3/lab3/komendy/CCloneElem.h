#pragma once

#include "../podstawowe/CTableCollector.h"
#include "../podstawowe/CCommand.h"


#define S_GIVE_INDEX_TO_CLONE  "Podaj index objektu do sklonowania"
#define S_EMPTY_LIST "Pusta lista nic sie nie zadzialo"


class CCloneElem : public CCommand {

public:

	CCloneElem(CTableCollector *collector);

	void runCommand();

	void cloneAndAdd(int index);

private:

	CTableCollector *collector;

};



