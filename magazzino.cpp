#include "magazzino.h"
#include "tipoprodotto.h"

Magazzino::Magazzino() {
    IDProdotto = " ";
	quantitaDisponibile = 0;	
}

Magazzino::Magazzino(int _IDP, int qd) {
	IDProdotto = _IDP;
	quantitaDisponibile = qd;	
}

/*void Magazzino::quantitàdisponibile(){
     ifstream file ( "prodotti.csv" );
    ifstream is;
    char linea[100];
    is.open("prodotti.csv", ios::in); 
    
    is.getline(linea, 100); //leggere la linea id intestazione
    string value;
    while ( file.good() )
    {
          getline ( file, value, ',' ); // read a string until next comma: http://www.cplusplus.com/reference/string/getline/
          //cout << string( value, 1, value.length()-2 ); // display value removing the first and the last character from it
          =IDProdotto
    }
    
    is.close(); 
}*/
