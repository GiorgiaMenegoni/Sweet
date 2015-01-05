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
		string IDProdotto;
		string nome; //nome del prodotto
		map <string, string> tp;
		
	public:
		//costruttore di default e specifico
		TipoProdotto();
		TipoProdotto(string _IDProdotto); //costruttore ad un solo parametro da passare ad Ordine.h
		TipoProdotto(string _IDProdotto, string _nome);
		
		string get_idprodotto();
		string get_IDProdotto();
        string get_nome();
		void stampa(TipoProdotto* prodotto);
		TipoProdotto* inserisciProdotto();	
};

void test_prodotto();

#endif
