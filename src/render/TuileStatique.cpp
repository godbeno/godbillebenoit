#include <SFML/Graphics/Sprite.hpp>

#include "TuileStatique.h"

using namespace render;
using namespace sf;


TuileStatique::TuileStatique(int x, int y, int id) : Tuile(x,y,id)
{
    hauteur = 100;
    largeur = 100;
    switch(id)
    {
        case 0: //Herbe
            texture.loadFromFile("res/herbe.png");
            break;
    }
    sprite.setTexture(texture);
}
TuileStatique::~TuileStatique()
{
    
}
int const TuileStatique::getHauteur()
{
    return hauteur;
}
int const TuileStatique::getLargeur()
{
    return largeur;
}
void TuileStatique::setHauteur(int hauteur)
{
    this->hauteur = hauteur;
}
void TuileStatique::setLargeur(int largeur)
{
    this->largeur = largeur;
}
const sf::Sprite& TuileStatique::getSprite ()
{
    return sprite;
}
bool TuileStatique::estAnime ()
{
    return false;
}