#include "ChangerTour.h"

using namespace engine; 

ChangerTour::ChangerTour()
{
    
}
void ChangerTour::appliquer(state::Etat* etat, bool afficher)
{
    etat->changerTour(afficher);
}
void ChangerTour::annuler(state::Etat* etat, bool afficher)
{
    etat->changerTour(afficher);
}