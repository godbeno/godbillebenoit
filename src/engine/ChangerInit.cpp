#include "ChangerInit.h"
#include <iostream>

using namespace engine; 

ChangerInit::ChangerInit(int indice, int donnee)
{
	this->indice = indice;
	this->donnee = donnee;
}
void ChangerInit::appliquer(state::Etat* etat)
{
    etat->setDonneesInit(indice,donnee);
}
