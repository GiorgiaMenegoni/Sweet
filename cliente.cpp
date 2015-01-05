#include "cliente.h"
#include <fstream>
#include <map>

Cliente::Cliente(): pe(){
    p = NULL;
	idCliente="nome_cognome";
}

Cliente::Cliente(string _nome, string _cognome, string _nato_il, string _citta, string _ID): pe(_nome, _cognome, _nato_il, _citta) {
    idCliente = _ID;
}

string Cliente::get_id(){
    /*string temp;
    cout << "Inserire ID cliente : ";
    cin >> temp;
    idCliente = temp;*/
    return idCliente;    
}

Cliente* Cliente::inserisci_cliente(){  
	Cliente* cl = new Cliente();
	string temp;
	Persona* pe;
	cout << "Inserire ID cliente : ";
    cin >> temp;
    pe = cl->p->inserisci_persona();
	//temp = cl->get_id();
    
    cl->mci.insert( pair <string, Persona*> (temp, pe));
    	
     ofstream outfile;
     outfile.open("clienti.csv",ios::app);
     outfile << temp <<";" <<  pe->get_nome() <<";" << pe->get_cognome() << ";" << pe->get_data() << ";" << pe->get_citta() <<endl;
     outfile.close();
     return cl;
}

void Cliente::stampa(Cliente* cl){
     for (cl->pos = cl->mci.begin(); cl->pos!= cl->mci.end(); cl->pos++ ) {
			cout << "ID : " << pos->first << endl;
			cout << "nome: " << pos->second->get_nome() << endl;
			cout << "cognome: " << pos->second->get_cognome() << endl;
			cout << "nato il: " << pos->second->get_data() << endl;
			cout << "citta': " << pos->second->get_citta() << endl;
			}
}

void Cliente::stampa_tutti_clienti(){
     ifstream file ( "clienti.csv" );//apertura del file
     ifstream is;
     char linea[100];
     is.open("clienti.csv", ios::in); 
    
    is.getline(linea, 100); //leggere la linea id intestazione
    string value;
    while ( file.good() )
    {
    getline ( file, value, ',' ); // read a string until next comma: http://www.cplusplus.com/reference/string/getline/
    cout << string( value, 1, value.length()-2 ); // display value removing the first and the last character from it
    }                                   
    is.close();
}
/*    
void test_cliente(){
	cout<<"TEST CLIENTE"<<endl;	
	Cliente* c; // si deve inizializzare in qualche modo
	c = c->inserisci_cliente();
	c->stampa(c);
    //c->stampa_tutti_clienti();
}*/

