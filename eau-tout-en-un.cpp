#include <stdexcept>
/** @file **/
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

/** Infrastructure minimale de test **/
#define ASSERT(test) if (!(test)) cout << "Test failed in file " << __FILE__ << " line " << __LINE__ << ": " #test << endl

/** Construction d'un tableau d'entiers lu depuis un fichier
 * On suppose que le fichier contient sur chaque ligne un numéro de mois
 * suivi d'une donnée correspondant au mois.
 * @param nom_fichier, le nom du fichier de données
 * @return un tableau d'entiers de taille 12 tel que dans chaque
 * case d'indice i, on trouve la donnée du mois i
 **/
vector<int> litTableauMois(string nom_fichier) {
    vector<int>t;
    t=vector<int>(12);

      ifstream  fichier(nom_fichier);
      int mois;
      int volume;
      while(fichier>>mois and fichier>>volume){

        t[mois-1]=volume;
      }

    return t;


}

/** Test de la fonction litTableauMois **/
void testLitTableauMois() {
    vector<int> t = litTableauMois("donnees/volumes_d_eau_distribues.txt");
    ASSERT(t[0] == 16231200); // Le volume pour janvier
    ASSERT(t[11] == 15530100); // Le volume pour décembre
    ASSERT(t[4] == 17711200); //Le volume pour mai
}

/** Renvoie la somme d'un tableau d'entiers
 * @param t, un tableau d'entier
 * @return la somme des valeurs
 **/
int somme(vector<int> t) {
    int resultat=0;
    for (int i=0 ; i<t.size();i++){
        resultat=resultat+t[i];
    }
    return resultat;
}

/** Test de la fonction somme **/
void testSomme() {
    ASSERT(somme({1,2,3}) == 6);
    ASSERT(somme({}) == 0);
    ASSERT(somme({2,2,4,8}) == 16);
}

/** Renvoie la moyenne d'un tableau d'entier
 * @param t, un tableau d'entiers
 * @return la moyenne (entière) des valeurs
 **/
int moyenne(vector<int> t) {
    return somme(t)/t.size();


}

/** Test de la fonction moyenne **/
void testMoyenne() {
    ASSERT(moyenne({1,2,3}) == 2);
    ASSERT(moyenne({1}) == 1);
    ASSERT(moyenne({2,2,4,8}) == 4);
}


/** Renvoie l'indice de la valeur maximale du tableau
 * @param t, un tableau d'entier
 * @return l'indice de la valeur maximale ou -1 si le tableau est vide
 **/
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

/** Test de la fonction IndiceMax **/
void testIndiceMax() {
    ASSERT(indiceMax({}) == -1);
    ASSERT(indiceMax({1,2,3}) == 2);
    ASSERT(indiceMax({1,3,2}) == 1);
    ASSERT(indiceMax({1}) == 0);
    ASSERT(indiceMax({2,8,4,4}) == 1);
}

/** Lance les fonctions de test puis affiche :
 * - le volume d'eau total sur l'année
 * - la moyenne par mois
 * - le mois avec le plus gros volume d'eau et son volume
 **/
int main() {

    vector<int> t=litTableauMois("volumes_d_eau_distribues.txt");

    testLitTableauMois() ;
    testSomme();
    testMoyenne();
    testIndiceMax();

    for(int i=0 ; i< t.size(); i++){
        cout << t[i]<<endl;
    }

    int mois= indiceMax(t);
    int eauTotal=somme(t);
    int eauMoyenne= moyenne(t);


    cout<<"le volume d eau total sur l annee est : " << eauTotal <<endl;
    cout<<"la moyenne par mois est de : " << eauMoyenne << endl;
    cout<<"le mois avec le plus gros volume d eau et son volume : " << mois << " ==="  <<  t[mois];






}
