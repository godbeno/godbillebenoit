#include "Deplacement.h"
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
    etat->deplacerElement(origineX, origineY, cibleX, cibleY);
}