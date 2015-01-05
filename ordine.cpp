#include "ordine.h"
#include <fstream>


Ordine::Ordine(): tps() {
		IDOrdine=0;
        tpp=NULL;	
}

Ordine::Ordine(string _IDProdotto, int _IDOrdine): tps( _IDProdotto) {
        IDOrdine = _IDOrdine;
}

Ordine* Ordine::inserisciOrdine(){
        Ordine* ordine =new Ordine();
        string temp1;
        int temp2, temp3;
        temp1= ordine->tps.get_idprodotto();
        
        cout << "Inserisci quantita' desiderata: ";
        cin>> temp2;
        
        ordine->mpq.insert(pair <string, int> (temp1, temp2));
        
        //IDOrdine++;
        //cout << IDOrdine;
        cin >> temp3;
        ordine->VIDOrdine.push_back(temp3);
        ordine->mo.insert(pair<int, map<string,int> > (temp3, ordine->mpq));
        
         ofstream outfile;
         outfile.open("ordini.csv",ios::app);
         outfile << temp3 <<";" <<  temp1 << "; "<< temp2 << endl;
         outfile.close();
        
        return ordine;
}

void Ordine::stampa(Ordine* ordine) {
            map<string,int>:: iterator mpqi;
            vector<int>:: iterator VIDOrdineit;
            //map<string, map<string,int> >::const_iterator moi;
            //moi = ordine->mo.begin();
            
            for(VIDOrdineit = VIDOrdine.begin(); VIDOrdineit!=VIDOrdine.end();VIDOrdineit++){
            cout<< "IDOrdine: " << *VIDOrdineit;
            for(mpqi= ordine->mpq.begin(); mpqi!= ordine->mpq.end(); mpqi++){
                                     cout << "IDProdotti: " << mpqi->first << "Quantita': " <<  mpqi->second;
            }
            }
}

void test_ordine(){
     Ordine* o;
     o=o->inserisciOrdine();
     o->stampa(o);

}
