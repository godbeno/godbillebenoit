#include "Scene.h"
#include "state/Etat.h"
#include "TuileStatique.h"
#include "TuileAnimee.h"
#include <iostream>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Audio.hpp>

using namespace render;

Scene::Scene(state::Etat* etat, sf::RenderWindow* window)
{
    coucheTerrain = new Couche(window);
    couchePersonnage = new Couche(window);
    tx = sf::VideoMode::getDesktopMode().height/24.;
    couchePersonnage->addTuile(new TuileAnimee(tx*15, tx*15, 0, 36, couchePersonnage));
    this->etat = etat;
    this->window = window;
    state::ListeElement l = etat->getListe();
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
Scene::~Scene()
{
    delete couchePersonnage;
    delete coucheTerrain;
}
void Scene::changementEtat(state::EvenementEtat& e)
{
    if (e.getTypeEvenement() == state::NouveauPersonnage)
    {
        std::cout << "Un nouveau personnage a été créé (" << e.getPid() << ")" << std::endl;
        couchePersonnage->addTuile(new TuileStatique(e.getX()*tx, e.getY()*tx,e.getPid(), tx));
    }
    else if (e.getTypeEvenement() == state::PersonnageDeplace)
    {
        std::cout << "Un personnage a été déplacé" << std::endl;
        //On récupère l'ID de ce personnage
        if (couchePersonnage->getTuile(e.getX()*tx, e.getY()*tx) != nullptr)
        {
            couchePersonnage->setTuile(e.getX()*tx, e.getY()*tx, new TuileStatique(e.getNewx()*tx, e.getNewy()*tx, e.getPid(), tx));
            std::cout << "FIN" << std::endl;
        }
        else
            std::cout << "Null ptr" << std::endl;
    }
}
void Scene::afficher()
{
    window->clear();
    coucheTerrain->afficher();
    couchePersonnage->afficher();
    window->display();
}
