#pragma once
#include <iostream>
class Cexception
{
private:
	char * sEXEMsg;
public:
	//definir les constructeurs et les destructeurs
	Cexception();
	~Cexception();
	Cexception(Cexception &vExe);
	Cexception(char *sMsg);

	//definir les methodes
	void EXEModifierMsg(char *sMsg);
	const char* EXELireMsg();

};

