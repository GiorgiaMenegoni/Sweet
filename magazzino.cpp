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
    cout <<"2)Inserisci nuova quantita' prodotto: "<< endl << endl;
    cout <<"Inserisci valore: " ; 
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

void Magazzino::lettura_file_magazzino_materiale(){     
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

void Magazzino::lettura_file_magazzino_prodotto(){     
    ifstream is;
    char linea[100];
    is.open("magazzino_prodotti.csv", ios::in);
    is.getline(linea, 100);  
        
    while(!is.getline(linea,100).eof()) { //es.getline mi ritorna una linea intera e un VALORE che viene depositato dentro linea -> gli sto dicendo di copiare finchè non ha finito tutta la linea —-> eof (end of file) copia finchè non è finito il file
        //cout<< linea<< endl; //faccio il parse di linea con strtok
        char* pch; //mi permette di arrivare dove sono arrivata
        pch = strtok(linea, ";"); //ogni volta che arriva al ; salva il valore in una variabile e ricomincia ricordandosi dove è arrivato
        string id_prodotto;
        id_prodotto=(char*)(pch);
        pch = strtok(NULL, ";"); //NULL perchè non voglio ripartire dall'inizio ma dalla posizione a cui ero arrivato
        int quantita = atoi(pch);                                            
        pm.insert(pair<string, int>(id_prodotto, quantita));
        }
    is.close(); //chiudo il file
}

void Magazzino::trova(){
    int temp;
    cout << endl;
    cout << "---- RICERCA IN MAGAZZINO ----" << endl;
    cout << "1)Cerca IDMateriale" << endl;
    cout << "2)Cerca IDProdotto" << endl ;
    cout << "0)Torna al menu' precedente" << endl << endl;
    cout << "Inserisci valore della scelta: ";
    cin>> temp;
    
    switch(temp){        
        case 1:{
                Magazzino m;
                m.lettura_file_magazzino_materiale();
                map <string, int>::iterator mmi;                           
                string id_materiale;
                cout<< "Inserisci chiave materiale: ";
                cin>>id_materiale;
                
                mmi = m.mm.find(id_materiale);                
                if(mmi != m.mm.end()){
                cout << "Materiale presente in magazzino." << endl;
                cout << "Quantita': " << mmi->second << endl;
                if(mmi->second >=0){
                    int scelta;
                    cout << "---- MODIFICA MAGAZZINO MATERIALE ----" << endl;
                    cout << "1)Invia ordine a fornitore" <<endl; //invio -> incremento quantita' -> decremento
                    cout << "2)Decremento" << endl ; //decremento
                    cout << "0)Torna al menu' precedente" << endl << endl;
                    cout << "Inserisci valore della scelta: ";
                    cin>> scelta;
                                    
                    switch(scelta){
                        case 1 :{
                            int temp;
                            int temp1;
                            cout << "Inserisci quantita' da ordinare: ";
                            cin>>temp;
                            
                            ofstream outfiles;
                            outfiles.open("ordini_verso_fornitore_materiale.csv",ios::app);
                            outfiles << id_materiale <<";" << temp <<endl;
                            outfiles.close();
                            
                            int temp6=mmi->second;
                            int value=temp6+temp;
                            m.mm[id_materiale]=value;
                            cout << "Nuova quantita' in magazzino: " << value << endl;
                            cout << "Quantita' da decrementare: ";
                            cin>>temp1;
                            int newvalue=value-temp1;
                            m.mm[id_materiale]=newvalue;
                            cout << "Quantita' in magazzino: " << newvalue << endl;
                                                          
                            m.mm.erase(mmi);
                            m.mm.insert(pair<string, int>(id_materiale, newvalue));
                                                          
                            remove("magazzino_materiale.csv");
                            
                            ofstream outfile;
                            outfile.open("magazzino_materiale.csv",ios::app);
                            outfile << " IDMateriale" <<";" <<  "quantita" <<endl;
                            outfile.close();
                                                                                        
                            for(mmi = m.mm.begin(); mmi != m.mm.end(); mmi++){
                                ofstream outfile;
                                outfile.open("magazzino_materiale.csv",ios::app);
                                outfile << mmi->first <<";" <<  mmi->second <<endl;
                                outfile.close();
                            }
                        }break;
                                                   
                        case 2:{
                            int temp1;
                            cout << "Quantita' da decrementare: ";
                            cin>>temp1;
                            int temp4=mmi->second;
                            int newvalue=temp4-temp1;
                            m.mm[id_materiale]=newvalue;
                            cout << "Quantita' in magazzino: " << newvalue << endl;
                                                           
                            m.mm.erase(mmi);
                            m.mm.insert(pair<string, int>(id_materiale, newvalue));
                                                          
                            remove("magazzino_materiale.csv");
                            
                            ofstream outfile;
                            outfile.open("magazzino_materiale.csv",ios::app);
                            outfile << " IDMateriale" <<";" <<  "quantita" <<endl;
                            outfile.close();
                                                          
                            for(mmi = m.mm.begin(); mmi != m.mm.end(); mmi++){
                                ofstream outfile;
                                outfile.open("magazzino_materiale.csv",ios::app);
                                outfile << mmi->first <<";" <<  mmi->second <<endl;
                                outfile.close();
                            }
                                                           
                        }break;
                    }
                }
                }
                else{
                     cout<<"Materiale assente in magazzino.";
                     m.inserisci_quantita();                     
                }
        }break;
                  
        case 2:{
                Magazzino ma;
                ma.lettura_file_magazzino_prodotto();
                map <string, int>::iterator pmi;                           
                string id_prodotto;
                cout<< "Inserisci chiave prodotto: ";
                cin>>id_prodotto;
                
                pmi= ma.pm.find(id_prodotto);
                                           
                if(pmi!= ma.pm.end()){
                cout << "Prodotto presente in magazzino." << endl;
                cout << "Quantita': " << pmi->second << endl;
                if(pmi->second >=0){
                    int scelta;
                    cout << "---- MODIFICA MAGAZZINO PRODOTTI ----" << endl;
                    cout << "1)Invia ordine a fornitore" <<endl; //invio -> incremento quantita' -> decremento
                    cout << "2)Decremento" << endl ;//decremento
                    cout << "0)Torna al menu' precedente" << endl << endl;
                    cout << "Inserisci valore della scelta: ";
                    cin>> scelta;
                                    
                    switch(scelta){
                    case 1 :{
                        int temp;
                        int temp1;
                        cout << "Inserisci quantita' da ordinare: ";
                        cin>>temp;
                                                          
                        ofstream outfiles;
                        outfiles.open("ordini_verso_fornitore_tipo_prodotto.csv",ios::app);
                        outfiles << id_prodotto <<";" << temp <<endl;
                        outfiles.close();
                                                          
                        int temp4=pmi->second;
                        int value=temp4+temp;
                        ma.pm[id_prodotto]=value;
                        cout << "Nuova quantita' in magazzino: " << value << endl;
                        cout << "Quantita' da decrementare: ";
                        cin>>temp1;
                        int newvalue=value-temp1;
                        ma.pm[id_prodotto]=newvalue;
                        cout << "Quantita' in magazzino: " << newvalue << endl;
                                                          
                        ma.pm.erase(pmi);
                        ma.pm.insert(pair<string, int>(id_prodotto, newvalue));
                                                          
                        //riscrittura su file .csv
                        remove("magazzino_prodotti.csv");
                                                          
                        //scrittura della prima linea
                        ofstream outfile;
                        outfile.open("magazzino_prodotti.csv",ios::app);
                        outfile << " IDProdotti" <<";" <<  "quantita" <<endl;
                        outfile.close();
                                                          
                        for(pmi = ma.pm.begin(); pmi != ma.pm.end(); pmi++){
                            ofstream outfile;
                            outfile.open("magazzino_prodotti.csv",ios::app);
                            outfile << pmi->first <<";" <<  pmi->second <<endl;
                            outfile.close();
                            }                                                 
                        }break;
                                                   
                        case 2:{
                            int temp1;
                            cout << "Quantita' da decrementare: ";
                            cin>>temp1;
                            int temp4=pmi->second;
                            int newvalue=temp4-temp1;
                            ma.pm[id_prodotto]=newvalue;
                            cout << "Quantita' in magazzino: " << newvalue << endl;
                                                           
                            ma.pm.erase(pmi);
                            ma.pm.insert(pair<string, int>(id_prodotto, newvalue));
                                                          
                            //riscrittura su file .csv
                            remove("magazzino_prodotti.csv");
                                                          
                            ofstream outfile;
                            outfile.open("magazzino_prodotti.csv",ios::app);
                            outfile << " IDProdotti" <<";" <<  "quantita'" <<endl;
                            outfile.close();
                                                          
                            for(pmi = ma.pm.begin(); pmi != ma.pm.end(); pmi++){
                                ofstream outfile;
                                outfile.open("magazzino_prodotti.csv",ios::app);
                                outfile << pmi->first <<";" <<  pmi->second <<endl;
                                outfile.close();
                                } 
                                                            
                        }break;
                    }
                }
                }
                else{
                     cout<<"Prodotto assente in magazzino." << endl;
                     ma.inserisci_quantita();                     
                }
        }break;     	     
    }
}

void test_magazzino(){
     cout<<"TEST MAGAZZINO"<<endl;
     Magazzino m;
     m.trova();
     m.lettura_file_magazzino();
     m.stampa();
     
     m.inserisci_quantita();
     m.Stampa_quantitaDisponibileMateriale();
     m.Stampa_quantitaDisponibileProdotto();
     m.quantitadisponibile();   
}
