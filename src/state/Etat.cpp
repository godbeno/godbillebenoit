#include "Etat.h"
using namespace state;

Etat::Etat ()
{
    liste = new ListeElement;
    grille = new GrilleElement(*this);
}

Etat::~Etat ()
{
    delete liste;
    delete grille;
}

Etat* const Etat::clone ()
{
    Etat* e = new Etat;
    e->liste = this->liste;
    e->grille = this->grille;
    return e;
}

void Etat::copy (const Etat& e)
{
    this->liste = e.liste;
    this->grille = e.grille;
}

bool const Etat::equals (const Etat& e)
{
    return (this->liste == e.liste && this->grille == e.grille);
}

const GrilleElement& Etat::getGrille () const
{
    return *grille;
}

const ListeElement& Etat::getListe() const
{
    return *liste;
}

void Etat::setGrille (const GrilleElement& grille)
{
    *(this->grille) = grille;
}

void Etat::setListe (const ListeElement& liste)
{
    *(this->liste) = liste;
}

void Etat::initialiserTerrain()
{
    grille->genererTerrainAleatoire();
}

void Etat::ajouterPersonnage(bool equipe, int id)
{
    Personnage* p = new Personnage(equipe, TypePersonnage(id));
    liste->add(p);
}