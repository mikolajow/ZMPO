#include "CCommand.h"



class CClearScreenCommand : public CCommand
{
public:

	CClearScreenCommand() {}

	void runCommand()
	{
		system("cls");
	}

};


































