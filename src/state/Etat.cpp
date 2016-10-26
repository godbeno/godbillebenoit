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
        std::cout << "On retourne ct " << std::endl;
        v.push_back(ct);
        return v;
    }
    else if (p->getPA() > 0)
    {
        std::cout << "On check l'ensemble des cases" << std::endl;
        int i = ct->getX(), j = ct->getY();
        
        if(grille->getCelluleDecor(i+1,j)) // On vérifie que cette case est accessible par cette case
        {
            if (grille->getCelluleDecor(i+1,j)->estAccessible(Acces::Ouest))
            {
                std::cout << "Ouest ok" << std::endl;
                p->setPArestant(p->getPA()-1);
                v2 = rechercheCaseRec(grille->getCelluleDecor(i+1,j), p);
                p->setPArestant(p->getPA()+1);
                for (unsigned int k = 0; k < v2.size(); k++)
                    if (std::find(v.begin(), v.end(), v2[k]) == v.end())
                        v.push_back(v2[k]);
                if(std::find(v.begin(), v.end(), ct) == v.end())
                    v.push_back(ct);
                v2.clear();
            }
        }
        if(grille->getCelluleDecor(i-1,j)) // On vérifie que cette case est accessible par cette case
        {
            if (grille->getCelluleDecor(i-1,j)->estAccessible(Acces::Est))
            {
                std::cout << "Est ok" << std::endl;
                p->setPArestant(p->getPA()-1);
                v2 = rechercheCaseRec(grille->getCelluleDecor(i-1,j), p);
                p->setPArestant(p->getPA()+1);
                for (unsigned int k = 0; k < v2.size(); k++)
                    if (std::find(v.begin(), v.end(), v2[k]) == v.end())
                        v.push_back(v2[k]);
                if(std::find(v.begin(), v.end(), ct) == v.end())
                    v.push_back(ct);
                v2.clear();
            }
        }
        if(grille->getCelluleDecor(i,j+1)) // On vérifie que cette case est accessible par cette case
        {
            if (grille->getCelluleDecor(i,j+1)->estAccessible(Acces::Nord))
            {
                std::cout << "Nord ok" << std::endl;
                p->setPArestant(p->getPA()-1);
                v2 = rechercheCaseRec(grille->getCelluleDecor(i,j+1), p);
                p->setPArestant(p->getPA()+1);
                for (unsigned int k = 0; k < v2.size(); k++)
                    if (std::find(v.begin(), v.end(), v2[k]) == v.end())
                        v.push_back(v2[k]);
                if(std::find(v.begin(), v.end(), ct) == v.end())
                    v.push_back(ct);
                v2.clear();
            }
        }
        if(grille->getCelluleDecor(i,j-1)) // On vérifie que cette case est accessible par cette case
        {
            if (grille->getCelluleDecor(i,j-1)->estAccessible(Acces::Sud))
            {
                
                std::cout << "Sud ok" << std::endl;
                p->setPArestant(p->getPA()-1);
                v2 = rechercheCaseRec(grille->getCelluleDecor(i,j-1), p);
                p->setPArestant(p->getPA()+1);
                for (unsigned int k = 0; k < v2.size(); k++)
                    if (std::find(v.begin(), v.end(), v2[k]) == v.end())
                        v.push_back(v2[k]);
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
        avertirObservateurs(new EvenementEtat(TypeEvenementEtat(6), this, 0,0, 0,z, 0, 0));       
}

float Etat::getZoom()
{
    return zoom;
}

void Etat::setCamerax(int cx)
{
    this->camerax = cx;
        avertirObservateurs(new EvenementEtat(TypeEvenementEtat(5), this, 0,0, 0,0, cx, 0));
        std::cout << "SETCAMERA X DANS ETAT " << std::endl;  
}

int Etat::getCamerax()
{
    return camerax;
}

void Etat::setCameray(int cy)
{ 
    this->cameray = cy;
    avertirObservateurs(new EvenementEtat(TypeEvenementEtat(5), this, 0,0, 0,0, 0, cy));
    std::cout << "SETCAMERA Y DANS ETAT " << std::endl;  

}

int Etat::getCameray()
{
    return cameray;
}
void Etat::setBrillant(bool b, CaseTerrain* ct)
{
    avertirObservateurs(new EvenementEtat(TypeEvenementEtat(7), this, ct->getX(), ct->getY(), 0,0));
}