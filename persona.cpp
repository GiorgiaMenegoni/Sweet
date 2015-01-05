#include "Persona.h"

Persona::Persona(){
	nome=" ";
	cognome=" ";
	nato_il="../../..";
	citta=" ";
}
Persona::Persona(string _nome, string _cognome, string _nato_il, string _citta){
    nome=_nome;
	cognome=_cognome;
	nato_il=_nato_il;
	citta=_citta;
}

string Persona::get_nome(){
	return nome;
}

string Persona::get_cognome(){
	return cognome;
}

string Persona::get_citta(){
	return citta;
}

string Persona::get_data(){
	return nato_il;
}

/*
void Persona::inserisciCognome(string _cognome){
	cognome=_cognome;
}

void Persona::inserisciData(string _data){
	nato_il=_data;
}

void Persona::inserisciCitta(string _citta){
	citta=_citta;
}*/

Persona* Persona::inserisci_persona(){
    Persona* pp = new Persona();
   	cout<<"Inserire il nome: ";
    cin>>pp->nome;
	cout<<"Inserire il cognome: ";
	cin>>pp->cognome;
	cout<<"Inserire la data di nascita: ";
	cin>>pp->nato_il;
	cout<<"Inserire la citta: ";
	cin>>pp->citta;
	return pp;	
}


void Persona::stampa(Persona* p){
     cout << "Nome : " << p->nome << endl;
     cout << "Cognome : " << p->cognome << endl;
     cout << "Nato il : " << p->nato_il << endl;     
     cout << "Citta' : " << p->citta << endl;  
}


void test_persona(){
               Persona* p;
               p = p->inserisci_persona();
               p->stampa(p);
}
