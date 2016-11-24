#include "Deplacement.h"
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace engine;

Deplacement::Deplacement(int Originex, int Originey, int Ciblex, int Cibley)
{
   this->origineX = Originex;
   this->origineY = Originey;
   this->cibleX = Ciblex;
   this->cibleY = Cibley;
}

void Deplacement::appliquer(state::Etat* etat, bool afficher)
{
    etat->deplacerElement(origineX, origineY, cibleX, cibleY, afficher, false);
}
state::CaseTerrain* Deplacement::getCaseArrivee(state::Etat* etat)
{
    return etat->getGrille().getCelluleDecor(cibleX, cibleY);
}
void Deplacement::annuler (state::Etat* etat, bool afficher)
{
    etat->deplacerElement(cibleX, cibleY, origineX, origineY, afficher, true);
}
int Deplacement::getDistance()
{
    return abs(cibleX-origineX)+abs(cibleY-origineY);
}
void Deplacement::printOrigine()
{
    std::cout << "(" << origineX << ", " << origineY << ")->";
}
void Deplacement::printArrivee()
{
    std::cout << "(" << cibleX << ", " << cibleY << ")";
}