#include "CItem.h"
#include <vector>


using namespace std;

class CKnapsackProblem
{
public:

	CKnapsackProblem(vector<CItem*> *vec, double bagCapa);

	int getNumberOfItems();
	double getBagCapacity();
	vector<CItem*>* getItemList();


private:

	int numberOfItems;

	double bagCapacity;

	vector<CItem*> *itemList;

};





























