#include "CChangeTableSize.h"
#include<iostream>




CChangeTableSize::CChangeTableSize(CTableCollector *collect) {
	collector = collect;
}


void CChangeTableSize::runCommand() {

	cout << S_GIVE_INDEX << endl;

	int tableIndex = collector->giveMeAnIndex();

	cout << S_GIVE_NEW_TABLE_SIZE << endl;

	int newTableLength = collector->giveMeANumber();

	bool success = (*(collector->getVector()))[tableIndex]->setTableSize(newTableLength);
	if (!success) {
		cout << S_WRONG_VALUE_NOTHING_HAPPENED << endl;
	}
}



























