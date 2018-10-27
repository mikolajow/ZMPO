#include "CMakeNewCTables.h"
#include <iostream>


using namespace std;


CMakeNewCTables::CMakeNewCTables(CTableCollector *collect) {
	collector = collect;
}



void CMakeNewCTables::runCommand() {

	cout << S_HOW_MANY_WANA_CREATE << endl;

	int howMany;
	howMany = collector->giveMeANumber();

	makeCTables(howMany);
}



void CMakeNewCTables::makeCTables(int howMany) {
	for (int i = 0; i < howMany; i++) {
		collector->getVector()->push_back(new CTable());
	}
}


























