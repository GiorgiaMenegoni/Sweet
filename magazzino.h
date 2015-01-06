#ifndef __MAGAZZINO_H__
#define __MAGAZZINO_H__
#include <cstdlib>
#include <iostream>
#include "tipoprodotto.h"
#include <string>


using namespace std;


class Magazzino {
	private:
		string IDMateriale;
		int quantitaDisponibileMateriale;
		string IDProdotto;
		int quantitaDisponibileProdotto;
		map <string, int> mm; //map dei materiali in magazzino
		map <string, int> pm; //map dei prodotti in magazzino
	
    public:
		Magazzino();
		Magazzino(string _IDM, int _qDM, string _IDP, int _qDP);
		
		void Stampa_quantitaDisponibileMateriale(); //stampa tutti i materiali presenti in magazzino con le relative quantita'
		void Stampa_quantitaDisponibileProdotto(); //stampa tutti i prodotti presenti in magazzino con le relative quantita'
		void inserisciQuantita();
		//void stampa(Magazzino* magaz);
		void stampa();
		void trova();
		void lettura_file_magazzino();
		
        void inserisciProdotto();
		void rimuoviProdotto();
		void modificaQuantita();
};

void test_magazzino();

#endif
