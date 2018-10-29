#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "CCommand.h"
#include "CMenuItem.h"
#include "CMenu.h"
#include "CMenuCommand.h"


#include "CMakeNewCTables.h"
#include "CChangeTableSize.h"
#include "CDeleteChosenElement.h"
#include "CDeleteAll.h"
#include "CChangeName.h"
#include "CGetInfo.h"
#include "CChangeOneField.h"
#include "CCloneElem.h"
#include "CClearScreen.h"


class CConfig {

public:

	void config();

private:


	CMenuCommand* makeClearScreenCommand();
};





























