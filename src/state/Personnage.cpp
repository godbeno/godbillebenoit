#include "Personnage.h"
#include "Element.h"

Personnage::Personnage(bool equipe, TypePersonnage type)
{
    orientation = true;
    id = type;
    this->equipe = equipe;
    switch(type)
    {
        case Spadassin:
            pvMax = 200;
            paMax = 4;
            porteeMin = 1;
            porteeMax = 1;
            attaque = 75;
            break;
        case Lancier:
            pvMax = 150;
            paMax = 4;
            porteeMin = 1;
            porteeMax = 2;
            attaque = 50;
            break;
        case Archer:
            pvMax = 100;
            paMax = 5;
            porteeMin = 2;
            porteeMax = 5;
            attaque = 50;
            break;
        case Canon:
            pvMax = 200;
            paMax = 2;
            porteeMin = 3;
            porteeMax = 6;
            attaque = 150;
            break;
        case Cavalier:
            pvMax = 200;
            paMax = 7;
            porteeMin = 1;
            porteeMax = 1;
            attaque = 100;
            break;
        case Roi:
            pvMax = 500;
            paMax = 4;
            porteeMin = 1;
            porteeMax = 1;
            attaque = 125;
            break;
            
    }
    pv = pvMax;
    pa = paMax;
    
    
}
bool const Personnage::estPersonnage()
{
    return true;
}
int const Personnage::getPV ()
{
    return pv;
}
int Personnage::getPA ()
{
    return pa;
}
bool const Personnage::getOrientation()
{
    return orientation;
}
int const Personnage::getID ()
{
    return id;
}
bool const Personnage::getEquipe ()
{
    return equipe;
}
int const Personnage::getPVMax ()
{
    return pvMax;
}
int const Personnage::getPAMax ()
{
    return paMax;
}

void Personnage::setPVrestant (int pv)
{
    this->pv = pv;
}
void Personnage::setPArestant (int pa)
{
    this->pa = pa;
}
bool const Personnage::equals(const Personnage &p)
{
    return (p.getID() == id && p.getPV() == pv && p.getX() == getX() && p.getY() == getY() && p.getEquipe() == equipe);
}
void Personnage::clone (const Personnage* p)
{
    orientation = p->getOrientation();
    pv = p->getPV();
    pa = p->getPA();
    id = p->getID();
    equipe = p->getEquipe();
    pvMax = p->getPVMax();
    paMax = p->getPAMax()
    porteeMax = p->getPorteeMax();
    porteeMin = p->getPorteeMin();
    attaque = p->getAttaque();
}
int const Personnage::getPorteeMax ()
{
    return porteeMax;
}
int const Personnage::getPorteeMin ()
{
    return porteeMin;
}
int const Personnage::getAttaque ()
{
    return attaque;
}
TypePersonnage Personnage::getType ()
{
    return TypePersonnage(id);
}



