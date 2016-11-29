#include "Couche.h"
#include "Bouton.h"
#include <iostream>
#include <stdlib.h>

using namespace render;

Bouton::Bouton(int ID, bool Actif)
{
    this->ID = ID;
    this->Actif = Actif;
    
}

void Bouton::setID(int ID)
{
    this->ID = ID;
}
int Bouton::getID()
{
    return ID;
}

void Bouton::setActif(bool Actif)
{
    this->Actif = Actif;
}
bool Bouton::getActif()
{
    return Actif;
}