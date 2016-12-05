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
        case 100 :
                texture.loadFromFile("res/Textures/Bouton-attaque-On.png");
                sprite.setTexture(texture);
                sprite.setPosition(largeur/2-185,hauteur-105);
                break;
        case 101 :
                texture.loadFromFile("res/Textures/Bouton-attaque-Off.png");
                sprite.setTexture(texture);
                sprite.setPosition(largeur/2-185,hauteur-105);
                break;
                
                
        case 102 :
                texture.loadFromFile("res/Textures/Bouton-déplacement-On.png");
                sprite.setTexture(texture);
                sprite.setPosition(largeur/2-115,hauteur-105);
                break;
        case 103 :
                texture.loadFromFile("res/Textures/Bouton-déplacement-Off.png");
                sprite.setTexture(texture);
                sprite.setPosition(largeur/2-115,hauteur-105);
                break;
                
                
                
        case 104 :
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
                
        case 105 :
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
                
                /* ------------------INITIALISATION ----------------------*/
        case 10 :
                texture.loadFromFile("res/Textures/case-grise.png");
                sprite.setTexture(texture);
                sprite.setPosition(0,0);
                sprite.setScale(1.2,1.2);
                break;
        case 11 :
                texture.loadFromFile("res/Textures/Archer-attaque.png");
                sprite.setTexture(texture);
                sprite.setPosition(0,30);
                sprite.setScale(0.7,0.7);
                
                aTexte = true;
                texte.setFont(font);
                texte.setString("Archer (8pts)");
                texte.setPosition(5,0);
                texte.setColor(sf::Color::White);
                texte.setCharacterSize(18);
                
                break;            
        case 12 :
                texture.loadFromFile("res/Textures/plus.png");
                sprite.setTexture(texture);
                sprite.setPosition(80,25);
                sprite.setScale(1.5,1.5);
                break;            
        case 13 :
                texture.loadFromFile("res/Textures/moins.png");
                sprite.setTexture(texture);
                sprite.setPosition(80,65);
                sprite.setScale(1.5,1.5);
                break;
        case 14 :
                aTexte = true;
                texte.setFont(font);
                texte.setString("A / B");
                texte.setPosition(25,95);
                texte.setColor(sf::Color::White);
                texte.setCharacterSize(20);
                break;     
                
                
                
                
        case 20 :
                texture.loadFromFile("res/Textures/case-grise.png");
                sprite.setTexture(texture);
                sprite.setPosition(0,120);
                sprite.setScale(1.2,1.2);
                break;
        case 21 :
                texture.loadFromFile("res/Textures/Lancier-attaque.png");
                sprite.setTexture(texture);
                sprite.setPosition(0,150);
                sprite.setScale(0.7,0.7);
                
                aTexte = true;
                texte.setFont(font);
                texte.setString("Lancier (6pts)");
                texte.setPosition(5,120);
                texte.setColor(sf::Color::White);
                texte.setCharacterSize(18);
                
                break;            
        case 22 :
                texture.loadFromFile("res/Textures/plus.png");
                sprite.setTexture(texture);
                sprite.setPosition(80,145);
                sprite.setScale(1.5,1.5);
                break;            
        case 23 :
                texture.loadFromFile("res/Textures/moins.png");
                sprite.setTexture(texture);
                sprite.setPosition(80,185);
                sprite.setScale(1.5,1.5);
                break;
        case 24 :
                aTexte = true;
                texte.setFont(font);
                texte.setString("A / B");
                texte.setPosition(25,215);
                texte.setColor(sf::Color::White);
                texte.setCharacterSize(20);
                break;
                
                
                
                
                
        case 30 :
                texture.loadFromFile("res/Textures/case-grise.png");
                sprite.setTexture(texture);
                sprite.setPosition(0,240);
                sprite.setScale(1.2,1.2);
                break; 
        case 31 :
                texture.loadFromFile("res/Textures/Capitaine-attaque.png");
                sprite.setTexture(texture);
                sprite.setPosition(0,270);
                sprite.setScale(0.7,0.7);
                
                aTexte = true;
                texte.setFont(font);
                texte.setString("Capitaine (12pts)");
                texte.setPosition(5,240);
                texte.setColor(sf::Color::White);
                texte.setCharacterSize(15);
                
                break;            
        case 32 :
                texture.loadFromFile("res/Textures/plus.png");
                sprite.setTexture(texture);
                sprite.setPosition(80,265);
                sprite.setScale(1.5,1.5);
                break;            
        case 33 :
                texture.loadFromFile("res/Textures/moins.png");
                sprite.setTexture(texture);
                sprite.setPosition(80,305);
                sprite.setScale(1.5,1.5);
                break;
        case 34 :
                aTexte = true;
                texte.setFont(font);
                texte.setString("A / B");
                texte.setPosition(25,335);
                texte.setColor(sf::Color::White);
                texte.setCharacterSize(20);
                break;             
                
                
                
                
        case 40 :
                texture.loadFromFile("res/Textures/case-grise.png");
                sprite.setTexture(texture);
                sprite.setPosition(0,360);
                sprite.setScale(1.2,1.2);
                break;
        case 41 :
                texture.loadFromFile("res/Textures/canon-tir.png");
                sprite.setTexture(texture);
                sprite.setPosition(0,390);
                sprite.setScale(0.7,0.7);
                
                aTexte = true;
                texte.setFont(font);
                texte.setString("Canon (20pts)");
                texte.setPosition(5,360);
                texte.setColor(sf::Color::White);
                texte.setCharacterSize(17);
                
                break;            
        case 42 :
                texture.loadFromFile("res/Textures/plus.png");
                sprite.setTexture(texture);
                sprite.setPosition(80,385);
                sprite.setScale(1.5,1.5);
                break;            
        case 43 :
                texture.loadFromFile("res/Textures/moins.png");
                sprite.setTexture(texture);
                sprite.setPosition(80,425);
                sprite.setScale(1.5,1.5);
                break;
        case 44 :
                aTexte = true;
                texte.setFont(font);
                texte.setString("A / B");
                texte.setPosition(25,455);
                texte.setColor(sf::Color::White);
                texte.setCharacterSize(20);
                break; 
                
                
                
                
                
                
        case 50 :
                texture.loadFromFile("res/Textures/case-grise.png");
                sprite.setTexture(texture);
                sprite.setPosition(0,480);
                sprite.setScale(1.2,1.2);
                break;
        case 51 :
                texture.loadFromFile("res/Textures/chevalier-attaque2.png");
                sprite.setTexture(texture);
                sprite.setPosition(0,510);
                sprite.setScale(0.7,0.7);
                
                aTexte = true;
                texte.setFont(font);
                texte.setString("Chevalier (28pts)");
                texte.setPosition(5,480);
                texte.setColor(sf::Color::White);
                texte.setCharacterSize(15);
                
                break;            
        case 52 :
                texture.loadFromFile("res/Textures/plus.png");
                sprite.setTexture(texture);
                sprite.setPosition(80,505);
                sprite.setScale(1.5,1.5);
                break;            
        case 53 :
                texture.loadFromFile("res/Textures/moins.png");
                sprite.setTexture(texture);
                sprite.setPosition(80,545);
                sprite.setScale(1.5,1.5);
                break;
        case 54 :
                aTexte = true;
                texte.setFont(font);
                texte.setString("A / B");
                texte.setPosition(25,575);
                texte.setColor(sf::Color::White);
                texte.setCharacterSize(20);
                break;         
                
                
                
        case 60 :
                texture.loadFromFile("res/Textures/case-grise.png");
                sprite.setTexture(texture);
                sprite.setPosition(0,600);
                sprite.setScale(1.2,1.2);
                break;
        case 61 :
                texture.loadFromFile("res/Textures/Roi-attaque.png");
                sprite.setTexture(texture);
                sprite.setPosition(0,630);
                sprite.setScale(0.7,0.7);
                
                aTexte = true;
                texte.setFont(font);
                texte.setString("Roi (40pts)");
                texte.setPosition(5,600);
                texte.setColor(sf::Color::White);
                texte.setCharacterSize(19);
                
                break;            
        case 62 :
                texture.loadFromFile("res/Textures/plus.png");
                sprite.setTexture(texture);
                sprite.setPosition(80,625);
                sprite.setScale(1.5,1.5);
                break;            
        case 63 :
                texture.loadFromFile("res/Textures/moins.png");
                sprite.setTexture(texture);
                sprite.setPosition(80,665);
                sprite.setScale(1.5,1.5);
                break;
        case 64 :
                aTexte = true;
                texte.setFont(font);
                texte.setString("1 / 1");
                texte.setPosition(25,695);
                texte.setColor(sf::Color::White);
                texte.setCharacterSize(20);
                break;     
                
        case 70 :
                texture.loadFromFile("res/Textures/Bouton-On.png");
                sprite.setTexture(texture);
                sprite.setPosition(largeur - 250,15);
                sprite.setScale(2,2);
            
                aTexte = true;
                texte.setFont(font);
                texte.setString("C'est parti !");
                texte.setPosition(largeur-210, 30);
                texte.setColor(sf::Color::White);
                texte.setCharacterSize(20);
                break;            
                
        case 00 :
                texture.loadFromFile("res/Textures/Barre-menu.png");
                sprite.setTexture(texture);
                sprite.setPosition(120,0);
                sprite.setScale(2,2);
                break;
        case 01 :
                aTexte = true;
                texte.setFont(font);
                texte.setString("RESTANTS / TOTAL");
                texte.setPosition(215,20);
                texte.setColor(sf::Color::White);
                texte.setCharacterSize(20);
                break;            
        case 02 :
                aTexte = true;
                texte.setFont(font);
                texte.setString("X / 100");
                texte.setPosition(270,50);
                texte.setColor(sf::Color::White);
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