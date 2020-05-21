#include <stdexcept>
/** @file **/
#include <fstream>
#include <iostream>
using namespace std;


/** Calcule et affiche le volume d'eau total distribué à Paris en 2011 **/
int main() {



ifstream fichier("donnees/volumes_d_eau_distribues.txt");
    int mois;
    int volume;
    int resultat=0;


    while( fichier >> mois and fichier>>volume ){
        resultat=resultat+volume;
    }

    fichier.close();

    cout<<"Le volume total d eau distribue a Paris en 2011 est : "<< resultat <<endl;



}
