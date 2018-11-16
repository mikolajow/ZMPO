#include "CKnapsackProblem.h"



CKnapsackProblem::CKnapsackProblem(vector<CItem*> *vec, double bagCapa)
{
	itemList = vec;
	bagCapacity = bagCapa;
	numberOfItems = vec->size();
}















//GETTERS	

int CKnapsackProblem::getNumberOfItems() { return numberOfItems; }
double CKnapsackProblem::getBagCapacity() { return bagCapacity; }
vector<CItem*>* CKnapsackProblem::getItemList() { return itemList; }





























