#include "CommandeClic.h"
#include <iostream>

using namespace engine;


CommandeClic::CommandeClic (int i, int j, int bouton)
{
    x = i;
    y = j;
    this->bouton = bouton;
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
int CommandeClic::getBouton()
{
    return bouton;
}
