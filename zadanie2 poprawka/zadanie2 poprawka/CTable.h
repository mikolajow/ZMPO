#include <iostream>
#include <string>

using namespace std;




class CTable
{

public:

	int *pi_tab;
	int size;
	bool tableExist;

	CTable();
	CTable(CTable &pattern);
	~CTable();

	void vSetSize(int newSize);

	CTable& operator+(CTable &other);

	CTable& operator=(CTable &other);



};//koniec klasy






