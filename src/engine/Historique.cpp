#include "Historique.h"

using namespace engine;

Historique::Historique(state::Etat* sauvegarde)
{
    etatPrecedent = sauvegarde->clone();
    lsHistorique = new ListeActions();
}
void Historique::ajouterAction (Action* action)
{
    lsHistorique->ajouter(action);
}
void Historique::annulerUneAction ()
{
    
}
void Historique::annulerToutesActions ()
{
    
}
void Historique::retourSauvegarde (state::Etat* etat)
{
    etat->copy(*etatPrecedent);
}
