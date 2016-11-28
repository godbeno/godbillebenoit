#include "Zoom.h"
#include <iostream>

using namespace engine;


Zoom::Zoom(int i)
{
   this->i = i;
}  
void Zoom::appliquer (state::Etat* etat, bool afficher)
{
    if(this->i == -1)
    {
        if(etat->getZoom() > 1. )
            etat->setZoom(etat->getZoom()-0.5, afficher);
    }
    if(this->i == 1)
    {
        if(etat->getZoom() < 2. )
            etat->setZoom(etat->getZoom()+0.5, afficher);
    }
}
void Zoom::annuler (state::Etat* etat, bool afficher)
{
    
    if(this->i == -1)
    {
        if(etat->getZoom() < 2. )
            etat->setZoom(etat->getZoom()+0.5, afficher);
    }
    if(this->i == 1)
    {
        if(etat->getZoom() > 1. )
            etat->setZoom(etat->getZoom()-0.5, afficher);
    }
}