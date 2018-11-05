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


class CConfig {

public:

	void config();

private:


	CMenuCommand* makeClearScreenCommand();
};





























