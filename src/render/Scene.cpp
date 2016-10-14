#include "Scene.h"
#include "state/Etat.h"
#include "TuileStatique.h"
#include <iostream>
#include <SFML/Graphics/RenderWindow.hpp>

using namespace render;

Scene::Scene(state::Etat* etat, sf::RenderWindow* window)
{
    coucheTerrain = new Couche(window);
    couchePersonnage = new Couche(window);
    this->etat = etat;
    this->window = window;
    state::ListeElement l = etat->getListe();
    std::cout << "l size : " << l.size();
    for (int i = 0; i < l.size(); i++)
    {
        if (!l.get(i)->estPersonnage())
        {
            std::cout << "+1 couche terrain" << std::endl;
            coucheTerrain->setTuile(l.get(i)->getX(), l.get(i)->getY(), new TuileStatique(l.get(i)->getX()*100, l.get(i)->getY()*100, l.get(i)->getID())); 
        }
        else
        {
            std::cout << "C'est un personnage" << std::endl;
        }
    }
}
void Scene::changementEtat(state::EvenementEtat& e)
{
    if (e.getTypeEvenement() == state::NouveauPersonnage)
    {
        std::cout << "Un nouveau personnage a été créé" << std::endl;
    }
}
void Scene::afficher()
{
    window->clear();
    coucheTerrain->afficher();
    //couchePersonnage->afficher();
    window->display();
}