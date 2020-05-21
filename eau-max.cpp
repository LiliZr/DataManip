#include <stdexcept>
/** @file **/
#include <fstream>
#include <iostream>
using namespace std;

/** Calcule et affiche le mois et le voume où le volume d'eau
* distribué à Paris en 2011 a été maximal **/
int main() {
    ifstream fichier("donnees/volumes_d_eau_distribues.txt");
    int mois;
    int volume;
    int volumeMax=0;
    int moisCorrespondant;
    while( fichier>>mois and fichier>>volume){
            if (volume>volumeMax){
                volumeMax=volume;
                moisCorrespondant=mois;
            }
    }
    fichier.close();
    cout<<"le mois dont le volume est le plus important est le  : "<< moisCorrespondant<<endl;
}
