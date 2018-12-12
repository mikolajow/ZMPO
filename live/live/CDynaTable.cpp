#include "CDynaTable.h"




CDynaTable::CDynaTable()
{
	table = new int*[0];
	size = 0;
}


CDynaTable::~CDynaTable()
{
	for (int i = 0; i < size; i++)
	{
		delete table[i];
	}
	delete table;
}


void CDynaTable::add(int newValue)
{
	int *newDynaValue = new int(newValue);
	//zwieksz rozmiar
	int **newTable = new int*[size+1];
	
	//kopjuje
	for (int i = 0; i < size; i++)
	{
		newTable[i] = table[i];
	}

	newTable[size] = newDynaValue;
	
	//usuwam stara tablice
	delete table;

	table = newTable;

	size = size + 1;
}


bool CDynaTable::setValueOnIndex(int index, int newValue)
{
	if (index < 0 || index >= size)
		return false;
	else
	{
		int *newDynaValue = new int(newValue);
		int *oldValue = table[index];
		table[index] = newDynaValue;
		//*(table[index]) = newValue;
		delete oldValue;
		return true;
	}
}


int* CDynaTable::getValueFromIndex(int index)
{
	if (index < 0 || index >= size)
		return nullptr;
	else
		return table[index];
}


void CDynaTable::addValues(CDynaTable &secondTable)
{
	for (int i = 0; i < secondTable.size; i++)
	{
		this->add( *(secondTable.table[i]) );
	}
	//delete &(secondTable);
}


CDynaTable& CDynaTable::operator=(CDynaTable &secondObject)
{
	if (&secondObject == this)
		return *this;
	else
	{
		//usuwam aktualna
		for (int i = 0; i < size; i++)
			delete table[i];
		delete table;

		//kopjuje
		this->size = secondObject.size;
		this->table = new int*[size];
		for (int i = 0; i < size; i++)
		{
			int *newValueToAdd = new int(*(secondObject.table[i]));
			this->table[i] = newValueToAdd;
		}
		return *this;
	}//koniec else
}//koniec metody

























