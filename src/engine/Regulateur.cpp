#include "Regulateur.h"
#include <iostream>
#include "ListeCommande.h"
#include "Deplacement.h"
#include "ChangerMode.h"
#include "Attaquer.h"
#include <algorithm>
#include <SFML/Graphics.hpp>
#include "Moteur.h"
using namespace engine;

Regulateur::Regulateur(ListeActions* lsAction, state::Etat* etat, ListeCommande* lsCmd, Moteur *moteur)
{
    actions = lsAction;
    etatCourant = etat;
    commandes = lsCmd;
    
    //Vérification des actions
    for (int i = 0; i < lsAction->taille(); i++)
    {
        if (dynamic_cast<Deplacement*>(lsAction->get(i))) // On se place dans le cadre de Deplacement
        {
            std::vector<state::CaseTerrain*> v = etat->getCaseAtteignable(etat->getSelectionne());
            state::CaseTerrain* ct = static_cast<Deplacement*>(lsAction->get(i))->getCaseArrivee(etat);
            //if (ct)
                //std::cout << "Case Clic : " << ct->getX() << " " << ct->getY() << std::endl;
            if (std::find(v.begin(), v.end(), ct) == v.end())
            {
                lsAction->supprimer(i);
                lsAction->ajouter(new ChangerMode(6, -1, -1, moteur));
            }
            else
            {
                lsAction->ajouter(new ChangerMode(4, -1, -1, moteur));
            }
        }
        if (dynamic_cast<Attaquer*>(lsAction->get(i)))
        {
            std::vector<state::CaseTerrain*> v = etat->getCaseAttaquable(etat->getSelectionne());
            state::CaseTerrain* ct = static_cast<Attaquer*>(lsAction->get(i))->getCaseArrivee(etat);
            state::Personnage* p = etat->getSelectionne();
            if (std::find(v.begin(), v.end(), ct) == v.end() || p->getPA() < 2)
            {
                lsAction->supprimer(i);
                lsAction->ajouter(new ChangerMode(6, -1, -1, moteur));
            }

        }
        /*if (dynamic_cast<ChangerMode*>(lsAction->get(i)))
        {
            if (!static_cast<ChangerMode*>(lsAction->get(i))->getPersonnage(etat)->getEquipe())
                lsAction->supprimer(i);
        }*/
    }
    //std::cout << "TAILLE : "<< lsAction->taille() << std::endl;   
}
Regulateur::~Regulateur()
{
    //std::cout << "Destructeur de Regulateur" << std::endl;
}

void Regulateur::appliquer(bool afficher, Moteur* moteur)
{
    //std::cout << "(" << actions->taille() << ", " << commandes->taille() << ")" << std::endl;
    //std::cout << "Application des actions ! " << std::endl;
    if (moteur->enregistrementActive())
        for (int i = 0; i < actions->taille(); i++)
            moteur->enregistrerAction(actions->get(i));
    actions->appliquer(afficher); 
}