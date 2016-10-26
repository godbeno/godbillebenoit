#include "Regulateur.h"
#include <iostream>
#include "ListeCommande.h"
#include "Deplacement.h"
#include <algorithm>
using namespace engine;

Regulateur::Regulateur(ListeActions* lsAction, state::Etat* etat, ListeCommande* lsCmd)
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
            std::cout << "V size :" << v.size() << std::endl;
            state::CaseTerrain* ct = static_cast<Deplacement*>(lsAction->get(i))->getCaseArrivee(etat);
            std::cout << "Case Clic : " << ct->getX() << " " << ct->getY() << std::endl;
            std::cout << "V[0] : " << v[0]->getX() << " " << v[0]->getY() << std::endl;
            if (std::find(v.begin(), v.end(), ct) == v.end())
            {
                lsAction->supprimer(i);
                std::cout << "ICI " << std::endl;
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