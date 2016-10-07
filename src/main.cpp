#include <iostream>
#include "state/Etat.h"
using namespace std;

int main(int argc,char* argv[]) 
{   
    // Test Unitaire - Etat du jeu 
    Etat etat;
    etat.initialiserTerrain();
    etat.ajouterPersonnage(true, 2);

    return 0;
}
