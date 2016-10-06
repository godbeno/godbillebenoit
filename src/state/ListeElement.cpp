#include "ListeElement.h"


void ListeElement::ListeElement()
{
    factory = ElementFactory;
    elements = std::vector<Element*>;
}

void ListeElement::~ListeElement ()
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

void ListeElement::copy (const ListeElement& liste)
{
    this->e = liste->e;
    this->factory = liste->factory;
    this->elements = liste->elements;
}

bool const ListeElement::equals (const ListeElement& other)
{
    return (this->e == other->e && this->factory == other->factory && this->elements == other->elements);
}

int const ListeElement::size ()
{
    return elements.size();
}

Element* const ListeElement::get (int i)
{
    if (i<elements.size()) return elements[i];
}

void ListeElement::clear ()
{
    elements.clear();
}

void ListeElement::setElementFactory* (ElementFactory* f){
{
    this->factory=f;
}

void ListeElement::set (int i, Element* e)
{
    if(this->elements.size() >i){
        elements[i]=e;}{
        elements.resize(int i); elements[i]=e;
    }
}



        


    
