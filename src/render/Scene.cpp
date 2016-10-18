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
    float tx = sf::VideoMode::getDesktopMode().height/24.;
    for (int i = 0; i < l.size(); i++)
    {
        if (!l.get(i)->estPersonnage())
        {
            coucheTerrain->addTuile(new TuileStatique(l.get(i)->getX()*tx, l.get(i)->getY()*tx, l.get(i)->getID(), tx)); 
        }
        if (l.get(i)->estPersonnage())
        {
            couchePersonnage->addTuile(new TuileStatique(l.get(i)->getX()*tx, l.get(i)->getY()*tx, l.get(i)->getID()+50+10*!(static_cast<state::Personnage*>(l.get(i))->getEquipe()), tx));
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
    couchePersonnage->afficher();
    window->display();
}