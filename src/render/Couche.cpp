#include "Couche.h"
#include <iostream>

using namespace render;

Couche::Couche()
{
    tuiles.clear();
}
Tuile* Couche::getTuile (int i, int j)
{
    for (unsigned int k = 0; k < tuiles.size(); k++)
        if (tuiles[k]->getX() == i && tuiles[k]->getY() == j)
            return tuiles[k];
    return nullptr;
}
void Couche::setTuile (int i, int j, Tuile* tuile)
{
    for (unsigned int k = 0; k < tuiles.size(); k++)
        if (tuiles[k]->getX() == i && tuiles[k]->getY() == j)
            tuiles[k] = tuile;
}
void Couche::changementEtat(state::EvenementEtat& e)
{
    if (e.getTypeEvenement() == state::NouveauPersonnage)
    {
        std::cout << "Couche: Nouveau personnage" << std::endl;
    }
}
