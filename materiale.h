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
		string IDMateriale;
		string tipoMateriale;
		map<string, string> mp;
		
	public:
		Materiale();
		Materiale(string _IDM);
		Materiale(string _IDM, string tm);
		Materiale* inserisciTipoMateriale();
		void stampa(Materiale* mat);
		string get_idmateriale();		
};

void test_materiale();

#endif
