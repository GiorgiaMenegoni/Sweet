#include "addetto.h"

Addetto::Addetto(){
	username="user1";
	password="pass1";
}

//void Addetto::inizializza_addetto(string _nome, string _cognome, string _nato_il, string _citta){
	//p.inizializza(_nome, _cognome, _nato_il, _citta);
//}

bool Addetto::login(string _username, string _password){
	return ((username==_username)&&(password==_password));
}

bool Addetto::verifica_magazzino(){} //da implementare!!

void Addetto::invia_ordine_produzione(Ordine o){} //da implementare!!

void Addetto::invia_ordine_fornitore(Ordine o){} //da implementare!!

void start(){
	
	Addetto a;
	
	int m=0, n=0, o=0, k=0, x=0, y=0, p=0;

	cout<<"*** SWEET CHOCOLATE FACTORY ***"<<endl;
	
	while(m==0){
        cout<<"Login addetto"<<endl;
        string username, password;
        cout<<"inserire username: ";
        cin>>username;
        cout<<"inserire password: ";
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
	cout<<"4) Registra ordini fornitori"<<endl;
	cout<<"5) Aggiungi prodotto"<<endl;
	cout<<"6) Aggiungi materiale"<< endl;
	cout<<"0) Logout" << endl;
	cout << endl;
	cout<<"Inserire valore: ";
	cin>>m;
	system ("CLS");
	
	do{
		switch(m){
            case 10: {
           	     cout<<"---- MENU' ----"<<endl;
	             cout<<"1) Registra ordine"<<endl;
	             cout<<"2) Stampa lista ordini"<<endl;
	             cout<<"3) Verifica magazzino"<<endl;
	             cout<<"4) Registra ordini fornitori"<<endl;
                 cout<<"5) Stampa lista ordini"<<endl;
	             cout<<"6) Aggiungi prodotto"<<endl;
                 cout<<"7) Aggiungi materiale"<< endl;
                 cout<<"0) Logout" << endl;
	             cout << endl;
	             cout<<"Inserire valore: ";
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
				 cout << "Inserisci valore: ";
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
				        cout << "Inserisci valore: ";  cin>>n;
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
                        cout << "1) Inserisci nuovo cliente" << endl;
                        cout << "2) Ritorna al menu' precedente" << endl;
                        cout<<endl;
                        cout << "Inserisci valore: ";
                        cin >> k;
                        
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
                        Ordine* ordine;
                        ordine=ordine->inserisci_ordine();
                        cout << endl << endl;
                    }break;
                        
                    case 6:{
                        m=10;
                    }break;                    
				}
            }break; // qui finisce lo switch n
			
			case 2:{
            cout << "1) Stampa lista ordini" << endl;
                cout << "2) Ritorna al menu' principale" << endl;
                cout << endl;
                cout << "Inserisci valore: ";
                cin >> p;
                 
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
            
			case 3:{}break;
			case 4:{}break;
						
			case 5:{ // di m
                cout << "1) Inserisci nuovo prodotto" << endl;
                cout << "2) Ritorna al menu' precedente" << endl;
                cout << endl;
                cout << "Inserisci valore: ";  cin >> o;
                 
                switch(o){
                    case 1:{ // di o
                        TipoProdotto* tipoprod;
			            tipoprod=tipoprod->inserisci_prodotto();
                    }break;
                         
                    case 2:{
                        m=10;
                    }break;
                    system ("CLS");
                  }
            }break; // qui finisce il case 6
            
            case 6:{ // di m
                cout << "1) Inserisci nuovo materiale" << endl;
                cout << "2) Ritorna al menu' precedente" << endl;
                cout << endl;
                cout << "Inserisci valore: ";  cin >> x;
                 
                switch(x){
                    case 1:{ // di x
                        Materiale* tipomat;
                        tipomat=tipomat->inserisci_tipo_materiale();
                }break;
                     
                    case 2:{ // di x
                        m=10;
                        cout << endl << endl;
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
