#ifndef __MATERIALE_H__
#define __MATERIALE_H__
#include <cstdlib>
#include <iostream>
#include <string>
#include <map>

using namespace std;

class Materiale {
	private:
		string IDMateriale;
		string tipoMateriale;
		map<string, string> mp;
		
	public:
		Materiale();
		Materiale(string _IDM, string tm);
		Materiale* inserisciTipoMateriale();
		void stampa(Materiale* mat);
		
};

void test_materiale();

#endif
