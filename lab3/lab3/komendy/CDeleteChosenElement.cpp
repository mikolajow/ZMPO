#include "CDeleteChosenElement.h"
#include<iostream>




CDeleteChosenElement::CDeleteChosenElement(CTableCollector *collect) {
	collector = collect;
}


void CDeleteChosenElement::runCommand() {
	vector<CTable*> *vec = collector->getVector();

	if (vec->empty()) {
		cout << S_EMPTY_LIST << endl;
	}
	else
	{
		cout << S_GIVE_INDEX_TO_DELETE << endl;
		int chosenIndex = collector->giveMeAnIndex();
		deleteCTable(chosenIndex);
	}
}



void CDeleteChosenElement::deleteCTable(int index) {
	vector<CTable*> *vec = collector->getVector();
	CTable *chosen = (*vec)[index];
	(*vec).erase((*vec).begin() + index);
	delete chosen;
}


