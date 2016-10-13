#include "Scene.h"
#include <iostream>

using namespace render;

Scene::Scene()
{
    coucheTerrain = new Couche();
    couchePersonnage = new Couche();
}
void Scene::changementEtat(state::EvenementEtat& e)
{
    if (e.getTypeEvenement() == state::NouveauPersonnage)
    {
        std::cout << "Un nouveau personnage a été créé" << std::endl;
    }
}