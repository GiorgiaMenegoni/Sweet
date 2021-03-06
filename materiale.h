#ifndef __MATERIALE_H__
#define __MATERIALE_H__
#include <cstdlib>
#include <iostream>
#include <string>
#include <map>
#include "tipoprodotto.h"
#include <fstream>

using namespace std;

class Materiale {
	private:
		string id_materiale;
		string tipo_materiale;
		map<string, string> mp;
		
	public:
		Materiale();
		Materiale(string _IDM);
		Materiale(string _IDM, string tm);
		~Materiale();
		void inserisci_tipo_materiale();
		void stampa();
		string get_id_materiale();
        void lettura_file_materiali();		
};

void test_materiale();

#endif
