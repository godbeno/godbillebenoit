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
    largeur = sf::VideoMode::getDesktopMode().width;
    hauteur = sf::VideoMode::getDesktopMode().height;
    this->aTexte = false;
    font.loadFromFile("res/Fonts/arial.ttf");
    initBouton(ID);
    
}


void Bouton::initBouton(int ID)    
{
    switch(ID)
    {
        case 1 :
                texture.loadFromFile("res/Textures/Bouton-attaque-On.png");
                sprite.setTexture(texture);
                sprite.setPosition(largeur/2-185,hauteur-105);
                break;
        case 2 :
                texture.loadFromFile("res/Textures/Bouton-attaque-Off.png");
                sprite.setTexture(texture);
                sprite.setPosition(largeur/2-185,hauteur-105);
                break;
                
                
        case 3 :
                texture.loadFromFile("res/Textures/Bouton-déplacement-On.png");
                sprite.setTexture(texture);
                sprite.setPosition(largeur/2-115,hauteur-105);
                break;
        case 4 :
                texture.loadFromFile("res/Textures/Bouton-déplacement-Off.png");
                sprite.setTexture(texture);
                sprite.setPosition(largeur/2-115,hauteur-105);
                break;
                
                
                
        case 5 :
                texture.loadFromFile("res/Textures/Bouton-On.png");
                sprite.setTexture(texture);
                sprite.setPosition(3*largeur/4,hauteur-125);
                sprite.setScale(3,3);
                
                aTexte = true;
                texte.setFont(font);
                texte.setString("Fin de Tour");
                texte.setPosition(3*largeur/4+50,hauteur-100);
                texte.setColor(sf::Color::Black);
                texte.setCharacterSize(30);
                break; 
                
        case 6 :
                texture.loadFromFile("res/Textures/Bouton-Off.png");
                sprite.setTexture(texture);
                sprite.setPosition(3*largeur/4,hauteur-125);
                sprite.setScale(3,3);     
                aTexte = true;
                texte.setFont(font);
                texte.setString("   Attente");
                texte.setPosition(3*largeur/4+50,hauteur-100);
                texte.setColor(sf::Color::Black);
                texte.setCharacterSize(30);
                break; 
    }
}
    
    

    


  

void Bouton::setID(int ID)
{
    this->ID = ID;
    initBouton(ID);
}
int Bouton::getID()
{
    return ID;
}
sf::Sprite Bouton::getSprite()
{
    return sprite;
}
bool Bouton::getATexte()
{
    return aTexte;
}
sf::Text Bouton::getTexte()
{
    return texte;
}