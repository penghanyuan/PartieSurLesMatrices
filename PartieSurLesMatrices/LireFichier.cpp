#include "LireFichier.h"

CLireFichier::CLireFichier()
{
	uiLIFNbLigne = 0;
	uiLIFNbColonne = 0;
	uiNbContenu = 0;
	sLIFPath = NULL;
	pLIFElement = NULL;
	pContenu = NULL;
	sLIFType = NULL;
}


CLireFichier::~CLireFichier()
{
	if (sLIFPath != NULL)
	{
		free(sLIFPath);
	}
	if (sLIFType != NULL)
	{
		free(sLIFType);
	}
	if (pLIFElement != NULL)
	{
		unsigned int i = 0;
		for (i = 0; i < uiLIFNbLigne; i++){
			delete [] pLIFElement[i];
		}
		delete [] pLIFElement;
	}
	if (pContenu != NULL)
	{
		for (unsigned int i = 0; i < uiNbContenu; i++)
		{
			free(pContenu[i]);
		}
		free(pContenu);
	}

}

CLireFichier::CLireFichier(CLireFichier &vLif)
{
	unsigned int i = 0, j = 0;
	//copier les data
	uiLIFNbLigne = vLif.uiLIFNbLigne;
	uiLIFNbColonne = vLif.uiLIFNbColonne;
	//allouer la memoire et copier les data
	if (vLif.sLIFType != NULL){
		sLIFType = _strdup(vLif.sLIFType);
	}
	else{
		sLIFType = NULL;
	}
	if (vLif.sLIFPath != NULL)
	{
		sLIFPath = _strdup(vLif.sLIFPath);
	}
	else{
		sLIFPath = NULL;
	}
	if (vLif.pLIFElement != NULL)
	{
		pLIFElement = new double*[uiLIFNbLigne];
		if (pLIFElement == NULL){
			Cexception exc2("ERROR: fail to malloc.");
			throw exc2;
		}
		for (i = 0; i < uiLIFNbLigne; i++){
			pLIFElement[i] = new double[uiLIFNbColonne];
		}
		for (i = 0; i < uiLIFNbLigne; i++){
			for (j = 0; j < uiLIFNbColonne; j++){
				pLIFElement[i][j] = vLif.pLIFElement[i][j];
			}
		}
	}
	else{
		pLIFElement = NULL;
	}
	if (vLif.pContenu != NULL)
	{
		pContenu = (char**)malloc(sizeof(char*)*uiNbContenu);
		if (pContenu == NULL){
			Cexception exc3("ERROR: fail to malloc for the row.");
			throw exc3;
		}
		for (i = 0; i < uiNbContenu; i++){
			pContenu[i] = _strdup(vLif.pContenu[i]);
		}
	}
	else{
		pContenu = NULL;
	}
}

CLireFichier::CLireFichier(char *sPath)
{
	uiLIFNbLigne = 0;
	uiLIFNbColonne = 0;
	uiNbContenu = 0;
	sLIFPath = _strdup(sPath);
	pLIFElement = NULL;
	pContenu = NULL;
	sLIFType = NULL;
}
void CLireFichier::LIFLireFichier()
{
	unsigned int ligneCount = 0;
	char buffer[256];
	CFonction fonction;
	memset(buffer, '\0', 256);
	ifstream ReadFile(sLIFPath);
	if (ReadFile.fail()){
		Cexception exc("ERROR: open file failed!");
		throw exc;
	}
	else//ÎÄ¼þ´æÔÚ  
	{
		while (ReadFile.getline(buffer, 256, '\n')){
			if (!fonction.FONVideString(buffer)){
				ligneCount++;
				pContenu = (char**)realloc(pContenu, ligneCount * sizeof(char *));
				if (pContenu == NULL){
					Cexception exc1("ERROR: create memory failed!");
					throw exc1;
				}
				pContenu[ligneCount - 1] = _strdup(buffer);
			}
		}
		uiNbContenu = ligneCount;
	}
	
}
void CLireFichier::LIFDecomposerType()
{
	const char *dMid = " =";
	char *tmp = NULL, *res = NULL, *pNext = NULL;
	tmp = strtok_s(pContenu[0], dMid, &pNext);
	while (tmp){
		res = tmp;
		tmp =  strtok_s(NULL, dMid, &pNext);
	}
	sLIFType = _strdup(res);
}
void CLireFichier::LIFDecomposerNbLigne()
{
	const char *dMid = " =";
	char *tmp = NULL, *res = NULL, *pNext = NULL;
	tmp = strtok_s(pContenu[1], dMid, &pNext);
	while (tmp){
		res = tmp;
		tmp = strtok_s(NULL, dMid, &pNext);
	}
	uiLIFNbLigne = atoi(res);
	printf("%d\n", uiLIFNbLigne);
}
void CLireFichier::LIFDecomposerNbColonne()
{
	const char *dMid = " =";
	char *tmp = NULL, *res = NULL, *pNext = NULL;
	tmp = strtok_s(pContenu[2], dMid, &pNext);
	while (tmp){
		res = tmp;
		tmp = strtok_s(NULL, dMid, &pNext);
	}
	uiLIFNbColonne = atoi(res);
	printf("%d\n", uiLIFNbColonne);
}