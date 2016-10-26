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
    int tx = sf::VideoMode::getDesktopMode().height/24.;
    std::cout << "origine : (" << origineX << ", " << origineY << ")" << std::endl;
    std::cout << "direction : (" << cibleX/tx << ", " << cibleY/tx << ")" << std::endl;
    etat->deplacerElement(origineX, origineY, (int)cibleX/tx, (int)cibleY/tx);
}