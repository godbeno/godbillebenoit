#include "PlacementTroupe.h"
#include <iostream>

using namespace engine; 

PlacementTroupe::PlacementTroupe(int x, int y,int id)
{
	this->x = x;
	this->y = y;
	this->id = id;
}
void PlacementTroupe::appliquer(state::Etat* etat)
{
    etat->ajouterPersonnage(etat->getTour(), id, x, y, true);
}
