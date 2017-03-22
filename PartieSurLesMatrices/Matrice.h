#pragma once
#include "Cexception.h"

template <class MyType> class CMatrice
{
private:
	unsigned int uiMATNbLigne;
	unsigned int uiMATNbColonne;
	MyType **pMATElement;

public:
	//definir les constructeurs et les destructeurs
	CMatrice<MyType>();
	~CMatrice();
	CMatrice<MyType>(CMatrice<MyType> &vCmat);

	//definir des methodes
	unsigned int MATLireNbLigne();
	unsigned int MATLireNbColonne();
	void MATCreerMatrice(unsigned int ligne, unsigned int colonne);
	void MATConcretiserMatrice(MyType *pLigne, unsigned int ligne);
	CMatrice<MyType> & MATTransposer();
	void MATAfficher();
	
	//definir operateur
	CMatrice<MyType> & operator*(double dPara);
	CMatrice<MyType> & operator*(CMatrice<MyType> mPara);
	CMatrice<MyType> & operator+(CMatrice<MyType> mPara);
	CMatrice<MyType> & operator-(CMatrice<MyType> mPara);
	CMatrice<MyType> & operator=(CMatrice<MyType> mPara);
	CMatrice<MyType> & operator/(double dPara);

	//±£¡Ù
	MyType * operator[](unsigned int ligne);


};
