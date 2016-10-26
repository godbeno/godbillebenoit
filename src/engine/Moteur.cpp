#include "Moteur.h"
#include "CommandeClic.h"
#include "CommandeFleche.h"
#include "Deplacement.h"
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
        std::cout << "update" << std::endl;
        convertirCommande();
        derniereMaj = t;
    }
    
}
void Moteur::setMode(Mode mode)
{
    this->mode = mode;
}
void Moteur::convertirCommande()
{
    std::cout << "--------------------------------" << std::endl;
    std::cout << "On entre dans Convertir Commande" << std::endl;
    ListeActions aVerifier(etat); 
    if (listeCommande.get(3) != nullptr) // Gestion du clic de souris
    {
        if (mode == Mode::deplacement) // Si on est en mode déplacement
        {
            std::cout << "Traitement de la commande ! " << std::endl;
            CommandeClic* cc = static_cast<CommandeClic*>(listeCommande.get(3));
            std::cout << "Cast de la commande ! " << std::endl;
            aVerifier.ajouter(new Deplacement(etat->getSelectionne()->getX(), etat->getSelectionne()->getY(), cc->getX(), cc->getY()));
            std::cout << "Conversion de la commande ! " << std::endl;
        }
    }
    
    if (listeCommande.get(1) != nullptr) // Gestion des touches caméra
    {

        
       std::cout << "Traitement de la commande ! " << std::endl;
       CommandeFleche* cc = static_cast<CommandeFleche*>(listeCommande.get(1));
       std::cout << "Cast de la commande ! " << std::endl;
       //aVerifier.ajouter(new Deplacement(etat->getSelectionne()->getX(), etat->getSelectionne()->getY(), cc->getX(), cc->getY()));
       std::cout << "Conversion de la commande ! " << std::endl;

    }    
    
   
    Regulateur r(&aVerifier, etat, &listeCommande);
    r.appliquer();
    std::cout << "Fin de l'application" << std::endl;
    listeCommande.vider();
    std::cout << "Liste vidée ! " << std::endl;
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