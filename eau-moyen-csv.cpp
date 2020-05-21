#include <stdexcept>
/** @file **/
#include <fstream>
#include <iostream>
#include <sstream>
using namespace std;

int main() {
         ifstream fichier("donnees/volumes_d_eau_distribues.csv");
     string entete;
     getline(fichier, entete);


     string mois;
     string volume_str;
     int volume;
     int volumeTotal=0;
     //premiere methode
     while(fichier){

       getline(fichier, mois, ';');

       getline(fichier, volume_str);

       if(fichier){
        istringstream(volume_str) >> volume;

        volumeTotal=volumeTotal+volume;
       }
    }
     //deuxieme methode
     /*
     getline(fichier, mois, ';');

     while ( fichier>> volume_str ){
      getline(fichier, mois, ';');
      istringstream(volume_str) >> volume;


      volumeTotal=volumeTotal+volume;

     }
     */


     cout << "le volume moyen d eau est : " << volumeTotal/12<<endl;

    fichier.close();
    return 0;
}
