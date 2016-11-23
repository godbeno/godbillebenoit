#include "Tuile.h"

using namespace render;

Tuile::Tuile(float x, float y, int id,int truex,int truey)
{
    this->x = x;
    this->y = y;
    this->id = id;
    this->trueX = truex;
    this->trueY = truey;
}
Tuile::~Tuile()
{
    
}
int const Tuile::getID()
{
    return id;
}
float const Tuile::getX()
{
    return x;
}
float const Tuile::getY()
{
    return y;
}
void Tuile::setX (float x)
{
    this->x = x;
}
void Tuile::setY (float y)
{
    this->y = y;
}
void Tuile::setID (int id)
{
    this->id = id;
}
int Tuile::getTrueX ()
{
    return trueX;
}
int Tuile::getTrueY ()
{
    return trueY;
}
void Tuile::setTrueX (int truex)
{
    this->trueX = truex;
}
void Tuile::setTrueY (int truey)
{
    this->trueY = truey;
}