#include "ChangerMode.h"
#include "Moteur.h"
#include <iostream>

using namespace engine;

ChangerMode::ChangerMode(int IdMode, Moteur *moteur)
{
   this->idMode = IdMode;
   this->moteur = moteur;
}
void ChangerMode::appliquer(state::Etat* etat)
{
    std::cout << "On va appliquer le changement de mode" << std::endl;
    moteur->setMode(Mode(idMode));
}
