#pragma once

#include "../podstawowe/CTableCollector.h"
#include "../podstawowe/CCommand.h"


#define S_GIVE_NEW_NAME "Wprowadz nowa nazwe dla wybranego elementu"
#define S_GIVE_INDEX_TO_NAME_CHANGE "Wprowadz index elementu ktoremu chcesz zmienic nazwe"
#define S_EMPTY_LIST "Pusta lista nic sie nie zadzialo"


class CChangeName : public CCommand {

public:

	CChangeName(CTableCollector *collector);

	void runCommand();

	void changeName(int index, string newName);

private:

	CTableCollector *collector;

};









