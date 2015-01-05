#ifndef __RIGAORDINE_H__
#define __RIGAORDINE_H__
#include <cstdlib>
#include <iostream>
#include "tipoprodotto.h"
using namespace std;

//TipoProdotto tp;
			
class RigaOrdine {
	private:
		int IDOrdine;
		int IDProdotto;
	public:
		RigaOrdine();
		RigaOrdine(int _IDO, int _IDP);
		//void inserisciOrdine(); metodo da implementare
};


#endif
