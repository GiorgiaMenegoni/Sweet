#ifndef __CLIENTE_H__
#define __CLIENTE_H__

#include "persona.h"
#include <map>

class Cliente{
	private:
		Persona pe;
		Persona* p;
		string idCliente;
		map<string, Persona* > mci;
		map<string, Persona* >:: iterator pos;       
	public:
		Cliente();
		Cliente(string _nome, string _cognome, string _nato_il, string _citta, string _ID);
		Cliente(Cliente* _cl);
		string get_id();
		Cliente* inserisci_cliente();	
		void stampa(Cliente* cl); //stampa solo il cliente appena creato
		void stampa_tutti_clienti();
};

void test_cliente();

#endif
