#include "Etat.h"
using namespace state;

Etat::Etat ()
{
    liste = new ListeElement(this);
    grille = new GrilleElement(this);
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

const GrilleElement& Etat::getGrille ()
{
    return *grille;
}

const ListeElement& Etat::getListe()
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
    liste->copy(*grille);
}

void Etat::ajouterPersonnage(bool equipe, int id, int x, int y)
{
    Personnage* p = new Personnage(equipe, TypePersonnage(id), x, y);
    liste->add(p);
    avertirObservateurs(new EvenementEtat(TypeEvenementEtat(3), this));
}