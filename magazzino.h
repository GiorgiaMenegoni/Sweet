#ifndef __MAGAZZINO_H__
#define __MAGAZZINO_H__
#include <cstdlib>
#include <iostream>
#include "tipoprodotto.h"
#include <string>


using namespace std;


class Magazzino {
	private:
		string IDProdotto;
		int quantitaDisponibile;
		map <string, string> mm;
	public:
		Magazzino();
		Magazzino(int _IDP, int qd);
		
		//void quantitàdisponibile();
        void inserisciProdotto();
		void rimuoviProdotto();
		void inserisciQuantita();
		void modificaQuantita();
};

#endif
