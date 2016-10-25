#include "Regulateur.h"

using namespace engine;

Regulateur::Regulateur(ListeActions& lsAction, state::Etat* etat, ListeCommande& lsCmd)
{
    actions = lsAction;
    etatCourant = etat;
    commandes = lsCmd;
    
    //Vérification des actions
    
}
Regulateur::~Regulateur()
{
}

void Regulateur::appliquer()
{
    actions.appliquer(); 
}