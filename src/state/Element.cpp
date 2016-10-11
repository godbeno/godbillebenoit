#include "Element.h"
using namespace state;

Element::Element()
{
    x = -1;
    y = -1;
}
Element::~Element()
{
    
}
int const Element::getX()
{
    return x;
}
int const Element::getY()
{
    return y;
}
void Element::setX(int x)
{
    this->x = x;
}
void Element::setY(int  y)
{
    this->y = y;
}