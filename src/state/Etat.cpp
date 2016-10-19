#include "Etat.h"
#include <iostream>
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

void Etat::initialiserTerrain(bool estChateau)
{
    grille->genererTerrainAleatoire(estChateau);
    liste->copy(*grille);
}

void Etat::ajouterPersonnage(bool equipe, int id, int x, int y)
{
    Personnage* p = new Personnage(equipe, TypePersonnage(id), x, y);
    grille->add(p);
    liste->copy(*grille);
    avertirObservateurs(new EvenementEtat(TypeEvenementEtat(3), this, x, y, id, equipe));
}

void Etat::deplacerElement(int i1, int j1, int i2, int j2)
{
    Personnage* p = grille->getCellulePersonnage(i1,j1);
    if (p != nullptr)
    {
        grille->deplacerElement(p, i2, j2);
        liste->copy(*grille);
        avertirObservateurs(new EvenementEtat(TypeEvenementEtat(1), this, i1,j1, p->getID(),p->getEquipe(), i2, j2));
    }
    else
    {
        std::cout << "pointeur null " << std::endl;
    }
}