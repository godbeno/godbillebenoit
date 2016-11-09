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
void Historique::annulerUneAction (state::Etat* etat)
{
    lsHistorique->get(lsHistorique->taille()-1)->annuler(etat);
    lsHistorique->supprimer(lsHistorique->taille()-1);
}
void Historique::annulerToutesActions (state::Etat* etat)
{
    for (int i = 0; i < lsHistorique->taille(); i++)
    {
        lsHistorique->get(lsHistorique->taille()-i)->annuler(etat);
        lsHistorique->supprimer(lsHistorique->taille()-i);
    }
}
void Historique::retourSauvegarde (state::Etat* etat)
{
    etat->copy(*etatPrecedent);
}
