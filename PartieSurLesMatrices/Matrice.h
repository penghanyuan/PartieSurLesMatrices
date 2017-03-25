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
	MyType * operator[](int ligne);


};


template<class MyType> CMatrice<MyType>::CMatrice()
{
	uiMATNbLigne = 0;
	uiMATNbColonne = 0;
	pMATElement = NULL;
}


template<class MyType>  CMatrice<MyType>::~CMatrice()
{
	unsigned int i = 0;
	for (i = 0; i < uiMATNbLigne; i++){
		delete[] pMATElement[i];
	}
	delete[] pMATElement;
}

template<class MyType>  CMatrice<MyType>::CMatrice(CMatrice &vCmat)
{
	unsigned int i = 0, j = 0;

	//copier les data
	uiMATNbLigne = vCmat.uiMATNbLigne;
	uiMATNbColonne = vCmat.uiMATNbColonne;
	//allouer la memoire
	pMATElement = new MyType*[uiMATNbLigne];
	if (pMATElement == NULL){
		Cexception exc2("ERROR: fail to malloc for the row.");
		throw exc2;
	}
	for (i = 0; i < uiMATNbLigne; i++){
		pMATElement[i] = new MyType[uiMATNbColonne];
		if (pMATElement[i] == NULL){
			Cexception exc3("ERROR: fail to malloc for the column.");
			throw exc3;
		}
	}

	for (i = 0; i < uiMATNbLigne; i++){
		for (j = 0; j < uiMATNbColonne; j++){
			pMATElement[i][j] = vCmat.pMATElement[i][j];
		}
	}
}

template<class MyType>  unsigned int CMatrice<MyType>::MATLireNbLigne()
{
	// retourner la valeur de la ligne
	return uiMATNbLigne;
}

template<class MyType>  unsigned int CMatrice<MyType>::MATLireNbColonne()
{
	// retourner la valeur de la colonne
	return uiMATNbColonne;
}

template<class MyType>  void CMatrice<MyType>::MATCreerMatrice(unsigned int ligne, unsigned int colonne)
{
	unsigned int i = 0;
	// jeter une exception
	if (ligne <= 0 || colonne <= 0){
		Cexception exc1("Error: illegal matrix size.");
		throw exc1;
	}
	// definir la ligne et colonne
	uiMATNbLigne = ligne;
	uiMATNbColonne = colonne;

	//allouer la memoire
	pMATElement = new MyType*[uiMATNbLigne];
	if (pMATElement == NULL){
		Cexception exc2("Error: fail to malloc.");
		throw exc2;
	}
	
	for (i = 0; i < uiMATNbColonne; i++){
		if (pMATElement[i] == NULL){
			Cexception exc3("Error: fail to malloc.");
			throw exc3;
		}
		pMATElement[i] = new MyType[uiMATNbColonne];
	}
}

template<class MyType> 	void  CMatrice<MyType>::MATConcretiserMatrice(MyType *pLigne, unsigned int ligne)
{
	unsigned int j = 0;
	if (ligne > uiMATNbLigne){
		Cexception exc("ERROR: Wrong line number");
		throw exc;
	}
	for (j = 0; j < uiMATNbColonne; j++){
		pMATElement[ligne - 1][j] = pLigne[j];
	}
}

template<class MyType>  CMatrice<MyType> & CMatrice<MyType>::MATTransposer()
{
	unsigned int ligneT = uiMATNbColonne;
	unsigned int colonneT = uiMATNbLigne;
	CMatrice<MyType> *matriceT = new CMatrice<MyType>;

	// creer la matrice transposee
	matriceT->MATCreerMatrice(ligneT, colonneT);
	for (i = 0; i < ligneT; i++)
	{
		for (j = 0; j < colonneT; j++)
		{
			matriceT->pMATElement[i][j] = pMATElement[j][i];
		}
	}
	// retourner la matrice transposee
	return *matriceT;
}

template<class MyType> void CMatrice<MyType>::MATAfficher()
{
	unsigned int i, j;
	for (i = 0; i < uiMATNbLigne; i++){
		for (j = 0; j < uiMATNbColonne; j++){
			printf("%d ", pMATElement[i][j]);
		}
		printf("\n");
	}
}
template<class MyType> CMatrice<MyType> &  CMatrice<MyType>::operator*(double dPara)
{
	CMatrice *vMat = new CMatrice;
	//MyType *ligne = new MyType[uiMATNbColonne];
	int i = 0, j = 0;
	vMat->MATCreerMatrice(uiMATNbLigne, uiMATNbColonne);
	for (i = 0; i < uiMATNbLigne; i++){
		for (j = 0; j < uiMATNbColonne; j++){
			vMat->pMATElement[i][j] = dPara*pMATElement[i][j];
		}
	}
	return *vMat;
}

template<class MyType> CMatrice<MyType> &  CMatrice<MyType>::operator+(CMatrice<MyType> mPara){
	if (mPara.uiMATNbColonne != uiMATNbColonne || mPara.uiMATNbLigne != uiMATNbLigne){
		Cexception exc("ERROR: Two martix should have same size when using +!");
		throw exc;
	}
	int i = 0, j = 0;
	CMatrice<MyType> *vMat = new CMatrice<MyType>;
	//MyType *ligne = new MyType[uiMATNbColonne];
	vMat->MATCreerMatrice(uiMATNbLigne, uiMATNbColonne);

	for (i = 0; i < uiMATNbLigne; i++){
		for (j = 0; j < uiMATNbColonne; j++){
			vMat->pMATElement[i][j] = mPara.pMATElement[i][j] + pMATElement[i][j];
		}
	}
	return *vMat;
}


template<class MyType> CMatrice<MyType> & CMatrice<MyType> :: operator*(CMatrice<MyType> mPara)
{
	MyType somme;
	CMatrice<MyType> *matriceProduit = new CMatrice<MyType>;
	// jeter une exception
	if (uiMATNbColonne != mPara.uiMATNbLigne)
	{
		Cexception exc1("Error: illegal matrix size for multiplication.");
		throw exc1;
	}

	// multiplication
	matriceProduit->MATCreerMatrice(uiMATNbLigne, mPara.uiMATNbColonne);
	for (i = 0; i < uiMATNbLigne; i++)
	{
		for (j = 0; j < mPara.uiMATNbColonne; j++)
		{
			somme = 0;
			for (k = 0; k < uiMATNbColonne; k++)
			{
				somme = somme + pMATElement[i][k] * mPara.pMATElement[k][j];
			}
			matriceProduit[i][j]

		}
	}

}

template<class MyType> CMatrice<MyType> & CMatrice<MyType> :: operator=(CMatrice<MyType> mPara)
{
	if (mPara.uiMATNbColonne != uiMATNbColonne || mPara.uiMATNbLigne != uiMATNbLigne){
		Cexception exc("ERROR: Two martix should have same size when using = !");
		throw exc;
	}

	unsigned int i = 0, j = 0;

	//copier les data
	uiMATNbLigne = mPara.uiMATNbLigne;
	uiMATNbColonne = mPara.uiMATNbColonne;
	//allouer la memoire
	pMATElement = new MyType*[uiMATNbLigne];
	if (pMATElement == NULL){
		Cexception exc2("ERROR: fail to malloc for the row.");
		throw exc2;
	}
	for (i = 0; i < uiMATNbLigne; i++){
		pMATElement[i] = new MyType[uiMATNbColonne];
		if (pMATElement[i] == NULL){
			Cexception exc3("ERROR: fail to malloc for the column.");
			throw exc3;
		}
	}

	for (i = 0; i < uiMATNbLigne; i++){
		for (j = 0; j < uiMATNbColonne; j++){
			pMATElement[i][j] = mPara.pMATElement[i][j];
		}
	}

	return *this;
}

template<class MyType> CMatrice<MyType> &  CMatrice<MyType>::operator/(double dPara)
{
	if (dPara == 0){
		Cexception exc("ERROR: Divisor can't be 0!");
		throw exc;
	}
	CMatrice *vMat = new CMatrice;
	//MyType *ligne = new MyType[uiMATNbColonne];
	unsigned int i = 0, j = 0;
	vMat->MATCreerMatrice(uiMATNbLigne, uiMATNbColonne);
	for (i = 0; i < uiMATNbLigne; i++){
		for (j = 0; j < uiMATNbColonne; j++){
			vMat->pMATElement[i][j] = pMATElement[i][j]/dPara;
		}
	}
	return *vMat;
}

template<class MyType> MyType *  CMatrice<MyType>::operator[](int dPara)
{
	return pMATElement[dPara];
}