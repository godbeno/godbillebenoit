#include "Attaquer.h"

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
    etat->attaquer(attaquantX, attaquantY, cibleX, cibleY);
}
