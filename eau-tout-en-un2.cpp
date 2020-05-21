#include <stdexcept>
/** @file **/
#include <fstream>
#include <iostream>
#include "tableau-donnees.h"
using namespace std;

/** Affiche
 * - le volume d'eau total sur l'année
 * - la moyenne par mois
 * - le mois avec le plus gros volume d'eau et son volume
 **/
int main() {
    vector<vector<int>>t =litTableauInt("donnees/volumes_d_eau_distribues.txt");
    vector<int>v = colonne(t ,1);

    cout <<"le volume d eau total sur l annee est de : " << somme(v) <<endl;
    cout <<"la moyenne par mois est de : " << moyenne(v) << endl;
    cout <<"le mois avec le plus gros volume d eau est : " << t [indiceMax(v)][0] <<  " avec un volume de : " << v[indiceMax(v)] << endl;
}
