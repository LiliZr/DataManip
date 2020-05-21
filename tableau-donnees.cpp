#include <stdexcept>
/** @file **/
#include <fstream>
#include "tableau-donnees.h"

int moyenne(vector<int> t) {
    int resultat=0;
    for (int i=0 ; i<t.size();i++){
        resultat=resultat+t[i];
    }
    return resultat/t.size();
}

int somme(vector<int> t) {
    int resultat=0;
    for (int i=0 ; i<t.size();i++){
        resultat=resultat+t[i];
    }
    return resultat;
}

int sommePartielle(vector<int> t, int i) {
    int resultat=t[i];
    while(i<t.size()){
        i=i+1;
        resultat=resultat+t[i];
    }
    return resultat;
}


int indiceMax(vector<int> t) {
    int a=0;
    if(t.size()==0) return -1;

    for(int i =1;i<t.size();i++){
                if(t[i]>t[a]){
                    a=i;

                }

    }
    return a;
}

vector<vector<int>> litTableauInt(string nom_fichier, int nb_colonnes) {

    vector<vector<int>>t;

    int c=-1;
    int l=0;

    ifstream fichier( nom_fichier);
    int n;

    while( fichier>> n ){
            c=c+1;
            if (c==0){
                t.push_back(vector<int>(nb_colonnes));
            }
            if(c<nb_colonnes){
                   t[l][c]=n;

            }
            if(c!=0 and c%(nb_colonnes-1)==0 ){

                   c=-1;
                   l=l+1;

            }

    }


    fichier.close();
    return t;
}

vector<int> colonne(vector<vector<int>> t, int j) {
     vector<int>v;
    int c=t.size();
    v=vector<int>(c);

    for (int i=0 ; i< t.size() ; i++){
            v[i]=t[i][j];

    }
    return v;
}
