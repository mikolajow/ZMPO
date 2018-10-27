#include "CChangeTableSize.h"
#include<iostream>




CChangeTableSize::CChangeTableSize(CTableCollector *collect) {
	collector = collect;
}


void CChangeTableSize::runCommand() {
	vector<CTable*> *vec = collector->getVector();

	if (vec->empty()) {
		cout << S_EMPTY_LIST << endl;
	}
	else
	{
		cout << S_GIVE_INDEX << endl;

		int tableIndex = collector->giveMeAnIndex();

		cout << S_GIVE_NEW_TABLE_SIZE << endl;

		int newTableLength = collector->giveMeANumber();

		bool success = (*(collector->getVector()))[tableIndex]->setTableSize(newTableLength);
		if (!success) {
			cout << S_WRONG_VALUE_NOTHING_HAPPENED << endl;
		}
	}//koniec else
}//koniec metody



























