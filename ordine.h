#ifndef __ORDINE_H__
#define __ORDINE_H__
#include <cstdlib>
#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include "tipoprodotto.h"
#include "materiale.h"
#include "magazzino.h"

using namespace std;

class Ordine {
      private:
        string id_ordine; //data dell'ordine
        map<string,int> mpq; //map del prodotto
        map<string,int> mm; //map del materiale
        multimap<string, map<string,int> > mo; //map dell'ordine
        TipoProdotto* tpp;
        TipoProdotto tps;
        Materiale mt;                          	
      public:
		Ordine(); //costruttore di default
		Ordine(string _IDProdotto, string _id_ordine, string _IDMateriale); //costruttore specifico
		Ordine* inserisci_ordine();
		void stampa(Ordine* ordine);
		string get_data();
};

void test_ordine();


#endif
