#include "Tuile.h"

using namespace render;

Tuile::Tuile(float x, float y, int id)
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