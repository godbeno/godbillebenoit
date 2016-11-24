#include "Historique.h"
#include <iostream>

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
    if (lsHistorique->taille() > 0)
    {
        //std::cout << "Taille ok (" << lsHistorique->taille() <<")" << std::endl;
        lsHistorique->get(lsHistorique->taille()-1)->annuler(etat, false);
        lsHistorique->supprimer(lsHistorique->taille()-1);
    }
}
void Historique::annulerToutesActions (state::Etat* etat)
{
    for (int i = 0; i < lsHistorique->taille(); i++)
    {
        lsHistorique->get(lsHistorique->taille()-i)->annuler(etat, false);
        lsHistorique->supprimer(lsHistorique->taille()-i);
    }
}
void Historique::retourSauvegarde (state::Etat* etat)
{
    etat->copy(*etatPrecedent);
}
