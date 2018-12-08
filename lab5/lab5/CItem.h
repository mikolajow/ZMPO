#include <string>
#include <iostream>


using namespace std;


class CItem
{
public:

	CItem(string nam, double weig, double val);

	string getName();
	double getValue();
	double getWeight();
private:
	string name;

	double value;
	
	double weight;
};




























