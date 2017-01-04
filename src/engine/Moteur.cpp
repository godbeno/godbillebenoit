#include "Moteur.h"
#include "CommandeClic.h"
#include "CommandeFleche.h"
#include "CommandeZoomCamera.h"
#include "Deplacement.h"
#include "DeplacementCamera.h"
#include "ChangerMode.h"
#include "ChangerTour.h"
#include "ChangerInit.h"
#include "Attaquer.h"
#include "Zoom.h"
#include "Historique.h"
#include <iostream>
#include <thread>
#include <mutex>

std::mutex actionMutex;
//std::mutex mtxUsr;
using namespace engine;

Moteur::Moteur(state::Etat* etat)
{
    quitter = false;
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
    //actionMutex.lock();
    listeCommande.set(cmd);
    //actionMutex.unlock();
}
Mode Moteur::getMode()
{
    return mode;
}
void Moteur::update(clock_t t)
{
    //double(time-debut)/ CLOCKS_PER_SEC > 0.1
    //if ((double)(t-derniereMaj)/CLOCKS_PER_SEC > 0.1)
    //{
        //std::cout << "update " << listeCommande.taille() << std::endl;
        if ((listeNonVide() && etat->joueurIA()) || (!etat->joueurIA() && (double)(t-derniereMaj)/CLOCKS_PER_SEC > 0.5))
        {
            convertirCommande();
            derniereMaj = t;
        }
            //convertirCommande(true);
        //derniereMaj = t;
    //}
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
void Moteur::convertirCommande()
{
    //mtxUsr.lock();
    if (listeCommande.get(3) != nullptr && !etat->joueurIA()) // Gestion du clic de souris
    {
        CommandeClic* cc = static_cast<CommandeClic*>(listeCommande.get(3));
        if (mode == Mode::deplacement)
            ajouterAction(new Deplacement(etat->getSelectionne()->getX(), etat->getSelectionne()->getY(), cc->getX(), cc->getY(), true));

        else if (mode == Mode::jeu && cc->getBouton() == 0)
            ajouterAction(new ChangerMode(6, cc->getX(), cc->getY(), this, true));
        else if (mode == Mode::selection && cc->getBouton() == 0)
            ajouterAction(new ChangerMode(6, cc->getX(), cc->getY(), this, true));
        else if (mode == Mode::selection && cc->getBouton() == 1 && etat->getSelectionne()->getEquipe() == etat->getTour())
            ajouterAction(new ChangerMode(5, -1, -1, this, true));
        else if (mode == Mode::selection && cc->getBouton() == 2 && etat->getSelectionne()->getEquipe() == etat->getTour())
            ajouterAction(new ChangerMode(4, -1, -1, this, true));
        else if ((mode == Mode::selection || mode == Mode::jeu) && cc->getBouton() == 3)
            ajouterAction(new ChangerTour(true));      
        else if (mode == Mode::attaque)
             ajouterAction(new Attaquer(etat->getSelectionne()->getX(), etat->getSelectionne()->getY(), cc->getX(), cc->getY(), true));
        else if (mode == Mode::initialisation && abs(cc->getBouton()) > 16 && abs(cc->getBouton()) < 23)
        {   ajouterAction(new ChangerInit((etat->getTour()*12+abs(cc->getBouton())-10), (etat->getDonneesInit(etat->getTour()*12+abs(cc->getBouton())-10)+(cc->getBouton())/abs(cc->getBouton()))));
        std::cout << "ChangerInit ajouté, avec comme parametres "<< etat->getTour()*12+abs(cc->getBouton())-10 << ", "<< etat->getDonneesInit(etat->getTour()*12+abs(cc->getBouton())-10)+(cc->getBouton())/abs(cc->getBouton()) << std::endl;}
    
    }
    if (listeCommande.get(1) != nullptr) // Gestion des touches caméra
    {
       CommandeFleche* cc = static_cast<CommandeFleche*>(listeCommande.get(1));
       if (cc->getDirection() == 1)
          ajouterAction(new DeplacementCamera(etat->getCamerax(), etat->getCameray(), etat->getCamerax(), etat->getCameray()-1));
       else if(cc->getDirection() == 2)
          ajouterAction(new DeplacementCamera(etat->getCamerax(), etat->getCameray(), etat->getCamerax(), etat->getCameray()+1));
       else if(cc->getDirection() == 3)
          ajouterAction(new DeplacementCamera(etat->getCamerax(), etat->getCameray(), etat->getCamerax()+1, etat->getCameray()));
       else if(cc->getDirection() == 4)
          ajouterAction(new DeplacementCamera(etat->getCamerax(), etat->getCameray(), etat->getCamerax()-1, etat->getCameray()));
    }
    if (listeCommande.get(2) != nullptr) // Gestion du zoom caméra
    {
       CommandeZoomCamera* cc = static_cast<CommandeZoomCamera*>(listeCommande.get(2));
       ajouterAction(new Zoom(cc->geti()));
    }
    if (listeCommande.get(1) != nullptr || listeCommande.get(2) != nullptr || listeCommande.get(3) != nullptr)
        std::cout << "Humain->";
    listeCommande.vider();
    //mtxUsr.unlock();
    if (aVerifier->taille() > 0)
    {
        actionMutex.lock();
        Regulateur r(aVerifier, etat, this);
        r.appliquer(this);
        aVerifier->vider();
        actionMutex.unlock();
    }
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
    actionMutex.lock();
    aVerifier->ajouter(action);
    actionMutex.unlock();
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
void Moteur::updateThread()
{
    while(!etat->partieContinue() && !quitter)
        update(clock());
}
void Moteur::quit()
{
    quitter = true;
}
bool Moteur::listeNonVide()
{
    int nbCmd = 0;
    /*mtxUsr.lock();
    for (int i = 0; i < 3; i++)
        nbCmd += (listeCommande.get(i) != nullptr);
    mtxUsr.unlock();*/
    return (aVerifier->taille() > 0 || nbCmd >0);
}