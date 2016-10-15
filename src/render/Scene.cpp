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
    for (int i = 0; i < l.size(); i++)
    {
        if (!l.get(i)->estPersonnage())
        {
            coucheTerrain->addTuile(new TuileStatique(l.get(i)->getX()*100, l.get(i)->getY()*100, l.get(i)->getID())); 
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