#pragma once

class CDynaTable

{

public:

	CDynaTable();
	~CDynaTable();

	void add(int newValue);
	
	bool setValueOnIndex(int index, int newValue);

	int* getValueFromIndex(int index);

	void addValues(CDynaTable &secondTable);

	CDynaTable& operator=(CDynaTable &secondObject);

	int size;

private:

	int **table;


};





























