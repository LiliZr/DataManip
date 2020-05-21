#include <stdexcept>
/** @file **/
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include "tableau-donnees-csv.h"
#include "tableau-donnees.h"
using namespace std;

int main(){
    vector<vector<string>> t =litTableauCSV("donnees/tonnages_des_dechets_bacs_jaunes.csv");
    vector<int> v ;
    vector<int> p ;
    int indice;

    cout << "le tonnage annuel de chaque arrondissement est : " << endl;
    v= vector<int> (t.size()) ;
    for (int i=0 ; i< t.size() ; i++){
        if(i!=13){

            p=conversionInt(t[i]);
            v[i]=sommePartielle(p,1);

        }else{
            v[i]=0;
        }



    }for (int i=0 ; i< v.size() ; i++){
            if(i!= 13)
            cout<< t[i][0] << "   " << v[i] << endl;
    }

    indice=indiceMax(v);

    cout << "l arrondissement avec le plus dechets annuels est le : " << t[indice][0] << " avec un taux de : " << v[indice]<< endl;






}
