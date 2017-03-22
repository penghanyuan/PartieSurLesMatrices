#pragma once
#include "Matrice.h"

class CLireFichier
{
private:
	char * sLIFPath;
	unsigned int uiLIFNbLigne;
	unsigned int uiLIFNbColonne;
	double *pLIFElement;
public:
	//definir les constructeurs et les destructeurs
	CLireFichier();
	~CLireFichier();
	CLireFichier(CLireFichier &vLif);
	explicit CLireFichier(char *sPath);

	//definir les methodes
	unsigned int LIFLireNbLigne();
	void LIFModifierLigne(unsigned int uiLigne);
	unsigned int LIFLireNbColonne();
	void LIFModifierColonne(unsigned int uiColonne);
	const char* LIFLirePath();
	void LIFModifierPath(const char *sPath);
	void LIFLireFichier();
	void LIFCreerMatrice(CMatrice<double> &vMat);
};

