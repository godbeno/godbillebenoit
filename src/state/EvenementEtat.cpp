#include "EvenementEtat.h"

using namespace state;

EvenementEtat::EvenementEtat(TypeEvenementEtat id, Etat* etat)
{
    this->id = id;
    this->etat = etat;
}
const TypeEvenementEtat EvenementEtat::getTypeEvenement()
{
    return id;
}