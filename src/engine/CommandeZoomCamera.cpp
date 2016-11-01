#include "CommandeZoomCamera.h"

using namespace engine;

CommandeZoomCamera::CommandeZoomCamera(int i)
{
    this->i = i;
}
CategorieCommande CommandeZoomCamera::getCategorie()
{
    return CategorieCommande::zoomCamera;
}
int CommandeZoomCamera::geti()
{
    return i;
}