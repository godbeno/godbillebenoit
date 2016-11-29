#include "Moteur.h"
#include "CommandeClic.h"
#include "CommandeFleche.h"
#include "CommandeZoomCamera.h"
#include "Deplacement.h"
#include "DeplacementCamera.h"
#include "ChangerMode.h"
#include "ChangerTour.h"
#include "Attaquer.h"
#include "Zoom.h"
#include "Historique.h"
#include <iostream>
#include <thread>
#include <mutex>

using namespace engine;

Moteur::Moteur(state::Etat* etat)
{
    mode = Mode::demarrer;
    derniereMaj = clock();
    this->etat = etat;
    aVerifier = new ListeActions(etat);
    historique = new Historique(etat);
    enregistrer = false;
}
Moteur::~Moteur()
{
    delete etat;
}
state::Etat* Moteur::getEtat()
{
    return etat;
}
void Moteur::ajouterCommande (Commande* cmd)
{
    listeCommande.set(cmd);
}
Mode Moteur::getMode()
{
    return mode;
}
void Moteur::update(clock_t t)
{
    if ((t-derniereMaj) > 2)
    {
        //std::cout << "update " << listeCommande.taille() << std::endl;
        if (listeCommande.taille() != 0)
        {
            std::thread th(&Moteur::convertirCommande, this, true);
            th.join();
        }
            //convertirCommande(true);
        derniereMaj = t;
    }
}
void Moteur::setMode(Mode mode)
{
    if (this->mode == deplacement)
    {
        etat->setBrillant(false, nullptr);
    }
    else if (this->mode == attaque)
        etat->setRouge(false, nullptr);
    this->mode = mode;
    if (mode == deplacement)
    {
        std::vector<state::CaseTerrain*> v = etat->getCaseAtteignable(etat->getSelectionne());
        for (unsigned int j = 0; j < v.size(); j++)
            etat->setBrillant(true, v[j]);
    }
    else if (mode == attaque)
    {
        std::vector<state::CaseTerrain*> v = etat->getCaseAttaquable(etat->getSelectionne());
        for (unsigned int j = 0; j < v.size(); j++)
            etat->setRouge(true, v[j]);
    }
}
void Moteur::convertirCommande(bool afficher)
{
    if (listeCommande.get(3) != nullptr && !etat->joueurIA()) // Gestion du clic de souris
    {
        CommandeClic* cc = static_cast<CommandeClic*>(listeCommande.get(3));
        if (mode == Mode::deplacement)
            aVerifier->ajouter(new Deplacement(etat->getSelectionne()->getX(), etat->getSelectionne()->getY(), cc->getX(), cc->getY()));
        else if (mode == Mode::jeu && cc->getBouton() == 0)
            aVerifier->ajouter(new ChangerMode(6, cc->getX(), cc->getY(), this));
        else if (mode == Mode::selection && cc->getBouton() == 0)
            aVerifier->ajouter(new ChangerMode(6, cc->getX(), cc->getY(), this));
        else if (mode == Mode::selection && cc->getBouton() == 1 && etat->getSelectionne()->getEquipe() == etat->getTour())
            aVerifier->ajouter(new ChangerMode(5, -1, -1, this));
        else if (mode == Mode::selection && cc->getBouton() == 2 && etat->getSelectionne()->getEquipe() == etat->getTour())
            aVerifier->ajouter(new ChangerMode(4, -1, -1, this));
        else if (mode == Mode::selection && cc->getBouton() == 3)
            aVerifier->ajouter(new ChangerTour());      
        else if (mode == Mode::attaque)
            aVerifier->ajouter(new Attaquer(etat->getSelectionne()->getX(), etat->getSelectionne()->getY(), cc->getX(), cc->getY()));     
    }
    if (listeCommande.get(1) != nullptr) // Gestion des touches caméra
    {
       CommandeFleche* cc = static_cast<CommandeFleche*>(listeCommande.get(1));
       if (cc->getDirection() == 1)
          aVerifier->ajouter(new DeplacementCamera(etat->getCamerax(), etat->getCameray(), etat->getCamerax(), etat->getCameray()-1));
       else if(cc->getDirection() == 2)
          aVerifier->ajouter(new DeplacementCamera(etat->getCamerax(), etat->getCameray(), etat->getCamerax(), etat->getCameray()+1));
       else if(cc->getDirection() == 3)
          aVerifier->ajouter(new DeplacementCamera(etat->getCamerax(), etat->getCameray(), etat->getCamerax()+1, etat->getCameray()));
       else if(cc->getDirection() == 4)
          aVerifier->ajouter(new DeplacementCamera(etat->getCamerax(), etat->getCameray(), etat->getCamerax()-1, etat->getCameray()));
    }
    if (listeCommande.get(2) != nullptr) // Gestion du zoom caméra
    {
       CommandeZoomCamera* cc = static_cast<CommandeZoomCamera*>(listeCommande.get(2));
       aVerifier->ajouter(new Zoom(cc->geti()));
    }
    if (listeCommande.get(1) != nullptr || listeCommande.get(2) != nullptr || listeCommande.get(3) != nullptr)
        std::cout << "Humain->";
    std::mutex mtx;
    mtx.lock();
    Regulateur r(aVerifier, etat, &listeCommande, this);
    r.appliquer(afficher, this);
    listeCommande.vider();
    aVerifier->vider();
    mtx.unlock();
}

void Moteur::setZoom(float z)
{
    this->zoom = z ;
}

float Moteur::getZoom()
{
    return zoom;
}

void Moteur::setCamerax(int cx)
{
    this->camerax = cx;
}

int Moteur::getCamerax()
{
    return camerax;
}

void Moteur::setCameray(int cy)
{ 
    this->cameray = cy;
}

int Moteur::getCameray()
{
    return cameray;
}
void Moteur::ajouterAction(Action* action)
{
    aVerifier->ajouter(action);
}
void Moteur::finDuTour()
{
    etat->finDuTour();
}
void Moteur::annuler()
{
    historique->annulerUneAction(etat);
    //std::cout << "0k" << std::endl;
}
void Moteur::commencerEnregistrement()
{
    enregistrer = true;
}
void Moteur::arreterEnregistrement()
{
    enregistrer = false;
}
bool Moteur::enregistrementActive()
{
    return enregistrer;
}
void Moteur::enregistrerAction(Action* action)
{
    historique->ajouterAction(action);
}