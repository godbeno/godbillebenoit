#include "Scene.h"

using namespace render;

Scene::Scene()
{
    coucheTerrain = new Couche();
    couchePersonnage = new Couche();
}
Scene::changementEtat(const EvenementEtat& e)
{
    if (e.getTypeEvenement() == NouveauPersonnage)
    {
        std::cout << "Un nouveau personnage a été créé" << std::endl;
    }
}