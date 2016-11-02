#include "Zoom.h"
#include <iostream>

using namespace engine;


Zoom::Zoom(int i)
{
   this->i = i;
}  
void Zoom::appliquer (state::Etat* etat)
{
    std::cout << "Zoom est appliqué avec l'argument " << i << std::endl;
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
