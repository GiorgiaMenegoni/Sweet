#include "tipoprodotto.h"

TipoProdotto::TipoProdotto() {
	id_prodotto = " ";
	nome = " ";
}

//costruttore specifico
TipoProdotto::TipoProdotto(string _IDProdotto) {
	id_prodotto = _IDProdotto;
}		
		
TipoProdotto::TipoProdotto(string _id_prodotto, string _nome) {
	id_prodotto = _id_prodotto;
	nome = _nome;
}

TipoProdotto::~TipoProdotto(){
}

string TipoProdotto:: get_idprodotto() {
    string temp;
    cout << "Inserire ID prodotto : ";
    cin >> temp;
    id_prodotto= temp;
	return id_prodotto;
}
		
string TipoProdotto:: get_nome() {
	return nome;
}

string TipoProdotto:: get_IDProdotto(){
    return id_prodotto;       
}
		
TipoProdotto* TipoProdotto::inserisci_prodotto() {
    TipoProdotto* prodotto  = new TipoProdotto();
	string temp1, temp2; //si crea temporaneamente le variabili IDProdotto e Nome
			            //queste variabili vengono distrutte subito
	temp1= prodotto->get_idprodotto();
	cout << "Inserire nome prodotto : ";
	cin >> temp2;
	cout << endl;
	prodotto->tp.insert ( pair <string, string> (temp1, temp2));
            	
    ofstream outfile;
    outfile.open("prodotti.csv",ios::app);
    outfile << temp1 <<";" <<  temp2 <<endl;
    outfile.close();
    return prodotto; //ritorna un puntatore ad un Tipoprodotto
}
		
void TipoProdotto::stampa(TipoProdotto* prodotto) {
	map <string, string >:: iterator mii;
	for (mii = prodotto->tp.begin(); mii != prodotto->tp.end(); mii++ ) {
		cout << "ID : " << mii->first << " nome : " << mii->second << endl;
	}
}
		
void test_prodotto() {
	cout << "TEST PRODOTTO" << endl;
	TipoProdotto* tipoprod;
	tipoprod=tipoprod->inserisci_prodotto();
	tipoprod->stampa(tipoprod);
}
