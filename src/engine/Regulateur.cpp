#include "Regulateur.h"
#include <iostream>
#include "ListeCommande.h"
#include "Deplacement.h"
#include "ChangerMode.h"
#include <algorithm>
#include <SFML/Graphics.hpp>
using namespace engine;

Regulateur::Regulateur(ListeActions* lsAction, state::Etat* etat, ListeCommande* lsCmd, Moteur *moteur)
{
    actions = lsAction;
    etatCourant = etat;
    commandes = lsCmd;
    
    int largeur = sf::VideoMode::getDesktopMode().width;
    int hauteur = sf::VideoMode::getDesktopMode().height;
    std::cout << "Hauteur : " << hauteur-100 << ", Largeur : " << largeur/2-180 << std::endl;
    
    //Vérification des actions
    for (int i = 0; i < lsAction->taille(); i++)
    {
        /*if (dynamic_cast<ChangerMode*>(lsAction->get(i)))
        {
            ChangerMode *cm = static_cast<ChangerMode*>(lsAction->get(i));
            if (!cm->getPersonnage(etat))
            {
                lsAction->supprimer(i);
                lsAction->ajouter(new ChangerMode(3,-2,-2,moteur));
            }
        }*/
        if (dynamic_cast<Deplacement*>(lsAction->get(i))) // On se place dans le cadre de Deplacement
        {
            std::vector<state::CaseTerrain*> v = etat->getCaseAtteignable(etat->getSelectionne());
            std::cout << "V size :" << v.size() << std::endl;
            state::CaseTerrain* ct = static_cast<Deplacement*>(lsAction->get(i))->getCaseArrivee(etat);
            if (ct)
                std::cout << "Case Clic : " << ct->getX() << " " << ct->getY() << std::endl;
            //for (int j = 0; j < v.size(); j++)
            //    std::cout << "tableau " << j << " : " << v[j]->getX() << ", " << v[j]->getY() << std::endl;
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
    }
    std::cout << "TAILLE : "<< lsAction->taille() << std::endl;   
}
Regulateur::~Regulateur()
{
    //std::cout << "Destructeur de Regulateur" << std::endl;
}

void Regulateur::appliquer()
{
    //std::cout << "(" << actions->taille() << ", " << commandes->taille() << ")" << std::endl;
    //std::cout << "Application des actions ! " << std::endl;
    actions->appliquer(); 
}