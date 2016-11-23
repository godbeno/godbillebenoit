#include "Selection.h"
#include <iostream>
using namespace engine;

Selection::Selection(int Selectionx, int Selectiony)
{
   this->selectionX = Selectionx;
   this->selectionY = Selectiony;
   ancienSelect = nullptr;
}

void Selection::appliquer(state::Etat* etat, bool afficher)
{
    ancienSelect = etat->getSelectionne();
    etat->setSelectionne(selectionX, selectionY, afficher);
}
void Selection::annuler (state::Etat* etat, bool afficher)
{
    etat->setSelectionne(ancienSelect->getX(), ancienSelect->getY(), afficher);
    std::cout << "Fin de l'annulation" << std::endl;
}