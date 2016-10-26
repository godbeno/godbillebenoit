#include "DeplacementCamera.h"

using namespace engine;

DeplacementCamera::DeplacementCamera(int originex, int originey, int ciblex, int cibley)
{
   this->originex = originex;
   this->originey = originey;
   this->ciblex = ciblex;
   this->cibley = cibley;
}

void DeplacementCamera::appliquer(state::Etat* etat)
{
    etat->setCamerax(ciblex);
    etat->setCameray(cibley);
}
