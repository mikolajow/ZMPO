
#include "CChangeName.h"
#include<iostream>



CChangeName::CChangeName(CTableCollector *collect) {
	collector = collect;
}


void CChangeName::runCommand() {
	vector<CTable*> *vec = collector->getVector();

	if (vec->empty()) {
		cout << S_EMPTY_LIST << endl;
	}
	else
	{
		cout << S_GIVE_INDEX_TO_NAME_CHANGE << endl;
		int chosen = collector->giveMeAnIndex();
		cout << S_GIVE_NEW_NAME << endl;
		string newName;
		getline(cin, newName);
		changeName(chosen, newName);
	}//koniec else
}//koniec run command


void CChangeName::changeName(int index, string newName) {
	vector<CTable*> *vec = collector->getVector();
	(*vec)[index]->setName(newName);
}


