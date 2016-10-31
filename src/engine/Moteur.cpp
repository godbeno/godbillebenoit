#include "Moteur.h"
#include "CommandeClic.h"
#include "CommandeFleche.h"
#include "Deplacement.h"
#include "DeplacementCamera.h"
#include "ChangerMode.h"
#include <iostream>

using namespace engine;

Moteur::Moteur(state::Etat* etat)
{
    mode = Mode::demarrer;
    derniereMaj = clock();
    this->etat = etat;
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
    std::cout << " Commande ajoutée " << std::endl;
}
Mode Moteur::getMode()
{
    return mode;
}
void Moteur::update(clock_t t)
{
    if ((t-derniereMaj) > 0.2)
    {
        //std::cout << "update" << std::endl;
        if (listeCommande.taille() != 0)
            convertirCommande();
        derniereMaj = t;
    }
    
}
void Moteur::setMode(Mode mode)
{
    if (this->mode == deplacement)
    {
        etat->setBrillant(false, nullptr);
    }
    this->mode = mode;
    if (mode == deplacement)
    {
        std::vector<state::CaseTerrain*> v = etat->getCaseAtteignable(etat->getSelectionne());
        for (unsigned int j = 0; j < v.size(); j++)
            etat->setBrillant(true, v[j]);
    }
    else
    {
        
    }
}
void Moteur::convertirCommande()
{
    std::cout << "--------------------------------" << std::endl;
    std::cout << "On entre dans Convertir Commande" << std::endl;
    ListeActions aVerifier(etat); 
    if (listeCommande.get(3) != nullptr) // Gestion du clic de souris
    {
        CommandeClic* cc = static_cast<CommandeClic*>(listeCommande.get(3));
        if (mode == Mode::deplacement)
            aVerifier.ajouter(new Deplacement(etat->getSelectionne()->getX(), etat->getSelectionne()->getY(), cc->getX(), cc->getY()));
        else if (mode == Mode::jeu)
            aVerifier.ajouter(new ChangerMode(6, cc->getX(), cc->getY(), this));
        else if (mode == Mode::selection)
            aVerifier.ajouter(new ChangerMode(6, cc->getX(), cc->getY(), this));
    }
    
    if (listeCommande.get(1) != nullptr) // Gestion des touches caméra
    {
       //std::cout << "Traitement de la commande ! " << std::endl;
       CommandeFleche* cc = static_cast<CommandeFleche*>(listeCommande.get(1));
       if (cc->getDirection() == 1){
          aVerifier.ajouter(new DeplacementCamera(etat->getCamerax(), etat->getCameray(), etat->getCamerax(), etat->getCameray()-1));
       }
       else if(cc->getDirection() == 2){
          aVerifier.ajouter(new DeplacementCamera(etat->getCamerax(), etat->getCameray(), etat->getCamerax(), etat->getCameray()+1));
       }
       else if(cc->getDirection() == 3){
          aVerifier.ajouter(new DeplacementCamera(etat->getCamerax(), etat->getCameray(), etat->getCamerax()+1, etat->getCameray()));
       }
       else if(cc->getDirection() == 4){
          aVerifier.ajouter(new DeplacementCamera(etat->getCamerax(), etat->getCameray(), etat->getCamerax()-1, etat->getCameray()));
       }
    }    
    
   
    Regulateur r(&aVerifier, etat, &listeCommande, this);
    r.appliquer();
    //std::cout << "Fin de l'application" << std::endl;
    listeCommande.vider();
    //std::cout << "Liste vidée ! " << std::endl;
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