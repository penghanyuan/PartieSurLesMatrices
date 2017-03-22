#include <iostream>
#include "Matrice.h"
#include "LireFichier.h"
using namespace std;
int main(void){
	CMatrice<int> vMat;
	try{
		vMat.MATCreerMatrice(2, 2);
		int ligne[2] = { 1, 2 };
		vMat.MATConcretiserMatrice(ligne, 1);
	}
	catch (Cexception e){
		cout << e.EXELireMsg()<<endl;
	}
	return 0;
}