#include "Couche.h"
#include "Bouton.h"
#include <iostream>
#include <stdlib.h>

using namespace render;

Bouton::Bouton(int ID)
{
    this->ID = ID;
    
    int largeur = sf::VideoMode::getDesktopMode().width;
    int hauteur = sf::VideoMode::getDesktopMode().height;
    sf::Sprite sprite;
    sf::Texture texture;
    sf::Text texte;
    sf::Font font;
    font.loadFromFile("res/Fonts/arial.ttf");
    
    switch(ID)
    {
        case 1 :
                texture.loadFromFile("res/Textures/Barre-menu.png");
                sprite.setTexture(texture);
                sprite.setPosition(0,0);
                
                texte.setFont(font);
                texte.setString("Test");
                texte.setPosition(0, 0);
                texte.setColor(sf::Color::White);
                texte.setCharacterSize(30);    
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
