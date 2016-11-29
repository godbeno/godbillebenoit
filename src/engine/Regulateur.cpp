#include "Regulateur.h"
#include <iostream>
#include "ListeCommande.h"
#include "Deplacement.h"
#include "ChangerMode.h"
#include "Attaquer.h"
#include "Selection.h"
#include "ChangerTour.h"
#include "Zoom.h"
#include "DeplacementCamera.h"
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
            Deplacement* dep = static_cast<Deplacement*>(lsAction->get(i));
            std::cout << "Déplacement[";
            dep->printOrigine();
            dep->printArrivee();
            std::cout << "]->";
            std::vector<state::CaseTerrain*> v = etat->getCaseAtteignable(etat->getSelectionne());
            state::CaseTerrain* ct = static_cast<Deplacement*>(lsAction->get(i))->getCaseArrivee(etat);
            if (std::find(v.begin(), v.end(), ct) == v.end())
            {
                std::cout << "Annulé->";
                lsAction->supprimer(i);
                std::cout << "Mode Selection->";
                lsAction->ajouter(new ChangerMode(6, -1, -1, moteur));
            }
            else
            {
                std::cout << "mode déplacement->";
                lsAction->ajouter(new ChangerMode(4, -1, -1, moteur));
            }
        }
        if (dynamic_cast<Attaquer*>(lsAction->get(i)))
        {
            Attaquer* att = static_cast<Attaquer*>(lsAction->get(i));
            std::cout << "Attaque[";
            att->printOrigine();
            att->printArrivee();
            std::cout << "]->";
            std::vector<state::CaseTerrain*> v = etat->getCaseAttaquable(etat->getSelectionne());
            state::CaseTerrain* ct = static_cast<Attaquer*>(lsAction->get(i))->getCaseArrivee(etat);
            state::Personnage* p = etat->getSelectionne();
            if (std::find(v.begin(), v.end(), ct) == v.end() || p->getPA() < 2)
            {
                std::cout << "Annulé->";
                lsAction->supprimer(i);
                std::cout << "Mode Selection->";
                lsAction->ajouter(new ChangerMode(6, -1, -1, moteur));
            }

        }
        if (dynamic_cast<ChangerTour*>(lsAction->get(i)))
            std::cout << "Changement de Tour->";
        if (dynamic_cast<ChangerMode*>(lsAction->get(i)))
        {
            std::cout << "Changement de Mode->";
            ChangerMode* cm = static_cast<ChangerMode*>(lsAction->get(i));
            if (moteur->getMode() == Mode::jeu && etat->getSelectionne() == nullptr && etat->getGrille().getCellulePersonnage(cm->getX(), cm->getY()) == nullptr)
            {
                std::cout << "Annulé" << std::endl;
                lsAction->supprimer(i);
            }
        }
        if (dynamic_cast<Selection*>(lsAction->get(i)))
            std::cout << "Selection->";
        if (dynamic_cast<Zoom*>(lsAction->get(i)))
            std::cout << "Zoom->";
        if (dynamic_cast<DeplacementCamera*>(lsAction->get(i)))
            std::cout << "Deplacement de la Caméra->";
        
    }
}
Regulateur::~Regulateur()
{
}

void Regulateur::appliquer(bool afficher, Moteur* moteur)
{
    if (moteur->enregistrementActive())
        for (int i = 0; i < actions->taille(); i++)
        {
            if (dynamic_cast<Attaquer*>(actions->get(i)) || 
                dynamic_cast<Deplacement*>(actions->get(i))) //On vérifie que ce sont bien les actions qu'on souhaite annuler
            {
                std::cout << "Enregistré->";
                moteur->enregistrerAction(actions->get(i));
            }
        }
    for (unsigned int i = 0; i < actions->taille(); i++)
    {
        if (afficher)
        {
            if (dynamic_cast<ChangerTour*>(actions->get(i)))
                std::cout << "Changement de Tour->";
            if (dynamic_cast<ChangerMode*>(actions->get(i)))
                std::cout << "Changement de Mode->";
            if (dynamic_cast<Selection*>(actions->get(i)))
                std::cout << "Selection->";
            if (dynamic_cast<Zoom*>(actions->get(i)))
                std::cout << "Zoom->";
            if (dynamic_cast<DeplacementCamera*>(actions->get(i)))
                std::cout << "Deplacement de la Caméra->";
            if (dynamic_cast<Attaquer*>(actions->get(i)))
            {
                Attaquer* att = static_cast<Attaquer*>(actions->get(i));
                std::cout << "Attaque[";
                att->printOrigine();
                att->printArrivee();
                std::cout << "]->";
            }
            if (dynamic_cast<Deplacement*>(actions->get(i)))
            {
                Deplacement* dep = static_cast<Deplacement*>(actions->get(i));
                std::cout << "Deplacement[";
                dep->printOrigine();
                dep->printArrivee();
                std::cout << "]->";
            }
        }
    }
    std::cout << "Etat->";
    actions->appliquer(afficher);
    if (afficher)
        std::cout << "0k" << std::endl;
}