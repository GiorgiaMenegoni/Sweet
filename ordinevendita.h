
#ifndef __ORDINEVENDITA_H__
#define __ORDINEVENDITA_H__
#include <cstdlib>
#include <iostream>
using namespace std;

class OrdineVendita {
	private:
		int IDOrdine;
		int IDCliente;
	public:
		OrdineVendita();
		OrdineVendita(int _IDO, int IDC);
		void inserisciOrdine (int _IDO);
		void inserisciIdCliente(int _IDC);	
};


#endif
