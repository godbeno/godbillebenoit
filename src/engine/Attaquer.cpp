#include "Attaquer.h"
#include <iostream>

using namespace engine;


Attaquer::Attaquer (int Attaquantx, int Attaquanty, int Ciblex, int Cibley)
{
   this->attaquantX = Attaquantx;
   this->attaquantY = Attaquanty;
   this->cibleX = Ciblex;
   this->cibleY = Cibley;
}
void Attaquer::appliquer(state::Etat* etat)
{
    degat = etat->attaquer(attaquantX, attaquantY, cibleX, cibleY);
    std::cout << "Fin de l'attaque" << std::endl;
}
state::CaseTerrain* Attaquer::getCaseArrivee(state::Etat* etat)
{
    return etat->getGrille().getCelluleDecor(cibleX, cibleY);
}
void Attaquer::annuler(state::Etat* etat)
{
    etat->getGrille().getCellulePersonnage(cibleX, cibleY)->setPVrestant(etat->getGrille().getCellulePersonnage(cibleX, cibleY)->getPV() + degat);
}