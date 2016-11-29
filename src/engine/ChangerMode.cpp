#include "ChangerMode.h"
#include "Moteur.h"
#include "state/Personnage.h"
#include <iostream>

using namespace engine;

ChangerMode::ChangerMode(int IdMode, int x, int y, Moteur *moteur, bool afficher)
{
   this->idMode = IdMode;
   this->moteur = moteur;
   this->x = x;
   this->y = y;
   ancienPersonnage = nullptr;
   this->afficher = afficher;
}
void ChangerMode::appliquer(state::Etat* etat)
{
    ancienMode = (int)(moteur->getMode());
    ancienPersonnage = etat->getSelectionne();
    moteur->setMode(Mode(idMode));
    if (x != -1 && y != -1)
        etat->setSelectionne(x,y,afficher);
}
state::Personnage* ChangerMode::getPersonnage(state::Etat* etat)
{
    return etat->getGrille().getCellulePersonnage(x,y);
}
int ChangerMode::getX()
{
    return x;
}
int ChangerMode::getY()
{
    return y;
}
void ChangerMode::annuler(state::Etat* etat)
{
    //std::cout << "Changement de Mode->";
    moteur->setMode(Mode(ancienMode));
    if (ancienPersonnage != nullptr)
        etat->setSelectionne(ancienPersonnage->getX(), ancienPersonnage->getY(), afficher);
}