#include "Regulateur.h"

using namespace engine;

Regulateur::Regulateur(ListeActions* lsAction, state::Etat* etat, ListeCommande* lsCmd)
{
    actions = lsAction;
    etatCourant = etat;
    commandes = lsCmd;
}
Regulateur::~Regulateur()
{
    delete actions;
}