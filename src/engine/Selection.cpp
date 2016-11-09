#include "Selection.h"
using namespace engine;

Selection::Selection(int Selectionx, int Selectiony)
{
   this->selectionX = Selectionx;
   this->selectionY = Selectiony;
   ancienSelect = nullptr;
}

void Selection::appliquer(state::Etat* etat)
{
    ancienSelect = etat->getSelectionne();
    etat->setSelectionne(selectionX, selectionY);
}
void Selection::annuler (state::Etat* etat)
{
    etat->setSelectionne(ancienSelect->getX(), ancienSelect->getY());
}