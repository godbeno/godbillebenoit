#include "Couche.h"
#include "TuileStatique.h"
#include <iostream>

using namespace render;

Couche::Couche(sf::RenderWindow* window)
{
    tuiles.clear();
    this->window = window;
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
void Couche::addTuile(Tuile* tuile)
{
    tuiles.push_back(tuile);
}
void Couche::changementEtat(state::EvenementEtat& e)
{
    if (e.getTypeEvenement() == state::NouveauPersonnage)
    {
        std::cout << "Couche: Nouveau personnage" << std::endl;
    }
}
void Couche::afficher()
{
    //std::cout << "TUILES SIZE : " << tuiles.size() << std::endl;
    //TuileStatique tuile(50,50,0);
    for (unsigned int i = 0; i < tuiles.size(); i++)
    {
        if (!tuiles[i]->estAnime())
        {
            window->draw(static_cast<TuileStatique*>(tuiles[i])->getSprite());
            //window->draw(tuile.getSprite());
        }
    }
}