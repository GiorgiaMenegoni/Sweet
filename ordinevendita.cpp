
#include "ordinevendita.h"

OrdineVendita::OrdineVendita() {
	IDOrdine = 0;
	IDCliente = 0;
}

OrdineVendita::OrdineVendita(int _IDO, int _IDC) {
	IDOrdine = _IDO;
	IDCliente = _IDC;
}
