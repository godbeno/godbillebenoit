#include "ChangerMode.h"
#include "Moteur.h"
#include "state/Personnage.h"
#include <iostream>

using namespace engine;

ChangerMode::ChangerMode(int IdMode, int x, int y, Moteur *moteur)
{
   this->idMode = IdMode;
   this->moteur = moteur;
   this->x = x;
   this->y = y;
}
void ChangerMode::appliquer(state::Etat* etat)
{
    std::cout << "On va appliquer le changement de mode" << std::endl;
    moteur->setMode(Mode(idMode));
    if (x != -1 && y != -1)
        etat->setSelectionne(x,y);
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