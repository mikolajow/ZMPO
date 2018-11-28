#include "CItem.h"



CItem::CItem(string nam, double weig, double val)
{
	name = nam;
	value = val;
	weight = weig;
}


string CItem::getName() { return name; }
double CItem::getValue() { return value; }
double CItem::getWeight() { return weight; }





























