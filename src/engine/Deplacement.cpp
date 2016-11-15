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

void Deplacement::appliquer(state::Etat* etat)
{
    //int tx = sf::VideoMode::getDesktopMode().height/24.;
    std::cout << "origine : (" << origineX << ", " << origineY << ")" << std::endl;
    std::cout << "direction : (" << cibleX << ", " << cibleY << ")" << std::endl;
    etat->deplacerElement(origineX, origineY, cibleX, cibleY);
}
state::CaseTerrain* Deplacement::getCaseArrivee(state::Etat* etat)
{
    return etat->getGrille().getCelluleDecor(cibleX, cibleY);
}
void Deplacement::annuler (state::Etat* etat)
{
    etat->deplacerElement(cibleX, cibleY, origineX, origineY);
}
int Deplacement::getDistance()
{
    return abs(cibleX-origineX)+abs(cibleY-origineY);
}