#include "Tuile.h"

using namespace render;

Tuile::Tuile(int x, int y, int id)
{
    this->x = x;
    this->y = y;
    this->id = id;
}
Tuile::~Tuile()
{
    
}
int const Tuile::getID()
{
    return id;
}
int const Tuile::getX()
{
    return x;
}
int const Tuile::getY()
{
    return y;
}
void Tuile::setX (int x)
{
    this->x = x;
}
void Tuile::setY (int y)
{
    this->y = y;
}
void Tuile::setID (int id)
{
    this->id = id;
}