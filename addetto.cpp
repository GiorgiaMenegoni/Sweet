#include "addetto.h"
#include <fstream>
#include <map>

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

bool Addetto::verificaMagazzino(){}

/*void Addetto::inserisciOrdine(Cliente c, Ordine o){
	map_ordine.insert(pair<string,Ordine>(c.get_id(),o));
}*/

void Addetto::inviaOrdineProduzione(Ordine o){}

void Addetto::inviaOrdineFornitore(Ordine o){}

/*void Addetto::stampaRegistroClienti(){
	map<string,Cliente>::iterator msii;
	for(msii=map_cliente.begin();msii!=map_cliente.end();msii++){
		cout<<msii->first<<": "<<msii->second.get_p().get_nome()<<" , "<<msii->second.get_p().get_cognome();
	}
}*/

/*test
void test_addetto(){
	cout<<"TEST ADDETTO"<<endl;

	Cliente* cliente;
	cliente=cliente->inserisciCliente();
	cliente->stampa(cliente);
	
}*/

void start(){
	
	Addetto a;
	Cliente b;
	
	int m=0;
	int n=0;
	int o=0;
	int k=0;
	int x=0;
	int y=0;
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
          }else{
                cout<<"username e/o password non sono stati inseriti correttamente"<<endl;} 
          }
	
	
	cout<<"---- MENU' ----"<<endl;
	cout<<"1) Registra ordine"<<endl;
	cout<<"2) Verifica ordini"<<endl;
	cout<<"3) Verifica magazzino"<<endl;
	cout<<"4) Registra ordini fornitori"<<endl;
	cout<<"5) Esegui statistiche"<<endl;
	cout<<"6) Aggiungi prodotto"<<endl;
	cout<<"7) Aggiungi materiale"<< endl;
	cout << endl;
	cout<<"Inserire valore: ";
	cin>>m;
	system ("CLS");
	
	do{
		switch(m){
            case 10: {
           	     cout<<"---- MENU' ----"<<endl;
	             cout<<"1) Registra ordine"<<endl;
	             cout<<"2) Verifica ordini"<<endl;
	             cout<<"3) Verifica magazzino"<<endl;
	             cout<<"4) Registra ordini fornitori"<<endl;
                 cout<<"5) Esegui statistiche"<<endl;
	             cout<<"6) Aggiungi prodotto"<<endl;
                 cout<<"7) Aggiungi materiale"<< endl;
	             cout << endl;
	             cout<<"Inserire valore: ";
	             cin>>m;
	             system ("CLS");
              }break;
              
			case 1:{
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
				 cout << "Inserisci valore: ";
				 cin>>n;
				 system ("CLS");
                 }break;
				 
                    case 1:{ 
                        ifstream file ( "prodotti.csv" );
                        ifstream is;
                        char linea[100];
                        is.open("prodotti.csv", ios::in);     
                        is.getline(linea, 100); //leggere la linea id intestazione
                        string value;
                        while ( file.good() )
                        {
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
                        cout << "2) Ritorna al menu' principale" << endl;
                        cout<<endl;
                        cout << "Inserisci valore: ";
                        cin >> k;
                        
                        switch(k){
                          case 1:{
                               Cliente* cl;
			                   cl = cl->inserisci_cliente();
			                   cout << endl << endl;
			                   }break;
			                   
                          case 2:{
                              n=10;
                              cout<< endl << endl;
                              }break;
                         }}break;
                         
                    case 5:{
                         
                         }break;
                        
                    case 6:{
                        m=10;
                    }break;
                    
				
			}}break;
			
			case 2:{}break;
			
			case 6:{
                 cout << "1) Inserisci nuovo prodotto" << endl;
                 cout << "2) Ritorna al menu' principale" << endl;
                 cout << endl;
                 cout << "Inserisci valore: ";
                 cin >> o;
                 
                 switch(o){
                          case 1:{
                               TipoProdotto* tipoprod;
			                   tipoprod=tipoprod->inserisciProdotto();
                               }break;
                         case 2:{
                              m=10;
                              
                         }break;
                         system ("CLS");
                  }
            }break;
            
            case 7:{
                 cout << "1) Inserisci nuovo materiale" << endl;
                 cout << "2) Ritorna al menu' principale" << endl;
                 cout << endl;
                 cout << "Inserisci valore: ";
                 cin >> x;
                 
                 switch(x){
                     case 1:{
                        Materiale* tipomat;
                        tipomat=tipomat->inserisciTipoMateriale();
                        }break;
                     
                     case 2:{
                         m=10;
                         cout << endl << endl;
                         }break;
                 }

            }break;            
		}	
	}
while(m!=0);
}
