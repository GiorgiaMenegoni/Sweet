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
		string username;
		string password;		
	public:
		Addetto();
		~Addetto();
		bool login(string _username, string _password);
			
};

//unico metodo da richiamare nel main - metodo che avvia il programma
void start();

void test_addetto();

#endif
