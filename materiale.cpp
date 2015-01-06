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
	
void Materiale:: inserisci_tipo_materiale(){
	string temp1, temp2; //si creano temporaneamente le variabili IDProdotto e Nome
			            //queste variabili vengono distrutte quando viene chiusa la parentesi graffa
	cout << "Inserire ID materiale : ";
	cin >> temp1;
	cout << endl;
	cout << "Inserire nome materiale : ";
	cin >> temp2;
	cout << endl;
	//mat->mp.insert ( pair <string, string> (temp1, temp2));            	
            
    ofstream outfile;
    outfile.open("materiali.csv",ios::app);
    outfile << temp1 <<";" <<  temp2 <<endl;
    outfile.close();
}

void Materiale::stampa() {
    lettura_file_materiali();
	map <string, string >:: iterator mii;
	for (mii = mp.begin(); mii != mp.end(); mii++ ) {
		cout << "ID : " << mii->first << " nome : " << mii->second << endl;
	}
}

void Materiale::lettura_file_materiali(){
     ifstream is;
     char linea[100];
     is.open("materiali.csv", ios::in);
     is.getline(linea, 100);  
        
     while(!is.getline(linea,100).eof()) { //es.getline mi ritorna una linea intera e un VALORE che viene depositato dentro linea -> gli sto dicendo di copiare finchè non ha finito tutta la linea —-> eof (end of file) copia finchè non è finito il file
        //cout<< linea<< endl; //faccio il parse di linea con strtok
        char* pch; //mi permette di arrivare dove sono arrivata
        pch = strtok(linea, ";"); //ogni volta che arriva al ; salva il valore in una variabile e ricomincia ricordandosi dove è arrivato
        string id_materiale;
        id_materiale=(char*)(pch);
        pch = strtok(NULL, ";"); //NULL perchè non voglio ripartire dall'inizio ma dalla posizione a cui ero arrivato
        string nome;
        nome=(char*) pch;                                            
        mp.insert(pair<string, string>(id_materiale, nome));
        }
        is.close();
     
}

void test_materiale(){
     cout << "TEST MATERIALE" << endl;
     Materiale tipomat;
     tipomat.inserisci_tipo_materiale();
     tipomat.stampa();
}
