#include "ChangerInit.h"
#include <iostream>

using namespace engine; 

ChangerInit::ChangerInit(int indice, int donnee)
{
	this->indice = indice;
	this->donnee = donnee;
}
void ChangerInit::appliquer(state::Etat* etat)
{   int delta = donnee-etat->getDonneesInit(indice);
    etat->setDonneesInit(indice,donnee);
    etat->setDonneesInit(indice-6,etat->getDonneesInit(indice-6)+delta);
}
void ChangerInit::annuler (state::Etat* etat)
{
}