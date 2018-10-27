#include "CDeleteAll.h"
#include<iostream>







CDeleteAll::CDeleteAll(CTableCollector *collect) {
	collector = collect;
}


void CDeleteAll::runCommand() {

	cout << S_SURE_WANA_DELETE_ALL << endl;
	int decision = collector->giveMeANumber();
	if (decision == 1) {
		deleteAll();
	}//koniec if

}




void CDeleteAll::deleteAll() {
	vector<CTable*> *vec = collector->getVector();
	for (unsigned int i = 0; i < (*vec).size(); i++) {
		delete  (*vec)[i];
	}
	(*vec).clear();
}









