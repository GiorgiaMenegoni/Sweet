#include "materiale.h"

Materiale :: Materiale() {
	IDMateriale = " ";
	tipoMateriale = " ";
}

Materiale::Materiale(string _IDM){
    IDMateriale=_IDM;
}
		
Materiale::Materiale(string _IDM, string tm) {
	IDMateriale = _IDM;
	tipoMateriale = tm;
}

string Materiale:: get_idmateriale() {
               string temp;
               cout << "Inserire ID materiale : ";
               cin >> temp;
               IDMateriale= temp;
			return IDMateriale;
}
	
Materiale* Materiale:: inserisciTipoMateriale(){
     Materiale* mat  = new Materiale();
			string temp1, temp2; //si crea temporaneamente le variabili IDProdotto e Nome
			                     //queste variabili vengono distrutte subito
			cout << "Inserire ID materiale : ";
			cin >> temp1;
			cout << endl;
			cout << "Inserire nome materiale : ";
			cin >> temp2;
			cout << endl;
			mat->mp.insert ( pair <string, string> (temp1, temp2));
            	
            
            ofstream outfile;
            outfile.open("materiali.csv",ios::app);
            outfile << temp1 <<";" <<  temp2 <<endl;
            outfile.close();
            return mat; //ritorna un puntatore ad un Tipoprodotto
}

void Materiale::stampa(Materiale* mat) {
			map <string, string >:: iterator mii;
			for (mii = mat->mp.begin(); mii != mat->mp.end(); mii++ ) {
			cout << "ID : " << mii->first << " nome : " << mii->second << endl;
			}
		}

void test_materiale(){
     cout << "TEST MATERIALE" << endl;
     Materiale* tipomat;
     tipomat=tipomat->inserisciTipoMateriale();
     tipomat->stampa(tipomat);
}
