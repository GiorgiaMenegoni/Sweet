#ifndef __AZIENDA_H__
#define __AZIENDA_H__

#include "addetto.h"

class Azienda{
	private:
		string nome;
		int p_iva;
	public:
		Azienda();
		~Azienda();
};

void test_azienda();

#endif
