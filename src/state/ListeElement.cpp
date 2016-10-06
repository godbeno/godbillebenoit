#include "ListeElement.h"


void ListeElement::ListeElement(Etat& e)
{
    this->e = e;
    factory = ElementFactory;
    elements = std::vector<Element*>;
}

void ~ListeElement ()
{
    delete[] elements;
}

ListeElement* const ListeElement::clone (const ListeElement* l)
{
    this->e = l->e;
    this->factory = l->factory;
    this->elements = l->elements;
    return this;
}

void copy (const ListeElement& liste)
{
    this->e = liste->e;
    this->factory = liste->factory;
    this->elements = liste->elements;
}

bool const equals (const ListeElement& other)
{
    return (this->e == other->e && this->factory == other->factory && this->elements == other->elements);
}

int const size ()
{
    return elements.size();
}

Element* const get (int i)
{
    if (i<elements.size()) return elements[i];
}

void clear ()
{
    elements.clear();
}


    
