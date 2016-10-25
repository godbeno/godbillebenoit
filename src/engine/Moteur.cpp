#include "Moteur.h"
#include "CommandeClic.h"
#include "Deplacement.h"

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
}
Mode Moteur::getMode()
{
    return mode;
}
void Moteur::update(clock_t t)
{
    if ((t-derniereMaj) > 0.2)
    {
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
    ListeActions aVerifier(etat); 
    if (listeCommande.get(3) != nullptr) // Gestion du clic de souris
    {
        if (mode == Mode::deplacement) // Si on est en mode déplacement
        {
            CommandeClic* cc = static_cast<CommandeClic*>(listeCommande.get(3));
            aVerifier.ajouter(new Deplacement(etat->getSelectionne()->getX(), etat->getSelectionne()->getY(), cc->getX(), cc->getY()));
        }
    }
    Regulateur r(aVerifier, etat, listeCommande);
    r.appliquer();
}
