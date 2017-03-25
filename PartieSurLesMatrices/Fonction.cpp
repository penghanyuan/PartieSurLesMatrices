#include "Fonction.h"


CFonction::CFonction()
{
}


CFonction::~CFonction()
{
}
bool CFonction::FONVideString(char *vPara)
{
	if (strcmp(vPara, "") == 0)
		return true;
	else
		return false;
}