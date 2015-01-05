#ifndef __ORDINE_H__
#define __ORDINE_H__
#include <cstdlib>
#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include "tipoprodotto.h"
#include "materiale.h"

using namespace std;

class Ordine {
      private:
              string IDOrdine; //data dell'ordine
              map<string,int> mpq; //map del prodotto
              map<string,int> mm; //map del materiale
              map<string, map<string,int> > mo; //map dell'ordine
              TipoProdotto* tpp;
              TipoProdotto tps;
              Materiale mt;
                          	
      public:
		//costruttore di default e specifico
		Ordine();
		Ordine(string _IDProdotto, string _IDOrdine, string _IDMateriale);
		Ordine* inserisciOrdine();
		void stampa(Ordine* ordine);
		string get_data();
};

void test_ordine();


#endif
