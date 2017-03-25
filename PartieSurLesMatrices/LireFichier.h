#pragma once
#include <iostream>
#include <fstream>
#include "Matrice.h"
#include "Fonction.h"
#include "Cexception.h"
using namespace std;

class CLireFichier
{
private:
	char * sLIFPath;
	unsigned int uiLIFNbLigne;
	unsigned int uiLIFNbColonne;
	double **pLIFElement;
	char **pContenu;
	unsigned int uiNbContenu;
	char *sLIFType;
public:
	//definir les constructeurs et les destructeurs

	CLireFichier();
	~CLireFichier();
	CLireFichier(CLireFichier &vLif);
	explicit CLireFichier(char *sPath);

	//definir les methodes
	void LIFDecomposerType();
	void LIFDecomposerNbLigne();
	void LIFDecomposerNbColonne();
	void LIFDecomposerContenu();
	const char* LIFLirePath();
	void LIFModifierPath(const char *sPath);
	void LIFLireFichier();//lire tous les strings legaux du fichier
	void LIFCreerMatrice(CMatrice<double> &vMat);
};

