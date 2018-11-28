
#include "CTable.h"




using namespace std;


int main()
{

	CTable c_t0;
	CTable c_t1;

	c_t0.vSetSize(2);
	c_t1.vSetSize(1);
	c_t0.pi_tab[0] = 0;
	c_t0.pi_tab[1] = 1;
	c_t1.pi_tab[0] = 4;

	CTable sum;
	c_t0 + c_t1;
	sum = c_t0 + c_t1;


	for (int i = 0; i < sum.size; i++)
	cout << sum.pi_tab[i] << ",";




	int s;
	cin >> s;


}//koniec main

















