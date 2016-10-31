#include "Etat.h"
#include <iostream>
#include <algorithm>
#include <SFML/Graphics.hpp>
using namespace state;

Etat::Etat ()
{
    liste = new ListeElement(this);
    grille = new GrilleElement(this);
    camerax = 0;
    cameray = 0;
    zoom = 1;
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
        p->setPArestant(p->getPA()-(abs(i1-i2)+abs(j1-j2)));
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
    std::cout << "On traite le changement de selection dans Etat" << std::endl;
    selectionne = grille->getCellulePersonnage(i, j);
    avertirObservateurs(new EvenementEtat(TypeEvenementEtat(8), this, i, j, 0, 0));
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
    p->setPArestant(y);
    for(unsigned int i = 0; i < v.size(); i++)
        if (v[i] == ct)
            v.erase(v.begin()+i);
    return v;
}
std::vector<CaseTerrain*> Etat::rechercheCaseRec(CaseTerrain* ct, Personnage* p)
{
    std::vector<CaseTerrain*> v, v2;
    if (p->getPA() == 0)
    {
        v.push_back(ct);
    }
    else if (p->getPA() > 0)
    {
        int i = ct->getX(), j = ct->getY();
        
        if(grille->getCelluleDecor(i+1,j)) // On vérifie que cette case est accessible par cette case
        {
            if (grille->getCelluleDecor(i+1,j)->estAccessible(Acces::Ouest)
                    && ct->estAccessible(Acces::Est)
                    && grille->getCellulePersonnage(i+1, j) == nullptr)
            {
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
            if (grille->getCelluleDecor(i-1,j)->estAccessible(Acces::Est)
                    && ct->estAccessible(Acces::Ouest)
                    && grille->getCellulePersonnage(i-1, j) == nullptr)
            {
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
            if (grille->getCelluleDecor(i,j+1)->estAccessible(Acces::Nord)
                    && ct->estAccessible(Acces::Sud)
                    && grille->getCellulePersonnage(i, j+1) == nullptr)
            {
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
            if (grille->getCelluleDecor(i,j-1)->estAccessible(Acces::Sud)
                    && ct->estAccessible(Acces::Nord)
                    && grille->getCellulePersonnage(i, j-1) == nullptr)
            {
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
    }
    return v;
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
        std::cout << "SETCAMERA X DANS ETAT DE VALEUR " << cx << std::endl;  
}

int Etat::getCamerax()
{
    return camerax;
}

void Etat::setCameray(int cy)
{ 
    this->cameray = cy;
    avertirObservateurs(new EvenementEtat(TypeEvenementEtat(5), this, 0,0, 0,0, 0, cy));
    std::cout << "SETCAMERA Y DANS ETAT DE VALEUR " << cy << std::endl;  

}

int Etat::getCameray()
{
    return cameray;
}
void Etat::setBrillant(bool b, CaseTerrain* ct)
{
    if (b)
        avertirObservateurs(new EvenementEtat(TypeEvenementEtat(7), this, ct->getX(), ct->getY(), 0, true));
    else
        avertirObservateurs(new EvenementEtat(TypeEvenementEtat(7), this, 0, 0, 0, false));
        
}
float Etat::getCoeff()
{
    return (sf::VideoMode::getDesktopMode().width*zoom)/24.;
}
std::vector<CaseTerrain*> Etat::getCaseAttaquable(Personnage *p)
{
    std::vector<CaseTerrain*> v;
    bool equipe = p->getEquipe();
    int cx = p->getX();
    int cy = p->getY();
    for (int z = p->getPorteeMin(); z <= p->getPorteeMax(); z++)
    {
        for (int i = 0; i <= z; i++)
        {
            
            if (grille->getCellulePersonnage(cx-z+i, cy-i))
                if (grille->getCellulePersonnage(cx-z+i, cy-i)->getEquipe() != equipe)
                    if (std::find(v.begin(), v.end(), grille->getCelluleDecor(cx-z+i, cy-i)) == v.end())
                        v.push_back(grille->getCelluleDecor(cx-z+i, cy-i));
            if (grille->getCellulePersonnage(cx-z+i, cy+i))
                if (grille->getCellulePersonnage(cx-z+i, cy+i)->getEquipe() != equipe)
                    if (std::find(v.begin(), v.end(), grille->getCelluleDecor(cx-z+i, cy+i)) == v.end())
                        v.push_back(grille->getCelluleDecor(cx-z+i, cy+i));
            if (grille->getCellulePersonnage(cx+z-i, cy-i))
                if (grille->getCellulePersonnage(cx+z-i, cy-i)->getEquipe() != equipe)
                    if (std::find(v.begin(), v.end(), grille->getCelluleDecor(cx+z-i, cy-i)) == v.end())
                        v.push_back(grille->getCelluleDecor(cx+z-i, cy-i));
            if (grille->getCellulePersonnage(cx+z-i, cy+i))
                if (grille->getCellulePersonnage(cx+z-i, cy+i)->getEquipe() != equipe)
                    if (std::find(v.begin(), v.end(), grille->getCelluleDecor(cx+z-i, cy+i)) == v.end())
                        v.push_back(grille->getCelluleDecor(cx+z-i, cy+i));
        }
    }
    return v;
}
void Etat::setRouge(bool b, CaseTerrain* ct)
{
    if (b)
        avertirObservateurs(new EvenementEtat(TypeEvenementEtat(9), this, ct->getX(), ct->getY(), 0, true));
    else
        avertirObservateurs(new EvenementEtat(TypeEvenementEtat(9), this, 0, 0, 0, false));
}