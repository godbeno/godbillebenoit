#include "Selection.h"
#include <iostream>
using namespace engine;

Selection::Selection(int Selectionx, int Selectiony, bool afficher)
{
   this->selectionX = Selectionx;
   this->selectionY = Selectiony;
   ancienSelect = nullptr;
   this->afficher = afficher;
}

void Selection::appliquer(state::Etat* etat)
{
    ancienSelect = etat->getSelectionne();
    etat->setSelectionne(selectionX, selectionY, afficher);
}
void Selection::annuler (state::Etat* etat)
{
    //std::cout << "Selection->";
    etat->setSelectionne(ancienSelect->getX(), ancienSelect->getY(), afficher);
}