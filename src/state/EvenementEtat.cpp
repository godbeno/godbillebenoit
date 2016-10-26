#include "EvenementEtat.h"

using namespace state;

EvenementEtat::EvenementEtat(TypeEvenementEtat id, Etat* etat, int x, int y, int pid, bool equipe, int newX, int newY, float zoom)
{
    this->id = id;
    this->etat = etat;
    this->x = x;
    this->y = y;
    this->pid = pid*2 + 43 + !equipe;
    this->newX = newX;
    this->newY = newY;
    this->zoom = zoom;
    
}
TypeEvenementEtat EvenementEtat::getTypeEvenement()
{
    return id;
}
int EvenementEtat::getX()
{
    return x;
}
int EvenementEtat::getY()
{
    return y;
}
int EvenementEtat::getPid()
{
    return pid;
}
int EvenementEtat::getNewx()
{
    return newX;
}
int EvenementEtat::getNewy()
{
    return newY;
}

float EvenementEtat::getZoom()
{
    return zoom;
}
