#pragma once
#include<vector>
#include "CTable.h"



#define S_DEFAULT_COMMAND "Komenda domyslna "


using namespace std;

class CCommand {

public:

	virtual void runCommand();

	virtual ~CCommand();
	
};










































