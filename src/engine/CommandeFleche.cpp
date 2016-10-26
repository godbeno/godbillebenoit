#include "CommandeFleche.h"
#include <iostream>

using namespace engine;

CommandeFleche::CommandeFleche(Direction direction)
{
    this->direction = direction;
     std::cout << "Création d'un événement fleche !" << std::endl;
}
CategorieCommande CommandeFleche::getCategorie()
{
    return CategorieCommande::deplacementCamera;
}
Direction CommandeFleche::getDirection()
{
    return direction;
}