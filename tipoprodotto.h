#ifndef __TIPOPRODOTTO_H__
#define __TIPOPRODOTTO_H__
#include <cstdlib>
#include <iostream>
#include <string>
#include <map>
#include <fstream>

using namespace std;

class TipoProdotto {
	private:
		string id_prodotto;
		string nome; //nome del prodotto
		map <string, string> tp;
		
	public:
		//costruttore di default e specifico
		TipoProdotto();
		TipoProdotto(string _id_prodotto); //costruttore ad un solo parametro da passare ad Ordine.h
		TipoProdotto(string _, string _nome);
		
		string get_idprodotto();
		string get_IDProdotto();
        string get_nome();
		void stampa(TipoProdotto* prodotto);
		TipoProdotto* inserisci_prodotto();
};

void test_prodotto();

#endif
