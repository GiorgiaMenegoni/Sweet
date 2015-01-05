#include "rigaordine.h"

RigaOrdine::RigaOrdine() {
	IDOrdine = 0;
	IDProdotto = 0;
}
RigaOrdine::RigaOrdine(int _IDO, int _IDP) {
	IDOrdine = _IDO;
	IDProdotto = _IDP; //faccio così o passo un (TipoProdotto& tp) ??
}
