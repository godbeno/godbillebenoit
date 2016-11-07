#include "Scene.h"
#include "state/Etat.h"
#include "TuileStatique.h"
#include "TuileAnimee.h"
#include <iostream>
#include "Panneau.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Audio.hpp>

using namespace render;

Scene::Scene(state::Etat* etat, sf::RenderWindow* window)
{
    coucheTerrain = new Couche(window);
    couchePersonnage = new Couche(window);
    panneau = new Panneau();
    this->zoom = 1;    
    tx = (sf::VideoMode::getDesktopMode().width*zoom)/24.;
    //couchePersonnage->addTuile(new TuileAnimee(tx*15, tx*15, 0, 36, couchePersonnage));
    this->etat = etat;
    this->window = window;
    this->camerax = 0;
    this->cameray = 0;
    state::ListeElement l = etat->getListe();
    for (int i = 0; i < l.size(); i++)
    {
        if (!l.get(i)->estPersonnage() )
        {
            coucheTerrain->addTuile(new TuileStatique((l.get(i)->getX()-camerax)*tx, (l.get(i)->getY()-cameray)*tx, l.get(i)->getID(), tx)); 
        }
        if (l.get(i)->estPersonnage())
        {
            couchePersonnage->addTuile(new TuileStatique((l.get(i)->getX()-camerax)*tx, (l.get(i)->getY()-cameray)*tx, l.get(i)->getID()+50+10*!(static_cast<state::Personnage*>(l.get(i))->getEquipe()), tx));
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
        couchePersonnage->addTuile(new TuileStatique((e.getX()-camerax)*tx, (e.getY()-cameray)*tx,e.getPid(), tx));
    }
    else if (e.getTypeEvenement() == state::PersonnageDeplace)
    {
        std::cout << "Un personnage va être déplacé" << std::endl;
        std::cout << "Coordonées : " << (e.getX()-camerax)*tx << ", " << (e.getY()-cameray)*tx << std::endl;
        std::cout << "Coordonées 2 : " << e.getX() << ", " << e.getY() << std::endl;
        //On récupère l'ID de ce personnage
        if (couchePersonnage->getTuile((e.getX()-camerax)*tx, (e.getY()-cameray)*tx, zoom*tx) != nullptr)
        {
            couchePersonnage->setTuile((e.getX()-camerax)*tx, (e.getY()-cameray)*tx, new TuileStatique((e.getNewx()-camerax)*tx, (e.getNewy()-cameray)*tx, e.getPid(), tx));
            coucheTerrain->setSelectionne((e.getNewx()-camerax)*tx, (e.getNewy()-cameray)*tx, tx);
            std::cout << "FIN" << std::endl;
        }
        else
            std::cout << "Null ptr" << std::endl;
    }
    else if (e.getTypeEvenement() == state::DeplacementCamera)
    {
        int ancienneCamerax = this->camerax;
        int ancienneCameray = this->cameray;
        this->camerax =  e.getNewx(); 
        this->cameray = e.getNewy();
        couchePersonnage->deplacerCamera(-(camerax-ancienneCamerax)*tx, -(cameray-ancienneCameray)*tx);
        coucheTerrain->deplacerCamera(-(camerax-ancienneCamerax)*tx, -(cameray-ancienneCameray)*tx);
    }
    else if (e.getTypeEvenement() == state::ZoomCamera)
    {   float ancienZoom = this->zoom;
        this->zoom = e.getZoom();
        tx = (sf::VideoMode::getDesktopMode().width*zoom)/24.;
        couchePersonnage->zoomCamera(zoom/ancienZoom);
        coucheTerrain->zoomCamera(zoom/ancienZoom);
    }
    else if (e.getTypeEvenement() == state::ModeDeplacement)
    {
        if (e.getEquipe())
            coucheTerrain->setSurbrillance((e.getX()-camerax)*tx, (e.getY()-cameray)*tx, tx);
        else
            coucheTerrain->unsetSurbrillance();
    }
    else if (e.getTypeEvenement() == state::ModeAttaque)
    {
        if (e.getEquipe())
            coucheTerrain->setRouge((e.getX()-camerax)*tx, (e.getY()-cameray)*tx, tx);
        else
            coucheTerrain->unsetRouge();
    }
    else if (e.getTypeEvenement() == state::ChangementSelectionne)
    {
        std::cout << "On traite le changement dans Scene" << std::endl;
        if (etat->getGrille().getCellulePersonnage(e.getX(), e.getY()))
        {
            std::cout << "Le personnage existe" << std::endl;
            coucheTerrain->setSelectionne((e.getX()-camerax)*tx, (e.getY()-cameray)*tx, tx);
            panneau->setSelectionne(etat, etat->getGrille().getCellulePersonnage(e.getX(), e.getY()));
        }
        else 
        {
            std::cout << "Le personnage n'existe pas" << std::endl;
            coucheTerrain->unsetSelectionne();
            panneau->unsetSelectionne();
        }
    }
    else if (e.getTypeEvenement() == state::Attaque)
    {
        couchePersonnage->setTuile((e.getX()-camerax)*tx, (e.getY()-cameray)*tx, new TuileAnimee((e.getX()-camerax)*tx, (e.getY()-cameray)*tx, 5, tx, couchePersonnage));
        couchePersonnage->setTuile((e.getNewx()-camerax)*tx, (e.getNewy()-cameray)*tx, new TuileAnimee((e.getNewx()-camerax)*tx, (e.getNewy()-cameray)*tx, 18, tx, couchePersonnage));
    }
    
    
}
 
void Scene::afficher()
{
    window->clear();
    coucheTerrain->afficher();
    couchePersonnage->afficher();
    panneau->draw(window);
    window->display();
}

int Scene::getZoom()
{
   return this->zoom; 
}

void Scene::setZoom(int z)
{
    this->zoom = z;
}

void Scene::setCamera(int x, int y)
{
    this->camerax = x;
    this->cameray = y;
}
float Scene::getCoeff()
{
    return tx;
}
int Scene::getCamerax()
{
    return camerax;
}
int Scene::getCameray()
{
    return cameray;
}