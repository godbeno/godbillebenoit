#include "GrilleElement.h"

void GrilleElement::GrilleElement(Etat& e)
{
    hauteur = 0;
    largeur = 0;
}

void GrilleElement::~GrilleElement ()
{
    delete[] this;
}

int const GrilleElement::getHauteur ()
{
    return hauteur;
}

int const GrilleElement::getLargeur ()
{
    return largeur;
}

Element const GrilleElement::getCellulePersonnage (int i, int j)
{
    for(k=0;k<this.size();k++){
        if(this.elements[k].x == i && this.elements[k].y == j && this.elements[k].estPersonnage)
            return this.elements[k];
    }
}

Element const GrilleElement::getCelluleDecor (int i, int j)
{
    for(k=0;k<this.size();k++){
        if(this.elements[k].x == i && this.elements[k].y == j && not(this.elements[k].estPersonnage))
            return this.elements[k];
    }
}
