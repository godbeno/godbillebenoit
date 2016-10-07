#include "GrilleElement.h"

GrilleElement::GrilleElement(Etat& e)
{
    hauteur = 0;
    largeur = 0;
}
int const GrilleElement::getHauteur ()
{
    return hauteur;
}

int const GrilleElement::getLargeur ()
{
    return largeur;
}

Personnage* const GrilleElement::getCellulePersonnage (int i, int j)
{
    for(unsigned int k=0;k<elements.size();k++){
        if(this->elements[k]->getX() == i && this->elements[k]->getY() == j && this->elements[k]->estPersonnage())
            return static_cast<Personnage*>(this->elements[k]);
    }
    return nullptr;
}

CaseTerrain* const GrilleElement::getCelluleDecor (int i, int j)
{
    for(unsigned int k=0;k<elements.size();k++){
        if(this->elements[k]->getX() == i && this->elements[k]->getY() == j && not(this->elements[k]->estPersonnage()))
            return static_cast<CaseTerrain*>(this->elements[k]);
    }
    return nullptr;
}
