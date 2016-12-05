#include "Scene.h"
#include "state/Etat.h"
#include "TuileStatique.h"
#include "TuileAnimee.h"
#include <iostream>
#include "Panneau.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Audio.hpp>
#include <mutex>

//std::mutex mtx;

using namespace render;

Scene::Scene(state::Etat* etat, sf::RenderWindow* window)
{
    coucheTerrain = new Couche(window);
    couchePersonnage = new Couche(window);
    panneau = new Panneau();
    message = new Message();
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
            coucheTerrain->addTuile(new TuileStatique((l.get(i)->getX()-camerax)*tx, (l.get(i)->getY()-cameray)*tx, l.get(i)->getID(), tx,l.get(i)->getX(),l.get(i)->getY(), this));
        if (l.get(i)->estPersonnage())
            couchePersonnage->addTuile(new TuileStatique((l.get(i)->getX()-camerax)*tx, (l.get(i)->getY()-cameray)*tx, l.get(i)->getID()+50+10*!(static_cast<state::Personnage*>(l.get(i))->getEquipe()), tx,l.get(i)->getX(),l.get(i)->getY(), this));
    }
}
Scene::~Scene()
{
    delete couchePersonnage;
    delete coucheTerrain;
}
void Scene::changementEtat(state::EvenementEtat& e)
{
    //std::cout << "Affichage->";
    if (e.getTypeEvenement() == state::NouveauPersonnage)
    {
        couchePersonnage->addTuile(new TuileStatique((e.getX()-camerax)*tx, (e.getY()-cameray)*tx,e.getPid(), tx,e.getX(),e.getY(), this));
    }
       
    else if (e.getTypeEvenement() == state::PersonnageDeplace)
    {
        if (couchePersonnage->getTuile(e.getX(), e.getY(), zoom*tx) != nullptr)
        {		
            mutexPerso.lock();
            couchePersonnage->setTuile(e.getX(), e.getY(), new TuileStatique((e.getNewx()-camerax)*tx, (e.getNewy()-cameray)*tx, e.getPid(), tx,e.getNewx(),e.getNewy(), this));
            mutexPerso.unlock();
            mutexTerrain.lock();
            coucheTerrain->setSelectionne((e.getNewx()-camerax)*tx, (e.getNewy()-cameray)*tx, tx);
            mutexTerrain.unlock();
            mutexPanneau.lock();
            panneau->setSelectionne(etat, etat->getSelectionne());   
            mutexPanneau.unlock();
        }
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
        mutexTerrain.lock();
        if (e.getEquipe())
            coucheTerrain->setSurbrillance((e.getX()-camerax)*tx, (e.getY()-cameray)*tx, tx);
        else
            coucheTerrain->unsetSurbrillance();
        mutexTerrain.unlock();
    }
    else if (e.getTypeEvenement() == state::ModeAttaque)
    {
        mutexTerrain.lock();
        if (e.getEquipe())
            coucheTerrain->setRouge((e.getX()-camerax)*tx, (e.getY()-cameray)*tx, tx);
        else
            coucheTerrain->unsetRouge();
        mutexTerrain.unlock();
    }
    else if (e.getTypeEvenement() == state::ChangementSelectionne)
    {
        if (etat->getGrille().getCellulePersonnage(e.getX(), e.getY()))
        {
            mutexTerrain.lock();
            coucheTerrain->setSelectionne((e.getX()-camerax)*tx, (e.getY()-cameray)*tx, tx);
            mutexTerrain.unlock();
            mutexPanneau.lock();
            panneau->setSelectionne(etat, etat->getGrille().getCellulePersonnage(e.getX(), e.getY()));
            mutexPanneau.unlock();
        }
        else 
        {
            mutexTerrain.lock();
            coucheTerrain->unsetSelectionne();
            mutexTerrain.unlock();
            mutexPanneau.lock();
            panneau->unsetSelectionne();
            mutexPanneau.unlock();
        }
    }
    else if (e.getTypeEvenement() == state::Attaque)
    {
        //std::cout << std::endl << "Attaque enclenchée dans affichage" << std::endl;
        int idp1 = couchePersonnage->getTuile(e.getX(), e.getY(), tx)->getID();
        int idp2 = couchePersonnage->getTuile(e.getNewx(), e.getNewy(), tx)->getID();
        int id1 = (((idp1-43)/2)-1) + ((idp1+1)%2)*7;
        int id2 = (((idp2-43)/2)-1) + ((idp2+1)%2)*19 + ((idp2)%2)*12;
        //std::cout << "Fin des ids" << std::endl;
        mutexPerso.lock();
        couchePersonnage->setTuile(e.getX(), e.getY(), new TuileAnimee((e.getX()-camerax)*tx, (e.getY()-cameray)*tx, id1, tx, couchePersonnage,e.getX(),e.getY(), this));
        couchePersonnage->setTuile(e.getNewx(), e.getNewy(), new TuileAnimee((e.getNewx()-camerax)*tx, (e.getNewy()-cameray)*tx, id2, tx,couchePersonnage,e.getNewx(),e.getNewy(), this));
        //std::cout << "Fin des setTuiles" << std::endl;        
        couchePersonnage->setDegat((e.getNewx()-camerax)*tx, (e.getNewy()-cameray)*tx, (int)e.getZoom());
        mutexPerso.unlock();
        //std::cout << "Fin des setDegats" << std::endl;
        mutexPanneau.lock();
        panneau->setSelectionne(etat, etat->getSelectionne()); 
        mutexPanneau.unlock();       
        //std::cout << "Fin des setSelectionne" << std::endl;
    }
    else if (e.getTypeEvenement() == state::PersonnageMort)
    {
        mutexPerso.lock();
        couchePersonnage->setTuile(e.getX(), e.getY(),nullptr);
        mutexPerso.unlock();
    }
    else if (e.getTypeEvenement() == state::ChangementDeTour)
    {
        mutexMsg.lock();
        message->changerTour();
        mutexMsg.unlock();
    }
    else if (e.getTypeEvenement() == state::FinDePartie)
    {
        mutexMsg.lock();
        message->finDePartie(e.getEquipe());
        mutexMsg.unlock();
    }
    
    
}
 
void Scene::afficher()
{
    window->clear();
    //std::cout << "Avnt couche Terrain" << std::endl;
    mutexTerrain.lock();
    coucheTerrain->afficher();
    mutexTerrain.unlock();
    //std::cout << "Couche Terrain dessinée" << std::endl;
    mutexPerso.lock();
    couchePersonnage->afficher();
    mutexPerso.unlock();
    //std::cout << "Les couches ont été dessinées" << std::endl;
    mutexPanneau.lock();
    panneau->draw(window);
    mutexPanneau.unlock();
    mutexMsg.lock();
    message->dessiner(window);
    mutexMsg.unlock();
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