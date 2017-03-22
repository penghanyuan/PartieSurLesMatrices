#include "Matrice.h"

#define GET_ARRAY_LEN(array,len) {len = (sizeof(array) / sizeof(array[0]));}
template<class MyType> CMatrice<MyType>::CMatrice()
{
	uiMATNbLigne = 0;
	uiMATNbColonne = 0;
	pMATElement = NULL;
}

//jeigje
template<class MyType>  CMatrice<MyType>::~CMatrice()
{
	int i = 0;
	for (i = 0; i < uiMATNbLigne; i++){
		delete[] pMATElement[i];
	}
	delete[] pMATElement;
}

template<class MyType>  CMatrice<MyType>::CMatrice(CMatrice &vCmat)
{
	int i = 0,j = 0;
	
	//allouer la memoire
	pMATElement = new MyType*[uiMATNbLigne];
	for (i = 0; i < uiMATNbColonne; i++){
		pMATElement[i] = new MyType[uiMATNbColonne];
	}

	//copier les data
	uiMATNbLigne = vCmat.uiMATNbLigne;
	uiMATNbColonne = vCmat.uiMATNbColonne;

	for (i = 0; i < uiMATNbLigne; i++){
		for (j = 0; j < uiMATNbColonne; j++){
			pMATElement[i][j] = vCmat[i][j];
		}
	}
}

template<class MyType> 	void  CMatrice<MyType>::MATConcretiserMatrice(MyType *pLigne, unsigned int ligne)
{
	int j = 0;
	if (ligne > uiMATNbLigne){
		Cexception exc("ERROR: Wrong line number");
		throw exc;
	}
	for (j = 0; j < uiMATNbColonne; j++){
		pMATElement[ligne - 1][j] = pLigne[j];
	}
}


template<class MyType> CMatrice<MyType> &  CMatrice<MyType>::operator*(double dPara)
{
	CMatrice vMat;
	MyType *ligne = new MyType[uiMATNbColonne];
	int i = 0, j = 0;
	vMat.MATCreerMatrice(uiMATNbLigne, uiMATNbColonne);
	for (i = 0; i < uiMATNbLigne; i++){
		for (j = 0; j < uiMATNbColonne; j++){
			ligne[j] = dPara*pMATElement[i][j];
		}
		vMat.MATConcretiserMatrice(ligne, i + 1);
	}
}

template<class MyType> CMatrice<MyType> &  CMatrice<MyType>::operator+(double dPara)