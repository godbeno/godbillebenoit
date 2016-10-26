#include "Regulateur.h"
#include <iostream>
#include "ListeCommande.h"
#include "Deplacement.h"
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
            //On verifie qu'il s'agit d'un déplacement autorisé 
        }
    }
    
}
Regulateur::~Regulateur()
{
    std::cout << "Destructeur de Regulateur" << std::endl;
}

void Regulateur::appliquer()
{
    std::cout << "(" << actions->taille() << ", " << commandes->taille() << ")" << std::endl;
    std::cout << "Application des actions ! " << std::endl;
    actions->appliquer(); 
}