#include "Selection.h"
using namespace engine;

Selection::Selection(int Selectionx, int Selectiony)
{
   this->selectionX = Selectionx;
   this->selectionY = Selectiony;
}

void Selection::appliquer(state::Etat* etat)
{
    etat->setSelectionne(selectionX, selectionY);
}