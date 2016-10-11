#include "ListeElement.h"
#include "Etat.h"
#include <iostream>

using namespace state;

ListeElement::ListeElement(Etat* e)
{
    elements.clear();
    this->e = e;
}

ListeElement::~ListeElement()
{
    for (unsigned int i = 0; i < elements.size(); i++)
    {
        delete elements[i];
    }
}

ListeElement* const ListeElement::clone()
{
    ListeElement* l = new ListeElement(this->e->clone());
    l->elements = this->elements;
    return l;
}

void ListeElement::copy (const ListeElement& liste)
{
    this->e = liste.e->clone();
    this->elements = liste.elements;
}

bool const ListeElement::equals (const ListeElement& other)
{
    return (this->elements == other.elements);
}

int const ListeElement::size ()
{
    return elements.size();
}

Element* const ListeElement::get (int i)
{
    if (static_cast<unsigned int>(i) <elements.size()) 
        return elements[i];
    else
        return nullptr;
}

void ListeElement::clear ()
{
    elements.clear();
}


void ListeElement::set (int i, Element* e)
{
    if(elements.size() > static_cast<unsigned int>(i))
        elements[i]=e;
    else
        elements.push_back(e);
}

void ListeElement::add(Element* n)
{
    elements.push_back(n);
}

        


    
