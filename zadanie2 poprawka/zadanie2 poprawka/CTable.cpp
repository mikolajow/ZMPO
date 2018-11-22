#include "CTable.h"


CTable::CTable()
{
	pi_tab = NULL;
	size = 0;
}

CTable::CTable(CTable &pattern)
{
	size = pattern.size;
	pi_tab = new int[size];
	for (int i = 0; i < size; i++)
		pi_tab[i] = pattern.pi_tab[i];
}

CTable::~CTable()
{
	if (pi_tab) {
		delete[] pi_tab;
		cout << "usuwam"<<endl;
	}
}


void CTable::vSetSize(int newSize)
{
	if (pi_tab)
		delete[] pi_tab;
	size = newSize;
	pi_tab = new int[newSize];
}


CTable& CTable::operator+(CTable &other)
{
	CTable *sum = new CTable();
	int sumSize = this->size + other.size;
	(*sum).vSetSize(sumSize);
	for (int i = 0; i < this->size; i++)
		(*sum).pi_tab[i] = pi_tab[i];

	for (int i = 0; i < other.size; i++)
		(*sum).pi_tab[this->size + i] = other.pi_tab[i];
	return (*sum);
}// +

CTable& CTable::operator=(CTable &wzor)
{
	if (this == &wzor) return *this;
	if (pi_tab)
		delete[] pi_tab;

	size = wzor.size;
	pi_tab = new int[size];

	for (int i = 0; i < size; i++)
		pi_tab[i] = wzor.pi_tab[i];

	return *this;
}// =










