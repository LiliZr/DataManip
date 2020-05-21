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
     int volumeMax=0;
     //premiere methode

     while(fichier){

      getline(fichier, mois, ';');

      getline(fichier, volume_str);

        if(fichier){
          istringstream(volume_str) >> volume;

          if (volume>volumeMax) volumeMax=volume;
        }
     }
     //deuxieme methode
 /*
     getline(fichier, mois, ';');

     while ( fichier>> volume_str ){
      getline(fichier, mois, ';');
      istringstream(volume_str) >> volume;


      if (volume>volumeMax) volumeMax=volume;




     }
     */
     cout << "le plus gros volume d eau est : " << volumeMax<<endl;

    fichier.close();
    return 0;

}
