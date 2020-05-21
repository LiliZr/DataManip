#include <stdexcept>
/** @file **/
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include "tableau-donnees-csv.h"
#include "tableau-donnees.h"
using namespace std;



int main() {
    vector<vector<string>> v =litTableauCSV("donnees/arbresremarquablesparis2011.csv");
    vector<string> s = colonne ( v, 6);
    vector<int> d = conversionInt(s);
    int indice = indiceMax(d);

    vector<string> s1 = colonne ( v, 5);
    vector<int> d1 = conversionInt(s1);
    for (int i=0 ; i< d1.size() ; i++){

        if (d1[i]!=0) d1[i]=2018-d1[i];

    }
    int indice1 = indiceMax(d1);

    cout << "le genre de l arbre le plus haut de paris est : " << v[indice][2] << " de l espece des " << v[indice][3] << endl;
    cout << endl;
    cout << "le genre de l arbre le plus vieux de paris est : " << v[indice1][2] << " de l espece des " << v[indice1][3] << endl;
    cout << endl;


}
