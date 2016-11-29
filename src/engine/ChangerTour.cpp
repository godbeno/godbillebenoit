#include "ChangerTour.h"
#include <iostream>

using namespace engine; 

ChangerTour::ChangerTour(bool afficher)
{
    this->afficher = afficher;
}
void ChangerTour::appliquer(state::Etat* etat)
{
    etat->changerTour(afficher);
}
void ChangerTour::annuler(state::Etat* etat)
{
    //std::cout << "Changement de tour->";
    etat->changerTour(afficher);
}