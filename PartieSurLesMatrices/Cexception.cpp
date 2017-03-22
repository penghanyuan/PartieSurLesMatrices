#include "Cexception.h"


Cexception::Cexception()
{
}


Cexception::~Cexception()
{
}
Cexception::Cexception(Cexception &vExe)
{
	
}
Cexception::Cexception(char *sMsg)
{
	sEXEMsg = sMsg;
}

void Cexception::EXEModifierMsg(char *sMsg)
{
	sEXEMsg = sMsg;
}
const char* Cexception::EXELireMsg()
{
	return (const char*)sEXEMsg;
}