#include "Zoom.h"
#include <iostream>

using namespace engine;


Zoom::Zoom(int i)
{
   this->i = i;
}  
void Zoom::appliquer (state::Etat* etat)
{
    if(this->i == -1)
    {
        if(etat->getZoom() > 1. )
            etat->setZoom(etat->getZoom()-0.5);
    }
    if(this->i == 1)
    {
        if(etat->getZoom() < 2. )
            etat->setZoom(etat->getZoom()+0.5);
    }
}
void Zoom::annuler (state::Etat* etat)
{
    
    if(this->i == -1)
    {
        if(etat->getZoom() < 2. )
            etat->setZoom(etat->getZoom()+0.5);
    }
    if(this->i == 1)
    {
        if(etat->getZoom() > 1. )
            etat->setZoom(etat->getZoom()-0.5);
    }
}