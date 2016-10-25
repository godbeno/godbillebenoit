#include "CommandeClic.h"
#include <iostream>

using namespace engine;


CommandeClic::CommandeClic (int i, int j)
{
    x = i;
    y = j;
    std::cout << "Création d'un événement clic !" << std::endl;
}
CategorieCommande CommandeClic::getCategorie ()
{
    return CategorieCommande::clicSouris;
}
int CommandeClic::getX ()
{
    return x;
}
int CommandeClic::getY ()
{
    return y;
}
