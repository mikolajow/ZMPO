#pragma once

#include "CTableCollector.h"
#include "CCommand.h"


#define S_GIVE_OJECT_INDEX_FOR_NEW_VALUE "Podaj index objektu ktoremu chcesz zmienic wartosc w komorce"
#define S_GIVE_INDEX_OF_FIELD_IN_TABLE_TO_CHANGE "Podaj index komorki ktora chcesz zmienic"
#define S_GIVE_NEW_VALUE "Podaj nowa wartosc"



class CChangeOneField : public CCommand {

public:

	CChangeOneField(CTableCollector *collector);

	void runCommand();

	bool changeOneValueOfCTable(int cTableIndex, int valueIndex, int newValue);


private:

	CTableCollector *collector;

};












