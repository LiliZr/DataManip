#include <stdexcept>
/** @file **/
#include <fstream>
#include <iostream>
#include "tableau-donnees.h"
using namespace std;

/** Calcule et affiche l'arrondissement ayant le plus de déchets sur l'année
 * ainsi que son tonnage annuel **/

int main() {
     int tonnage=0;
     int tonnageMax=0;
     ifstream fichier("donnees/tonnages_des_dechets_bacs_jaunes.txt");
     int dep;

     int comCorr, departMax;
     int k=-1;

     while( fichier>>dep ){

            k=k+1;
            if(k==0) {
                comCorr = dep;  // departement
            }if (k!=0){

                if(k<=12){
                   tonnage= tonnage+dep; // calcul le tonnage annuel

                }if(tonnage>tonnageMax) { // compare le tonnage annuel de chaque departement et stocke le max d'entre eux et le departement correspendant
                   tonnageMax=tonnage;
                   departMax = comCorr;

                }if(k%12==0){

                   k=-1;
                   tonnage=0;
                }

            }

     }
     fichier.close();

     cout<< " l arrondissement avec le plus de dechets annuel est "<< departMax <<" avec un taux de : "<< tonnageMax <<endl;
}
