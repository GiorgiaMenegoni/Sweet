#ifndef __PERSONA_H__
#define __PERSONA_H__

#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

class Persona{
	private:
		string nome;
		string cognome;
		string nato_il;
		string citta;
	public:
		Persona();
		Persona(string _nome, string _cognome, string _nato_il, string _citta);
		Persona* inserisci_persona();
		void stampa(Persona* p);
		string get_nome();
		string get_cognome();
		string get_data();
		string get_citta();		
};

void test_persona();

#endif
