
#include "CGetInfo.h"
#include<iostream>



CGiveInfo::CGiveInfo(CTableCollector *collect) {
	collector = collect;
}


void CGiveInfo::runCommand() {

	cout << S_GIVE_INDEX_OF_OBJECT_U_WANT_KNOW << endl;
	int index = collector->giveMeAnIndex();
	printCTable(index);

}



void CGiveInfo::printCTable(int index) {
	vector<CTable*> *vec = collector->getVector();
	cout << (*vec)[index]->toString() << endl;
}













