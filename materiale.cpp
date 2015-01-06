#include "materiale.h"

Materiale :: Materiale() {
	id_materiale = " ";
	tipo_materiale = " ";
}

Materiale::Materiale(string _IDM){
    id_materiale=_IDM;
}
		
Materiale::Materiale(string _IDM, string tm) {
	id_materiale = _IDM;
	tipo_materiale = tm;
}

string Materiale:: get_id_materiale() {
               string temp;
               cout << "Inserire ID materiale : ";
               cin >> temp;
               id_materiale= temp;
			return id_materiale;
}
	
Materiale* Materiale:: inserisci_tipo_materiale(){
    Materiale* mat  = new Materiale();
	string temp1, temp2; //si creano temporaneamente le variabili IDProdotto e Nome
			            //queste variabili vengono distrutte quando viene chiusa la parentesi graffa
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
     tipomat=tipomat->inserisci_tipo_materiale();
     tipomat->stampa(tipomat);
}
