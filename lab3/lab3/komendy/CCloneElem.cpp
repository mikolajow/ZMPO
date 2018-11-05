
#include "CCloneElem.h"
#include<iostream>



CCloneElem::CCloneElem(CTableCollector *collect) {
	collector = collect;
}


void CCloneElem::runCommand() {
	vector<CTable*> *vec = collector->getVector();

	if (vec->empty()) {
		cout << S_EMPTY_LIST << endl;
	}
	else
	{
		cout << S_GIVE_INDEX_TO_CLONE << endl;
		int index = collector->giveMeAnIndex();
		cloneAndAdd(index);
	}
}


void CCloneElem::cloneAndAdd(int index) {
	vector<CTable*> *vec = collector->getVector();
	CTable *clone = (*vec)[index]->clone();
	(*vec).push_back(clone);
}
