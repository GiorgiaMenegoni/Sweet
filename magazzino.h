#ifndef __MAGAZZINO_H__
#define __MAGAZZINO_H__
#include <cstdlib>
#include <iostream>
#include "tipoprodotto.h"
#include "materiale.h"
#include <string>
#include <map>

using namespace std;

class Magazzino {
	private:
		string id_materiale;
		int quantita_disponibile_materiale;
		string id_prodotto;
		int quantita_disponibile_prodotto;
		map <string, int> mm; //map dei materiali in magazzino
		map <string, int> pm; //map dei prodotti in magazzino
	
    public:
		Magazzino();
		Magazzino(string _IDM, int _qDM, string _IDP, int _qDP);		
        void stampa_quantita_disponibile_materiale(); //stampa tutti i materiali presenti in magazzino con le relative quantita'
		void stampa_quantita_disponibile_prodotto(); //stampa tutti i prodotti presenti in magazzino con le relative quantita'
		void inserisci_quantita();
		void stampa();
		void trova();
		void lettura_file_magazzino_materiale();
		void lettura_file_magazzino_prodotto();
        		
        //void inserisci_prodotto();
		//void rimuovi_prodotto();
		//void modifica_quantita();
};

void test_magazzino();

#endif
