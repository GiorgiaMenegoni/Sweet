#include "addetto.h"

Addetto::Addetto(){
	username="user1";
	password="pass1";
}

bool Addetto::login(string _username, string _password){
	return ((username==_username)&&(password==_password));
}

Addetto:: ~Addetto(){      
}

void start(){
	
	Addetto a;
	
	int m=0, n=0, o=0, k=0, x=0, y=0, p=0, b=0, g=0 , f=0;

	cout<<"*** SWEET CHOCOLATE FACTORY ***"<<endl;
	
	while(m==0){
        cout<<"---- LOGIN ADDETTO ----"<<endl << endl;
        string username, password;
        cout<<"Inserire username: ";
        cin>>username;
        cout<<"Inserire password: ";
        cin>>password;
        if(a.login(username,password)){
            cout<<"login effettuato"<<endl;
            m=1;
            system ("CLS");
        } 
        else{
            cout<<"username e/o password non sono stati inseriti correttamente"<<endl;} 
        }
	
	
	cout<<"---- MENU' ----"<<endl;
	cout<<"1) Registra ordine"<<endl;
	cout<<"2) Stampa lista ordini"<<endl;
	cout<<"3) Verifica magazzino"<<endl;
	cout<<"4) Stampa ordini verso fornitori"<<endl;
	cout<<"5) Aggiungi prodotto"<<endl;
	cout<<"6) Aggiungi materiale"<< endl;
	cout<<"0) Logout" << endl;
	cout << endl;
	cout<<"Inserire valore della scelta: ";
	cin>>m;
	system ("CLS");
	
	do{
		switch(m){
            case 10: {
           	     cout<<"---- MENU' ----"<<endl;
	             cout<<"1) Registra ordine"<<endl;
	             cout<<"2) Stampa lista ordini"<<endl;
	             cout<<"3) Verifica magazzino"<<endl;
	             cout<<"4) Stampa ordini verso fornitori"<<endl;
	             cout<<"5) Aggiungi prodotto"<<endl;
                 cout<<"6) Aggiungi materiale"<< endl;
                 cout<<"0) Logout" << endl;
	             cout << endl;
	             cout<<"Inserire valore della scelta: ";
	             cin>>m;
	             system ("CLS");
              }break;
              
			case 1:{ // di n
                 cout<< " ---- REGISTRA ORDINE ----" << endl;
                 cout<< "1) Visualizza lista prodotti" << endl;
				 cout<< "2) Visualizza lista materiali" << endl;
				 cout<< "3) Visualizza lista clienti" << endl;
				 cout<< "4) Inserisci nuovo cliente" << endl;
				 cout<< "5) Registra ordine" << endl;
				 cout<< "6) Torna al menu' principale" << endl;
				 cout << endl;
				 cout << "Inserisci valore della scelta: ";
				 cin>>n;
				 system ("CLS");
				 
                 switch(n){
                    case 10:{
                        cout<< " ---- REGISTRA ORDINE ----" << endl;
                        cout<< "1) Visualizza lista prodotti" << endl;
				        cout<< "2) Visualizza lista materiali" << endl;
				        cout<< "3) Visualizza lista clienti" << endl;
				        cout<< "4) Inserisci nuovo cliente" << endl;
			            cout<< "5) Registra ordine" << endl;
				        cout<< "6) Torna al menu' principale" << endl;
				        cout << endl;
				        cout << "Inserisci valore della scelta: ";  cin>>n;
				        system ("CLS");
                    }break;
				 
                    case 1:{ 
                        ifstream file ( "prodotti.csv" );
                        ifstream is;
                        char linea[100];
                        is.open("prodotti.csv", ios::in);     
                        is.getline(linea, 100); //leggere la linea id intestazione
                        string value;
                        while ( file.good() ){
                            getline ( file, value, ',' ); // read a string until next comma: http://www.cplusplus.com/reference/string/getline/
                            cout << string( value, 1, value.length()-2 ); // display value removing the first and the last character from it
                        }    
                        is.close();
                        
                        cout << endl << endl << endl;
                                                                    
                    }break;
                               
                    case 2:{
                        ifstream file ( "materiali.csv" );
                        ifstream is;
                        char linea[100];
                        is.open("materiali.csv", ios::in);    
                        is.getline(linea, 100); //leggere la linea id intestazione
                        string value;
                        while ( file.good()){
                               getline ( file, value, ',' ); // read a string until next comma: http://www.cplusplus.com/reference/string/getline/
                               cout << string( value, 1, value.length()-2 ); // display value removing the first and the last character from it
                        }    
                        is.close();
                        
                        cout << endl << endl << endl;
                        
                    }break;
                               
                    case 3:{
                        ifstream file ( "clienti.csv" );//apertura del file
                        ifstream is;
                        char linea[100];
                        is.open("clienti.csv", ios::in);     
                        is.getline(linea, 100); //leggere la linea id intestazione
                        string value;
                        while ( file.good() ){
                            getline ( file, value, ',' ); // read a string until next comma: http://www.cplusplus.com/reference/string/getline/
                            cout << string( value, 1, value.length()-2 ); // display value removing the first and the last character from it
                        }                                   
                        is.close();
                        
                        cout << endl << endl << endl;
                                                                                            
                    }break;
                                
                    case 4:{
                        cout << "---- INSERISCI CLIENTE ----" << endl;
                        cout << "1) Inserisci nuovo cliente" << endl;
                        cout << "2) Ritorna al menu' precedente" << endl;
                        cout<<endl;
                        cout << "Inserisci valore della scelta: ";
                        cin >> k;
                        system ("CLS");
                        
                        switch(k){
                            case 1:{ // di k
                                Cliente* cl;
			                    cl = cl->inserisci_cliente();
			                    cout << endl << endl;
			                    
			                }break;
			                   
                            case 2:{ // di k
                                n=10;
                                cout<< endl << endl;
                            }break;
                         }
                    }break; // qui finisce lo switch k
                         
                    case 5:{
                        cout << "---- INSERISCI ORDINE ----" << endl;
                        cout << "1) Inserisci nuovo ordine" << endl;
                        cout << "2) Ritorna al menu' precedente" << endl;
                        cout<<endl;
                        cout << "Inserisci valore della scelta: ";
                        cin >> b;
                        system("CLS");
                        
                        switch(b){
                            case 1:{ // di b
                                cout << "---- LISTA DEI PRODOTTI ----" << endl;
                                ifstream file ( "prodotti.csv" );
                                ifstream is;
                                char linea[100];
                                is.open("prodotti.csv", ios::in);     
                                is.getline(linea, 100); //leggere la linea id intestazione
                                string value;
                                while ( file.good() ){
                                    getline ( file, value, ',' ); // read a string until next comma: http://www.cplusplus.com/reference/string/getline/
                                    cout << string( value, 1, value.length()-2 ); // display value removing the first and the last character from it
                                }    
                                is.close();
                        
                                cout << endl << endl << endl;
                        
                                cout << "---- LISTA DEI MATERIALI ----" << endl;
                                ifstream files ( "materiali.csv" );//apertura del file
                                ifstream iss;
                                char linea_linea[100];
                                iss.open("materiali.csv", ios::in);     
                                iss.getline(linea_linea, 100); //leggere la linea id intestazione
                                string value_value;
                                while ( files.good() ){
                                      getline ( files, value_value, ',' ); // read a string until next comma: http://www.cplusplus.com/reference/string/getline/
                                      cout << string( value_value, 1, value_value.length()-2 ); // display value removing the first and the last character from it
                                }                                   
                                iss.close();
                        
                                cout << endl << endl << endl;
                                
                                Ordine* ordine;
                                ordine=ordine->inserisci_ordine();
                                cout << endl << endl;
			                }break;
			                   
                            case 2:{ // di b
                                n=10;
                                cout<< endl << endl;
                            }break;
                            }
                    }break;
                        
                    case 6:{
                        m=10;
                    }break;                    
				}
            }break; // qui finisce lo switch n
			
			case 2:{
                cout << "---- STAMPA LISTA ORDINI ----" << endl;
                cout << "1) Stampa lista ordini" << endl;
                cout << "2) Ritorna al menu' principale" << endl;
                cout << endl;
                cout << "Inserisci valore della scelta: ";
                cin >> p;
                system("CLS");
                 
                switch(p){
                    case 1:{ // di p
                        ifstream file ( "ordini.csv" );
                        ifstream is;
                        char linea[100];
                        is.open("ordini.csv", ios::in);    
                        is.getline(linea, 100); //leggere la linea id intestazione
                        string value;
                        while ( file.good()){
                            getline ( file, value, ',' ); // read a string until next comma: http://www.cplusplus.com/reference/string/getline/
                            cout << string( value, 1, value.length()-2 ); // display value removing the first and the last character from it
                        }    
                        is.close();
                        
                        cout << endl << endl << endl;
                    }break;
                               
                    case 2:{ // di p
                        m=10;                              
                    }break;
                    system ("CLS");
                }
            }break;
            
			case 3:{
                cout << "---- VERIFICA MAGAZZINO ----" << endl;
                cout << "1) Stampa il magazzino dei materiali" << endl;
                cout << "2) Stampa il magazzino dei prodotto" << endl;
                cout << "3) Verifica quantita' presente in magazzino" << endl;
                cout << "4) Ritorna al menu' principale" << endl;
                cout<<endl;
                cout << "Inserisci valore della scelta: ";
                cin >>g ;
                system("CLS");
                
                switch(g){
                         case 1:{
                             ifstream file ( "magazzino_materiale.csv" );
                             ifstream is;
                             char linea[100];
                             is.open("magazzino_materiale.csv", ios::in);    
                             is.getline(linea, 100); //leggere la linea id intestazione
                             string value;
                             while ( file.good()){
                             getline ( file, value, ',' ); // read a string until next comma: http://www.cplusplus.com/reference/string/getline/
                             cout << string( value, 1, value.length()-2 ); // display value removing the first and the last character from it
                             }    
                             is.close();
                        
                             cout << endl << endl << endl;
                              
                         }break;
                         
                         case 2:{
                             ifstream file ( "magazzino_prodotti.csv" );
                             ifstream is;
                             char linea[100];
                             is.open("magazzino_prodotti.csv", ios::in);    
                             is.getline(linea, 100); //leggere la linea id intestazione
                             string value;
                             while ( file.good()){
                             getline ( file, value, ',' ); // read a string until next comma: http://www.cplusplus.com/reference/string/getline/
                             cout << string( value, 1, value.length()-2 ); // display value removing the first and the last character from it
                             }    
                             is.close();
                        
                             cout << endl << endl << endl;
                             
                         }break;
                         
                         case 3:{
                              Magazzino n;
                              n.stampa_quantita_disponibile_materiale();
                              cout << endl;
                              n.stampa_quantita_disponibile_prodotto();                           
                              n.trova();
                              
                         }break;
                         
                         case 4:{
                             m=10;
                         }break;                
                }
            }break;
    
			case 4:{
                cout << "---- STAMPA ORDINI VERSO FORNITORI ----" << endl;
                cout << "1) Stampa ordini verso fornitori relativi ai materiali" << endl;
                cout << "2) Stampa ordini verso fornitori relativi ai prodotti" << endl;
                cout << "3) Ritorna al menu' principale" << endl;
                cout << endl;
                cout << "Inserisci valore della scelta: ";  cin >> f;
                system ("CLS");
                
                switch(f){
                    case 1:{
                        ifstream file ( "ordini_verso_fornitore_materiale.csv" );
                        ifstream is;
                        char linea[100];
                        is.open("ordini_verso_fornitore_materiale.csv", ios::in);    
                        is.getline(linea, 100); //leggere la linea id intestazione
                        string value;
                        while ( file.good()){
                        getline ( file, value, ',' ); // read a string until next comma: http://www.cplusplus.com/reference/string/getline/
                        cout << string( value, 1, value.length()-2 ); // display value removing the first and the last character from it
                        }    
                        is.close();
                        
                        cout << endl << endl << endl;
                         
                    }break;
                    
                    case 2:{
                        ifstream file ( "ordini_verso_fornitore_tipo_prodotto.csv" );
                        ifstream is;
                        char linea[100];
                        is.open("ordini_verso_fornitore_tipo_prodotto.csv", ios::in);    
                        is.getline(linea, 100); //leggere la linea id intestazione
                        string value;
                        while ( file.good()){
                        getline ( file, value, ',' ); // read a string until next comma: http://www.cplusplus.com/reference/string/getline/
                        cout << string( value, 1, value.length()-2 ); // display value removing the first and the last character from it
                        }    
                        is.close();
                        
                        cout << endl << endl << endl;
                        
                    }break;
                    
                    case 3:{
                        m=10;
                    }break;                
                }
            }break;
						
			case 5:{ // di m
                cout << "---- INSERISCI NUOVO PRODOTTO ----" << endl;
                cout << "1) Inserisci nuovo prodotto" << endl;
                cout << "2) Ritorna al menu' principale" << endl;
                cout << endl;
                cout << "Inserisci valore della scelta: ";  cin >> o;
                system ("CLS");
                 
                switch(o){
                    case 1:{ // di o
                        TipoProdotto* tipoprod;
			            tipoprod=tipoprod->inserisci_prodotto();
                    }break;
                         
                    case 2:{
                        m=10;
                    }break;
               }
            }break; // qui finisce il case 5
            
            case 6:{ // di m
                cout << "---- INSERISCI NUOVO MATERIALE ----" << endl;
                cout << "1) Inserisci nuovo materiale" << endl;
                cout << "2) Ritorna al menu' principale" << endl;
                cout << endl;
                cout << "Inserisci valore della scelta: ";  cin >> x;
                system ("CLS");
                 
                switch(x){
                    case 1:{ // di x
                        Materiale tipomat;
                        tipomat.inserisci_tipo_materiale();
                }break;
                     
                    case 2:{ // di x
                        m=10;
                    }break;
                 }

            }break; // qui finisce il case 7 di m            
		} // chiude lo switch	
	} // chiude il do
while(m!=0);
}// chiude lo start

void test_addetto(){
	cout<<"TEST ADDETTO"<<endl;

	Cliente* cliente;
	cliente=cliente->inserisci_cliente();
	cliente->stampa(cliente);	
}
