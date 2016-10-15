#include <SFML/Graphics/Sprite.hpp>
#include <iostream>

#include "TuileStatique.h"

using namespace render;
using namespace sf;


TuileStatique::TuileStatique(int x, int y, int id) : Tuile(x,y,id)
{
    hauteur = 50;
    largeur = 50;
    switch(id)
    {
        case 0: //Herbe
            texture.loadFromFile("../res/Textures/herbe.png");
            break;
        case 52:
            texture.loadFromFile("../res/Textures/Lancier-repos.png");
    }
    sprite.setTexture(texture);
    sprite.setPosition(x,y);
    if (id > 50)
        sprite.setScale(1./6, 1./6);
    else
        sprite.setScale(0.5,0.5);
    //std::cout << "Sprite position : (" << sprite.getPosition().x << ", " << sprite.getPosition().y << ") " << std::endl;
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