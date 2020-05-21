#include <stdexcept>
/** @file **/
#include <fstream>
#include <iostream>
#include "tableau-donnees.h"
using namespace std;

/** Renvoie le tableau des dechets annuels par arrondissement
 * @param t un double tableau contenant sur chaque ligne l'arrondissement
 * suivi du tonnage des déchets par mois
 * @return un tableau ou chaque case i contient les déchets annuels
 * de l'arrondissement correspondant dans t
 **/
vector<int> dechetsAnnuels(vector<vector<int>> t) {
    vector<int> r;
    for(int i=0; i<t.size(); i++) {
        r.push_back(sommePartielle(t[i],1));
    }
    return r;
}


/**
 * Demande à l'utilisateur un mois et calcule et affiche
 * - la somme des déchets pour le mois
 * - la moyenne par arrondissement pour le mois
 * - l'arrondissement avec le plus de déchets pour le mois (et son tonnage)
 * Puis, affiche pour l'année :
 * - la somme totale des dechets annuels
 * - la moyenne par arrondissement pour l'année
 * - l'arrondissement avec le plus de déchets pour l'année (et son tonnage annuel)
 **/
int main() {
    vector<vector<int>> t = litTableauInt("donnees/tonnages_des_dechets_bacs_jaunes.txt", 13);

    int mois;


    cout << " entrez un numero de mois entre 1 et 12 : " << endl;
    cin >> mois ;

    vector<int>v=colonne(t , mois);

    cout << "La somme des dechets pour ce mois est de : " << somme(v) << endl;
    cout << "La moyenne des dechets pour ce mois est de : "<< moyenne(v) << endl;
    cout <<"L'arrondissement avec le plus de dechets pour ce mois est : " << t[indiceMax(v)][0] << " avec " << v[indiceMax(v)] <<" tonnes de dechets." <<endl;
    cout<<endl;

    vector<int> r=dechetsAnnuels(t);

    cout <<"La somme des dechets annuel est de : " << somme(r) << endl;
    cout <<"La moyenne des dechets pour l'annee est de : " << moyenne(r) << endl;
    cout <<"L'arrondissement avec le plus de dechets l'annee est : " << t[indiceMax(r)][0] << " avec " << r[indiceMax(r)] << "tonnes de dechets." <<endl;

}
