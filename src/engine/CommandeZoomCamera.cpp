#include "CommandeZoomCamera.h"

using namespace engine;

CommandeZoomCamera::CommandeZoomCamera(bool haut, int i, int j)
{
    estHaut = haut;
    x = i;
    y = j;
}
CategorieCommande CommandeZoomCamera::getCategorie()
{
    return CategorieCommande::zoomCamera;
}
bool CommandeZoomCamera::getDirection()
{
    return estHaut;
}
int CommandeZoomCamera::getX()
{
    return x;
}
int CommandeZoomCamera::getY()
{
    return y;
}