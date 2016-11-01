#include "Zoom.h"

using namespace engine;


Zoom::Zoom(int i)
{
   this->i = i;
}  
void Zoom::appliquer (state::Etat* etat)
{
    if(this->i < 0)
    {
        if(etat->getZoom() > 1. )
            etat->setZoom(etat->getZoom()-0.5);
    }
    {
        if(etat->getZoom() < 2. )
            etat->setZoom(etat->getZoom()+0.5);
    }
}
