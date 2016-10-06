#include "Etat.h"

void Etat::Etat ()
{
    ListeElement = ListeElement::ListeElement();
    GrilleElement = GrilleElement::GrilleElement();
}

void Etat::~Etat ()
{
    delete[] this;
}

Etat* const Etat::clone (const Etat* e)
{
    this->ListeElement = e->ListeElement;
    this->GrilleElement = e->GrilleElement;
    return this;
}

void Etat::copy (const Etat* e)
{
    this->ListeElement = e->ListeElement;
    this->GrilleElement = e->GrilleElement;
}

bool const Etat::equals (const Etat* e)
{
    return (this->ListeElement == e->ListeElement && this->GrilleElement = e->GrilleElement);
}

GrilleElement getGrille ()
{
    return GrilleElement;
}

ListeElement getListe()
{
    return ListeElement;
}

void setGrille (const GrilleElement grille)
{
    this->GrilleElement = grille;
}

void setListe (const ListeElement liste)
{
    this->ListeElement = liste

