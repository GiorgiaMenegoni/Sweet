#include "magazzino.h"

Magazzino::Magazzino() {
    id_materiale = " ";
	quantita_disponibile_materiale = 0;
	id_prodotto= " ";
	quantita_disponibile_prodotto=0;
}

Magazzino::Magazzino (string _IDM, int _qDM, string _IDP, int _qDP) {
	id_materiale=_IDM;
	quantita_disponibile_materiale=_qDM;
    id_prodotto = _IDP;
	quantita_disponibile_prodotto = _qDP;	
}

void Magazzino::stampa_quantita_disponibile_materiale(){
    ifstream file ( "magazzino_materiale.csv" );
    ifstream is;
    char linea[100];
    is.open("magazzino_materiale.csv", ios::in); 
    
    is.getline(linea, 100); //leggere la linea id intestazione
    string value;
    while ( file.good() )
    {
          getline ( file, value, ',' ); // read a string until next comma: http://www.cplusplus.com/reference/string/getline/
          cout << string( value, 1, value.length()-2 ); // display value removing the first and the last character from it
    }
    
    is.close();  
}

void Magazzino::stampa_quantita_disponibile_prodotto(){
    ifstream file ( "magazzino_prodotti.csv" );
    ifstream is;
    char linea[100];
    is.open("magazzino_prodotti.csv", ios::in); 
    
    is.getline(linea, 100); //leggere la linea id intestazione
    string value;
    while ( file.good() ){
          getline ( file, value, ',' ); // read a string until next comma: http://www.cplusplus.com/reference/string/getline/
          cout << string( value, 1, value.length()-2 ); // display value removing the first and the last character from it
    }
    
    is.close(); 
}

void Magazzino::inserisci_quantita(){
    //Magazzino* mag  = new Magazzino();
	string temp1, temp3; //si crea temporaneamente le variabili IDProdotto e Quantita'
                        //queste variabili vengono distrutte subito
    int temp2, temp4;
    int scelta;            
    cout <<"1)Inserisci nuova quantita' materiale: "<< endl;
    cout <<"2)Inserisci nuova quantita' prodotto: "<< endl;
    cin>>scelta;
            
    switch(scelta){
        case 1:{
            cout << "Inserire IDmateriale : ";
			cin >> temp1;
			cout << "Inserire quantita' materiale : ";
			cin >> temp2;
			cout << endl;
			//mag->mm.insert ( pair <string, int> (temp1, temp2));                      
			ofstream outfile;
            outfile.open("magazzino_materiale.csv",ios::app);
            outfile << temp1 <<";" <<  temp2 <<endl;
            outfile.close();                                   
            //return mag;
        }break;
                                
        case 2:{
            cout << "Inserire IDProdotto : ";
			cin >> temp3;
			cout << "Inserire quantita' prodotto : ";
			cin >> temp4;
			cout << endl;
			//mag->pm.insert ( pair <string, int> (temp3, temp4));
			ofstream outfile;
            outfile.open("magazzino_prodotti.csv",ios::app);
            outfile << temp3 <<";" <<  temp4 <<endl;
            outfile.close();
            //return mag; //ritorna un puntatore ad un Magazzino
        }break;
    }
}

void Magazzino::stampa(){
    map <string, int>::iterator mmi;
    map <string, int>::iterator pmi;
                 
    for(mmi=mm.begin(); mmi!= mm.end(); mmi++){
        cout<<"IDMateriale: "<< mmi->first << " quantita': " << mmi->second << endl;
    }
    for(pmi=pm.begin(); pmi!= pm.end(); pmi++){
        cout<<"IDProdotto: "<< pmi->first << " quantita': " << pmi->second << endl;
    }
}

void Magazzino::lettura_file_magazzino(){     
    ifstream is;
    char linea[100];
    is.open("magazzino_materiale.csv", ios::in);
    is.getline(linea, 100);  
        
    while(!is.getline(linea,100).eof()) { //es.getline mi ritorna una linea intera e un VALORE che viene depositato dentro linea -> gli sto dicendo di copiare finchè non ha finito tutta la linea —-> eof (end of file) copia finchè non è finito il file
        //cout<< linea<< endl; //faccio il parse di linea con strtok
        char* pch; //mi permette di arrivare dove sono arrivata
        pch = strtok(linea, ";"); //ogni volta che arriva al ; salva il valore in una variabile e ricomincia ricordandosi dove è arrivato
        string id_materiale;
        id_materiale=(char*)(pch);
        pch = strtok(NULL, ";"); //NULL perchè non voglio ripartire dall'inizio ma dalla posizione a cui ero arrivato
        int quantita = atoi(pch);                                            
        mm.insert(pair<string, int>(id_materiale, quantita));
        }
    is.close(); //chiudo il file
}

void Magazzino::trova(){
    int temp;
    cout << "1)Cerca chiave materiale: " << endl;
    cout << "2)Cerca chiave prodotto: " << endl;
    cin>> temp;
    
    switch(temp){        
        case 1:{ 
            map <string, int>::iterator mmi;                           
            string temp1;
            cout<< "Inserisci chiave: ";
            cin>>temp1;
            mmi=mm.find(temp1);                           
            if(mmi != mm.end()){
                cout <<"presente" << endl;}
                else{cout<<"assente";}
        }break;
                  
        case 2:{ map <string, int>::iterator pmi;
            string temp1;
            cout<< "Inserisci chiave: ";
            cin>>temp1;
            pmi=pm.find(temp1);
            if(pmi != pm.end()){
            cout <<"presente" << endl;}else{
                cout<<"assente";
            }
        }break;     	     
    }
}

void test_magazzino(){
     Magazzino m;
     
     //m.lettura_file_magazzino();
     //m.stampa();
     
     m.inserisci_quantita();
     //m.Stampa_quantitaDisponibileMateriale();
     //m.Stampa_quantitaDisponibileProdotto();
     //m->quantitadisponibile(); 
     //m.trova();
}


