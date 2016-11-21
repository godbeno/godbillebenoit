#include "DeplacementCamera.h"
#include <iostream>

using namespace engine;

DeplacementCamera::DeplacementCamera(int originex, int originey, int ciblex, int cibley)
{
   this->originex = originex;
   this->originey = originey;
   this->ciblex = ciblex;
   this->cibley = cibley;
}

void DeplacementCamera::appliquer(state::Etat* etat, bool afficher)
{
    etat->setCamerax(ciblex, afficher);
    etat->setCameray(cibley, afficher);
}
void DeplacementCamera::annuler (state::Etat* etat, bool afficher)
{
    etat->setCamerax(originex, afficher);
    etat->setCameray(originey, afficher);
}