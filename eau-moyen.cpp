#include <stdexcept>
/** @file **/
#include <fstream>
#include <iostream>
using namespace std;

/** Calcule et affiche le volume d'eau moyen distribué par mois à Paris en 2011 **/
int main() {
    ifstream fichier("volumes_d_eau_distribues.txt");
    int mois ;
    int volume ;
    int resultat=0;
    while ( fichier>> mois and fichier >>volume){
        resultat=resultat+volume;
    }
    fichier.close();
    cout<< "le volume moyen est :" << resultat/12<<endl;
}
