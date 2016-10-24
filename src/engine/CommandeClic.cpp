#include "CommandeClic.h"

using namespace engine;

CommandeClic::CommandeClic(int i, int j)
{
    x = i;
    y = j;
}
CategorieCommande CommandeClic::getCategorie()
{
    return CategorieCommande::clicSouris;
}
int CommandeClic::getX()
{
    return x;
}
int CommandeClic::getY()
{
    return y;
}