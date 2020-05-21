#include <stdexcept>
/** @file **/
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

/** Infrastructure minimale de test **/
#define ASSERT(test) if (!(test)) cout << "Test failed in file " << __FILE__ << " line " << __LINE__ << ": " #test << endl


/** Construction d'un tableau 2D d'entiers lu depuis un fichier
 * @param fichier le nom d'un fichier contenant un nombre fixe
  * d'entiers par lignes, séparés par des espaces
 * @param nb_colonnes le nombre de colonnes du fichier
 * @return un tableau d'entiers à deux dimensions
 **/
vector<vector<int>> litTableauInt(string nom_fichier, int nb_colonnes) {

    vector<vector<int>>t;

    int c=-1;
    int l=0;

    ifstream fichier( nom_fichier);
    int n;

    while( fichier>> n ){
            c=c+1;
            if (c==0){
                t.push_back(vector<int>(nb_colonnes)); // crée une ligne du tableau
            }
            if(c<nb_colonnes){
                   t[l][c]=n;

            }
            if(c!=0 and c%(nb_colonnes-1)==0 ){

                   c=-1;    // remet le nombre de colonne à 0 au debut
                   l=l+1;   // avance d'une ligne

            }

    }


    fichier.close();
    return t;
}



/** Test de la fonction litTableauInt **/
void testLitTableauInt() {
    vector<vector<int>> t = litTableauInt("donnees/tonnages_des_dechets_bacs_jaunes.txt", 13);
    ASSERT(t[0][0] == 75007);
    ASSERT(t[3][5] == 876);
    ASSERT(t[19][12] == 235);
}


/** Extraction d'une colonne d'un tableau d'entiers
 * @param t un tableau 2D d'entiers
 * @param i un numéro de colonne
 * @return la colonne j, représentée par un vecteur d'entiers
 **/
vector<int> colonne(vector<vector<int>> t, int j) {
    vector<int>v;
    int c=t.size();
    v=vector<int>(c);

    for (int i=0 ; i< t.size() ; i++){
            v[i]=t[i][j];     // parcourt la colonne du tableau 2D et la stock dans le tableau 1D

    }
    return v;

}

/** Test de la fonction colonne **/
void testColonne() {
    vector<vector<int>> t = {{1,2,3},{4,5,6},{7,8,9},{10,11,12}};
    ASSERT( colonne(t,0) == vector<int>({1,4,7,10}));
    ASSERT( colonne(t,1) == vector<int>({2,5,8,11}));
    ASSERT( colonne(t,2) == vector<int>({3,6,9,12}));
}

/** copier la fonction somme déjà écrite **/
int somme(vector<int> t) {
    int resultat=0;
    for (int i=0 ; i<t.size();i++){
        resultat=resultat+t[i];
    }
    return resultat;
}

/** copier la fonction moyenne déjà écrite **/
int moyenne(vector<int> t) {
    return somme(t)/t.size();
}

/** copier la fonction indiceMax déjà écrite **/
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

/** Lance les tests de litTableauInt et colonne
 * puis demande à l'utilisateur un mois et calcule et affiche
 * - la somme des déchets pour le mois
 * - la moyenne par arrondissement pour le mois
 * - l'arrondissement avec le plus de déchets pour le mois (et son tonnage)
 **/
int main() {
    testLitTableauInt();
    testColonne();


    vector<vector<int>> t = litTableauInt("donnees/tonnages_des_dechets_bacs_jaunes.txt", 13);

    int mois;


    cout << " entrez un numero de mois entre 1 et 12 : " << endl;
    cin >> mois ;

    vector<int>v=colonne(t , mois);

    cout<< "La somme des dechets pour ce mois est de : " << somme(v) << endl;
    cout << "La moyenne des dechets pour ce mois est de : "<< moyenne(v) << endl;
    cout<<"L'arrondissement avec le plus de dechets pour ce mois est : " << t[indiceMax(v)][0] << " avec " << v[indiceMax(v)] <<" tonnes de dechets." <<endl;



}
