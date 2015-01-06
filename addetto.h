#ifndef __ADDETTO_H__
#define __ADDETTO_H__
#include <map>
#include <fstream>
#include <string>
#include "persona.h"
#include "addetto.h"
#include "cliente.h"
#include "ordine.h"
#include "tipoprodotto.h"
#include "materiale.h"

using namespace std;

class Addetto{
	private:
		Persona* p;
		string username;
		string password;		
	public:
		Addetto();
		void inizializza_addetto(string _nome, string _cognome, string _nato_il, string _citta);
		bool login(string _username, string _password);
		bool verifica_magazzino();
		void invia_ordine_produzione(Ordine o);
		void invia_ordine_fornitore(Ordine o);	
};

//unico metodo da richiamare nel main - metodo che avvia il programma
void start();

void test_addetto();

#endif
