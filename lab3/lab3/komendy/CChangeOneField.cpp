
#include "CChangeOneField.h"
#include<iostream>



CChangeOneField::CChangeOneField(CTableCollector *collect) {
	collector = collect;
}


void CChangeOneField::runCommand() {
	vector<CTable*> *vec = collector->getVector();

	if (vec->empty()) {
		cout << S_EMPTY_LIST << endl;
	}
	else
	{
		cout << S_GIVE_OJECT_INDEX_FOR_NEW_VALUE << endl;
		int cTableIndex = collector->giveMeAnIndex();
		cout << S_GIVE_INDEX_OF_FIELD_IN_TABLE_TO_CHANGE << endl;
		int valueIndex = collector->giveMeANumber();
		cout << S_GIVE_NEW_VALUE << endl;
		int newValue = collector->giveMeANumber();
		bool success = changeOneValueOfCTable(cTableIndex, valueIndex, newValue);
		if (!success) {
			cout << S_WRONG_INDEX << endl;
		}
	}//koniec else
}//koiec metody



bool CChangeOneField::changeOneValueOfCTable(int cTableIndex, int valueIndex, int newValue) {
	vector<CTable*> *vec = collector->getVector();
	bool success = (*vec)[cTableIndex]->setValueOnIndex(valueIndex, newValue);
	return success;
}
