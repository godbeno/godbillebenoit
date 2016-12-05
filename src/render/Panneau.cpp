#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <iostream>

#include "Panneau.h"
#include "state/Personnage.h"
#include "state/Etat.h"
#include "Bouton.h"
#include "state/TypePersonnage.h"
#include <string>

using namespace render;

Panneau::Panneau()
{
    listeBoutons.clear();
    listeBoutons.push_back(new Bouton(100));
    listeBoutons.push_back(new Bouton(102));    
    listeBoutons.push_back(new Bouton(104));
    
    listeBoutons.push_back(new Bouton(00));
    listeBoutons.push_back(new Bouton(01)); 
    listeBoutons.push_back(new Bouton(02));  
    
    listeBoutons.push_back(new Bouton(10));
    listeBoutons.push_back(new Bouton(11));  
    listeBoutons.push_back(new Bouton(12));
    listeBoutons.push_back(new Bouton(13));  
    listeBoutons.push_back(new Bouton(14));
    
    listeBoutons.push_back(new Bouton(20));
    listeBoutons.push_back(new Bouton(21));  
    listeBoutons.push_back(new Bouton(22));
    listeBoutons.push_back(new Bouton(23));  
    listeBoutons.push_back(new Bouton(24));
    
    listeBoutons.push_back(new Bouton(30));
    listeBoutons.push_back(new Bouton(31));  
    listeBoutons.push_back(new Bouton(32));
    listeBoutons.push_back(new Bouton(33));  
    listeBoutons.push_back(new Bouton(34));
    
    listeBoutons.push_back(new Bouton(40));
    listeBoutons.push_back(new Bouton(41));  
    listeBoutons.push_back(new Bouton(42));
    listeBoutons.push_back(new Bouton(43));  
    listeBoutons.push_back(new Bouton(44));
    
    listeBoutons.push_back(new Bouton(50));
    listeBoutons.push_back(new Bouton(51));  
    listeBoutons.push_back(new Bouton(52));
    listeBoutons.push_back(new Bouton(53));  
    listeBoutons.push_back(new Bouton(54));
    
    
    listeBoutons.push_back(new Bouton(60));
    listeBoutons.push_back(new Bouton(61));  
    listeBoutons.push_back(new Bouton(62));
    listeBoutons.push_back(new Bouton(63));  
    listeBoutons.push_back(new Bouton(64));
    
    listeBoutons.push_back(new Bouton(70));
    
    
    int largeur = sf::VideoMode::getDesktopMode().width;
    int hauteur = sf::VideoMode::getDesktopMode().height;
    
    textFond.loadFromFile("res/Textures/Barre-menu.png");
    
    fond.setTexture(textFond);
    fond.setPosition(largeur/2 - 195, hauteur-120);
    fond.setScale(2,2);
    font.loadFromFile("res/Fonts/arial.ttf");
    
    nom.setFont(font);
    nom.setString("Archer");
    nom.setPosition(largeur/2, hauteur-100);
    nom.setColor(sf::Color::White);
    nom.setCharacterSize(30);
    
    
    estSelect = false;
    

    
    //rajouter PA et PV etc 
    
}
void Panneau::draw(sf::RenderWindow* window)
{   
    window->draw(fond);
    for(unsigned int i=0;i<listeBoutons.size();i++)
    {
        window->draw(listeBoutons[i]->getSprite());
        if(listeBoutons[i]->getATexte())
            window->draw(listeBoutons[i]->getTexte());
    }
    
    if (estSelect)
    {
        window->draw(nom);
        window->draw(paTot);
        window->draw(paRest);
        window->draw(txtPa);
        window->draw(pvTot);
        window->draw(pvRest);
        window->draw(txtPv);
    }
}
void Panneau::setSelectionne(state::Etat* etat, state::Personnage* p)
{
    int largeur = sf::VideoMode::getDesktopMode().width;
    int hauteur = sf::VideoMode::getDesktopMode().height;
    
    estSelect = true;
    float paRestant, unitePa, pvRestant, unitePv;
    unitePa = 100/p->getPAMax();
    paRestant = p->getPA()*unitePa;
    unitePv = 100./p->getPVMax();
    pvRestant = p->getPV()*unitePv;
    
        for(unsigned int i=0;i<listeBoutons.size();i++)
    {
        if(listeBoutons[i]->getID()==101) listeBoutons[i]->setID(100);
        else if(listeBoutons[i]->getID()==103) listeBoutons[i]->setID(102);
    }
    
    switch(p->getType())
    {
        case state::Spadassin:
            nom.setString("Spadassin");
            break;
        case state::Lancier:
            nom.setString("Lancier");
            break;
        case state::Archer:
            nom.setString("Archer");
            break;
        case state::Canon:
            nom.setString("Canon");
            break;
        case state::Cavalier:
            nom.setString("Cavalier");
            break;
        case state::Roi:
            nom.setString("Roi");
            break;
    }
    nom.setPosition(largeur/2, hauteur-110);
    nom.setColor(sf::Color::White);
    nom.setCharacterSize(18);
    
    
    paTot.setPosition(sf::Vector2f(largeur/2, hauteur - 80));
    paTot.setFillColor(sf::Color(22,12,158));
    paTot.setSize(sf::Vector2f(100, 10));
    
    paRest.setSize(sf::Vector2f(paRestant, 10));
    paRest.setPosition(largeur/2, hauteur - 80);
    paRest.setFillColor(sf::Color(93,104,236));
    
    txtPa.setFont(font);
    txtPa.setString("PA : " + std::to_string(p->getPA()) + " / " + std::to_string(p->getPAMax()));
    txtPa.setCharacterSize(10);
    txtPa.setColor(sf::Color(22,12,158));
    txtPa.setPosition(sf::Vector2f(largeur/2 +110, hauteur - 80));
    
    pvTot.setPosition(sf::Vector2f(largeur/2, hauteur - 50));
    pvTot.setFillColor(sf::Color(139,0,0));
    pvTot.setSize(sf::Vector2f(100, 10));
    
    pvRest.setSize(sf::Vector2f(pvRestant, 10));
    pvRest.setPosition(largeur/2, hauteur - 50);
    pvRest.setFillColor(sf::Color(255,0,0));
    
    txtPv.setFont(font);
    txtPv.setString("PV : " + std::to_string(p->getPV()) + " / " + std::to_string(p->getPVMax()));
    txtPv.setCharacterSize(10);
    txtPv.setColor(sf::Color(255,0,0));
    txtPv.setPosition(sf::Vector2f(largeur/2 +110, hauteur - 50));
    
    
}
void Panneau::unsetSelectionne()
{
    for(unsigned int i=0;i<listeBoutons.size();i++)
    {
        if(listeBoutons[i]->getID()==100) listeBoutons[i]->setID(101);
        else if(listeBoutons[i]->getID()==102) listeBoutons[i]->setID(103);
    }
    estSelect = false;
}