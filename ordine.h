#ifndef __ORDINE_H__
#define __ORDINE_H__
#include <cstdlib>
#include <iostream>
#include <string>
#include <map>
#include "tipoprodotto.h"
#include <vector>

using namespace std;

class Ordine {
      private:
              int IDOrdine;
              map<string,int> mpq;
              map<int, map<string,int> > mo;
              vector<int> VIDOrdine;
              TipoProdotto* tpp;
              TipoProdotto tps;
                          	
      public:
		//costruttore di default e specifico
		Ordine();
		Ordine(string _IDProdotto, int _IDOrdine);
		Ordine* inserisciOrdine();
		void stampa(Ordine* ordine);
};

void test_ordine();


#endif
