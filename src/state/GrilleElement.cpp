#include "GrilleElement.h"
#include <iostream>
using namespace state;

GrilleElement::GrilleElement(Etat* e) : ListeElement(e)
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

void GrilleElement::genererTerrainAleatoire()
{
    for (int i = 0; i < 20; i++)
        for (int j = 0; j < 20; j++)
        {
            elements.push_back(new CaseTerrain(1));
            elements[i*20+j]->setX(i);
            elements[i*20+j]->setY(j);
        }
    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            std::cout << elements[i*20+j]->getID();
        }
        std::cout << std::endl;
    }
}