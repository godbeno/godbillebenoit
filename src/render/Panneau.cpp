#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <iostream>

#include "Panneau.h"

using namespace render;

Panneau::Panneau()
{
    
    int largeur = sf::VideoMode::getDesktopMode().width;
    int hauteur = sf::VideoMode::getDesktopMode().height;
    
    textFond.loadFromFile("res/Textures/Barre-menu.png");
    textBoutA.loadFromFile("res/Textures/Bouton-attaque-Off.png");
    textBoutD.loadFromFile("res/Textures/Bouton-déplacement-Off.png");
    
    fond.setTexture(textFond);
    boutA.setTexture(textBoutA);
    boutD.setTexture(textBoutD);
    
    fond.setPosition(largeur/2 - 195, hauteur-150);
    boutA.setPosition(largeur/2 - 150, hauteur-125);
    boutD.setPosition(largeur/2 - 75, hauteur-125);
    fond.setScale(2,2);
    
    //rajouter PA et PV etc 
    
}
void Panneau::draw(sf::RenderWindow* window)
{
    window->draw(fond);
    window->draw(boutA);
    window->draw(boutD);
}