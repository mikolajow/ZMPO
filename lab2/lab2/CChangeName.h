#pragma once

#include "CTableCollector.h"
#include "CCommand.h"


#define S_GIVE_NEW_NAME "Wprowadz nowa nazwe dla wybranego elementu"
#define S_GIVE_INDEX_TO_NAME_CHANGE "Wprowadz index elementu ktoremu chcesz zmienic nazwe"



class CChangeName : public CCommand {

public:

	CChangeName(CTableCollector *collector);

	void runCommand();

	void changeName(int index, string newName);

private:

	CTableCollector *collector;

};









