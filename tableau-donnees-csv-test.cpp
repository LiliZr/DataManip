#include <stdexcept>
/** @file **/
#include <iostream>
#include "tableau-donnees-csv.h"
using namespace std;

/** Infrastructure minimale de test **/
#define ASSERT(test) if (!(test)) cout << "Test failed in file " << __FILE__ << " line " << __LINE__ << ": " #test << endl

vector<vector<string>> donnees = {
                    { "avr-11", "15688700" },
                    { "juil-11", "16049700" },
                    { "mars-11", "16260600" },
                    { "juin-11", "17028600" },
                    { "sept-11", "16858200" },
                    { "déc-11", "15530100" },
                    { "févr-11", "14019000" },
                    { "août-11", "13959600" },
                    { "janv-11", "16231200" },
                    { "oct-11", "16592900" },
                    { "nov-11", "15672000" },
                    { "mai-11", "17711200" },
};

vector<vector<string>> petites_donnees = { { "a0", "b0"}, { "a1", "b1" } };

void litTableauCSVTest() {
    ASSERT( litTableauCSV("donnees/volumes_d_eau_distribues.csv", 2) == donnees );
    ASSERT( litTableauCSV("donnees/volumes_d_eau_distribues.csv") == donnees );
}

void colonneTest() {
    ASSERT(colonne(petites_donnees,0) == vector<string> t={"a0","a1"});


void conversionTest() {

    vector<string>s={"212.8","25","236.25"}
    vector<int> t ={212,25,236};
    vector<double>n={218.8,25,236.25}

    ASSERT(conversionInt(s)==t) ;
    ASSERT(conversionDouble(s)==n);
    ASSERT(conversion<int>(s)==t);
    ASSERT(conversion<double>(s)==n);
}

int main() {
    // afficheTableau(litTableauCSV("donnees/volumes_d_eau_distribues.csv", 2));
    // afficheTableau(litTableauCSV("donnees/volumes_d_eau_distribues.csv"));
    cout << "Lancement des tests de litTableauCSV:" << endl;
    litTableauCSVTest();
    cout << "Lancement des tests de conversion:" << endl;
    conversionTest();
}
