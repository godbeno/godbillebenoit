#include <iostream>
#include "state/Etat.h"
using namespace std;
using namespace state;
int main(int argc,char* argv[]) 
{   
    // Test Unitaire - Etat du jeu 
    Etat etat;

    etat.initialiserTerrain();
    etat.ajouterPersonnage(true, 2);
    

    return 0;
}
