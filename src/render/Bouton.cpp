#include "Couche.h"
#include "Bouton.h"
#include <iostream>
#include <stdlib.h>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "Panneau.h"
#include <string>

using namespace render;

Bouton::Bouton(int ID)
{
    this->ID = ID;
    int largeur = sf::VideoMode::getDesktopMode().width;
    int hauteur = sf::VideoMode::getDesktopMode().height;

    font.loadFromFile("res/Fonts/arial.ttf");
    
    switch(ID)
    {
        case 1 :
                texture.loadFromFile("res/Textures/Bouton-déplacement-On.png");
                sprite.setTexture(texture);
                sprite.setPosition(largeur/2,hauteur/2);
                break;
        case 2 :
                break;
            
                
        
    }
    
    

    


    
    //fond.setPosition(largeur/2 - 195, hauteur-120);
    
    //fond.setScale(2,2);
    /*
    nom.setFont(font);
    nom.setString("Archer");
    nom.setPosition(largeur/2, hauteur-100);
    nom.setColor(sf::Color::White);
    nom.setCharacterSize(30);
    */
    
    
    
    
    
}

void Bouton::setID(int ID)
{
    this->ID = ID;
}
int Bouton::getID()
{
    return ID;
}
sf::Sprite Bouton::getSprite()
{
    return sprite;
}
