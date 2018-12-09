#include "CCommand.h"
#include "CGeneticAlgorithm.h"




#define S_NOT_A_NUMBER "Podana wartosc nie jest prawidlowa liczba, wprowadz wartosc jeszcze raz"
#define I_ASCII_ZERO 48
#define I_ASCII_NINE 57
#define I_ASCII_PLUS 43
#define I_ASCII_MINUS 45
#define S_GIVE_ITERATION_TIME "Wprowadz czas w sekundach dla dzialania programu"


template <class T>
class CRunAlgorithm : public CCommand
{
public:

	CRunAlgorithm(CGeneticAlgorithm<T> *a)
	{
		this->alg = a;
	}

	void runCommand();

private:

	CGeneticAlgorithm<T> *alg;
	bool isNumber(string data);
	int giveMeANumber();

};



template<class T>
void CRunAlgorithm<T>::runCommand()
{
	cout << S_GIVE_ITERATION_TIME << endl;
	int time = giveMeANumber();
	alg->run(time);
}


template <class T>
bool CRunAlgorithm<T>::isNumber(string data) {
	int signCounter = 0;
	for (unsigned int i = 0; i < data.length(); i++) {
		int asciiValue = (int)data[i];

		if (asciiValue > I_ASCII_NINE || asciiValue < I_ASCII_ZERO) { //jesli wynikiem if jest true to znaczy ze dany znak nie jest cyfr¹ - 0 w ascii to 48 a 9 w ascii to 57
			if (asciiValue == I_ASCII_PLUS) {//sprawdzam czy jest znakiem +/- ,jesli jest to zwiekszam counter
				signCounter++;
			}
			else return false;//jesli nie jest cyfra ani znakiem to zwracam false
		}//koniec if

	}//koniec for

	switch (signCounter)
	{
	case 0: return true;	//jak nie ma znakow =/- a reszta to cyfry to jest liczba
	case 1: {
		if (data[0] == '+')
			return true; //jesli znak jest tylko na pierwszej pozycji
		else
			return false;
	}//koniec case 1
	default:
		return false;
	}//koniec switch

}//koniec metody is number

template <class T>
int CRunAlgorithm<T>::giveMeANumber() {
	string data;
	bool isANumber;
	do
	{
		getline(cin, data);
		isANumber = isNumber(data);
		if (!isANumber) {
			cout << S_NOT_A_NUMBER << endl;
		}
	} while (!isANumber);
	return stoi(data);		//stoi - string to int
}//koniec give  me a number


























