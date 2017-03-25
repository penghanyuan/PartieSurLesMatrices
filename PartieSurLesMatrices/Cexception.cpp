#include "Cexception.h"


Cexception::Cexception()
{
	sEXEMsg = NULL;
}


Cexception::~Cexception()
{
	free(sEXEMsg);
}
Cexception::Cexception(Cexception &vExe)
{
	sEXEMsg = _strdup(vExe.sEXEMsg);
}
Cexception::Cexception(char *sMsg)
{
	sEXEMsg = _strdup(sMsg);
}

void Cexception::EXEModifierMsg(char *sMsg)
{
	sEXEMsg = _strdup(sMsg);
}
const char* Cexception::EXELireMsg()
{
	return (const char*)sEXEMsg;
}