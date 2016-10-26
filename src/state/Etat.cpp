#include "Etat.h"
#include <iostream>
#include <algorithm>
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

GrilleElement& Etat::getGrille ()
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
        std::cout << "Les observateurs ont été notifiés" << std::endl;
    }
    else
    {
        std::cout << "pointeur null " << std::endl;
    }
}

Personnage* Etat::getSelectionne()
{
    return selectionne;
}
void Etat::setSelectionne(int i, int j)
{
    selectionne = grille->getCellulePersonnage(i, j);
}
void Etat::attaquer(int i1, int j1, int i2, int j2)
{
    Personnage* p1 = grille->getCellulePersonnage(i1,j1);
    Personnage* p2 = grille->getCellulePersonnage(i2,j2);
    if (p1 != nullptr && p2 != nullptr)
    {
        //Compléter
    }
}
std::vector<CaseTerrain*> Etat::getCaseAtteignable(Personnage* p)
{
    CaseTerrain* ct = grille->getCelluleDecor(p->getX(), p->getY());
    int y = p->getPA();
    std::vector<CaseTerrain*> v = rechercheCaseRec(ct, p);
    std::cout << "taille à la fin de la recherche : " << v.size() << std::endl;
    p->setPArestant(y);
    return v;
}
std::vector<CaseTerrain*> Etat::rechercheCaseRec(CaseTerrain* ct, Personnage* p)
{
    std::vector<CaseTerrain*> v, v2;
    if (p->getPA() == 0)
    {
        v.push_back(ct);
        return v;
    }
    else if (p->getPA() > 0)
    {
        int i = ct->getX(), j = ct->getY();
        p->setPArestant(p->getPA()-1);
        
        if(grille->getCelluleDecor(i+1,j)) // On vérifie que cette case est accessible par cette case
        {
            if (grille->getCelluleDecor(i+1,j)->estAccessible(Acces::Ouest))
            {
                v = rechercheCaseRec(grille->getCelluleDecor(i+1,j), p);
                if(std::find(v.begin(), v.end(), ct) == v.end()) 
                {
                    v.push_back(ct);
                }
            }
        }
        if(grille->getCelluleDecor(i-1,j)) // On vérifie que cette case est accessible par cette case
        {
            if (grille->getCelluleDecor(i-1,j)->estAccessible(Acces::Est))
            {
                v2 = rechercheCaseRec(grille->getCelluleDecor(i-1,j), p);
                for (unsigned int i = 0; i < v2.size(); i++)
                    if (std::find(v.begin(), v.end(), v2[i]) == v.end())
                        v.push_back(v2[i]);
                if(std::find(v.begin(), v.end(), ct) == v.end())
                    v.push_back(ct);
                v2.clear();
            }
        }
        if(grille->getCelluleDecor(i,j+1)) // On vérifie que cette case est accessible par cette case
        {
            if (grille->getCelluleDecor(i,j+1)->estAccessible(Acces::Nord))
            {
                v2 = rechercheCaseRec(grille->getCelluleDecor(i,j+1), p);
                for (unsigned int i = 0; i < v2.size(); i++)
                    if (std::find(v.begin(), v.end(), v2[i]) == v.end())
                        v.push_back(v2[i]);
                if(std::find(v.begin(), v.end(), ct) == v.end())
                    v.push_back(ct);
                v2.clear();
            }
        }
        if(grille->getCelluleDecor(i,j-1)) // On vérifie que cette case est accessible par cette case
        {
            if (grille->getCelluleDecor(i,j-1)->estAccessible(Acces::Sud))
            {
                v2 = rechercheCaseRec(grille->getCelluleDecor(i,j-1), p);
                for (unsigned int i = 0; i < v2.size(); i++)
                    if (std::find(v.begin(), v.end(), v2[i]) == v.end())
                        v.push_back(v2[i]);
                if(std::find(v.begin(), v.end(), ct) == v.end())
                    v.push_back(ct);
                v2.clear();
            }
        }
        std::cout << "Dans cette recherche: v = " << v.size() << std::endl;
        return v;
    }
}

void Etat::setZoom(float z)
{
    this->zoom = z ;
}

float Etat::getZoom()
{
    return zoom;
}

void Etat::setCamerax(int cx)
{
    this->camerax = cx;
}

int Etat::getCamerax()
{
    return camerax;
}

void Etat::setCameray(int cy)
{ 
    this->cameray = cy;
}

int Etat::getCameray()
{
    return cameray;
}