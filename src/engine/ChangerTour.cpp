#include "ChangerTour.h"

using namespace engine; 

ChangerTour::ChangerTour()
{
    
}
void ChangerTour::appliquer(state::Etat* etat)
{
    etat->changerTour();
}
void ChangerTour::annuler(state::Etat* etat)
{
    etat->changerTour();
}