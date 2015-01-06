#include "ordine.h"

Ordine::Ordine(): tps(), mt() {
	id_ordine="../../....";
    tpp=NULL;    	
}

Ordine::Ordine(string _IDProdotto, string _IDOrdine, string _IDMateriale): tps( _IDProdotto), mt(_IDMateriale) {
    id_ordine = _IDOrdine;        
}

string Ordine::get_data(){
    string temp;
    cout<< "Inserisci data dell'ordine: ";
    cin>> temp;
    return temp;
}

Ordine* Ordine::inserisci_ordine(){
    Ordine* ordine =new Ordine();
    string temp1, temp3, temp4; // id_prodotto, data, id_materiale
    int temp2, temp5; // quantità di prodotto e materiale da richiedere in input
    
    temp3=ordine->get_data();
    temp1= ordine->tps.get_idprodotto();
    cout << "Inserisci quantita' desiderata del prodotto: ";  cin>> temp2;
    ordine->mpq.insert(pair <string, int> (temp1, temp2));        
    temp4=ordine->mt.get_id_materiale();
    cout << "Inserisci quantita' desiderata del materiale: ";  cin>> temp5;
        
    ordine->mm.insert(pair <string, int> (temp4, temp5));
    ordine->mo.insert(pair<string, map<string,int> > (temp3, ordine->mpq));
    
    Magazzino* mag;
    for(int i=0;i<2; i++){mag->trova();}
        
    ofstream outfile;
    outfile.open("ordini.csv",ios::app);
    outfile << temp3 <<";" <<  temp1 << "; "<< temp2 << ";" <<  temp4 << "; "<< temp5 << endl;
    outfile.close();
        
    return ordine;
}

void Ordine::stampa(Ordine* ordine) {
    map<string,int>:: iterator mpqi;
    multimap<string, map<string,int> >::iterator moi;
    map<string,int>:: iterator mmi;
            
    for(moi=ordine->mo.begin(); moi!=ordine->mo.end(); moi++){
        cout<< "IDOrdine: " << moi->first;
        for(mpqi= ordine->mpq.begin(); mpqi!= ordine->mpq.end(); mpqi++){
            cout << "IDProdotti: " << mpqi->first << "Quantita': " <<  mpqi->second;
        }
        for(mmi= ordine->mm.begin(); mmi!= ordine->mm.end(); mmi++){
            cout << "IDMateriale: " << mmi->first << "Quantita': " <<  mmi->second;
        }
    }
}

void test_ordine(){
     Ordine* o;
     o=o->inserisci_ordine();
     o->stampa(o);  
}
