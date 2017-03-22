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
	// jeter une exception
	if (ligne <= 0 || colonne <= 0){
		Cexception exc1("Error: illegal matrix size.");
		throw exc1;
	}
	// definir la ligne et colonne
	uiMATNbLigne = ligne;
	uiMATNbColonne = colonne;

	//allouer la memoire
	if (pMATElement == NULL){
		Cexception exc2("Error: fail to malloc.");
		throw exc2;
	}
	pMATElement = new MyType*[uiMATNbLigne];
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
	int j = 0;
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