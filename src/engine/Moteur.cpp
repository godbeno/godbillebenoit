#include "Moteur.h"

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
    
}
void Moteur::setMode(Mode mode)
{
    this->mode = mode;
}
/*
    update (clock_t t);
    setMode (Mode mode);
*/
