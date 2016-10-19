#include "Couche.h"
#include "TuileStatique.h"
#include "TuileAnimee.h"
#include <iostream>

using namespace render;

Couche::Couche(sf::RenderWindow* window)
{
    tuiles.clear();
    this->window = window;
}
Couche::~Couche()
{
    for (unsigned int i = 0; i < tuiles.size(); i++)
        delete tuiles[i];
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
        {
            delete tuiles[k];
            tuiles.erase(tuiles.begin()+k);
        }
    tuiles.push_back(tuile);
    
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
    clock_t t;
    for (unsigned int i = 0; i < tuiles.size(); i++)
    {
        if (tuiles[i]->estAnime())
        {
            t = clock();
            static_cast<TuileAnimee*>(tuiles[i])->update(t);
        }
        window->draw(tuiles[i]->getSprite());
    }
}