#include <iostream>
#include "Matrice.h"
#include "LireFichier.h"
using namespace std;
int main(void){
	CMatrice<int> vMat;
	CLireFichier vLif("test.txt");
	try{

		vMat.MATCreerMatrice(2, 2);
		int ligne[2] = { 3, 9 };
		int ligne1[2] = { 1, 3 };
		vMat.MATConcretiserMatrice(ligne, 1);
		vMat.MATConcretiserMatrice(ligne1, 2);
		CMatrice<int> tmp;
		tmp.MATCreerMatrice(2, 2);
		tmp = vMat / 3;
		tmp.MATAfficher();
		vLif.LIFLireFichier();
		vLif.LIFDecomposerNbLigne();
		cout<<vMat[0][1];
	}
	catch (Cexception e){
		cout << e.EXELireMsg()<<endl;
	}
	return 0;
}