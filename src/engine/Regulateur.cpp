#include "Regulateur.h"
#include <iostream>
#include "ListeCommande.h"
using namespace engine;

Regulateur::Regulateur(ListeActions* lsAction, state::Etat* etat, ListeCommande* lsCmd)
{
    actions = lsAction;
    etatCourant = etat;
    commandes = lsCmd;
    
    //Vérification des actions
    
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