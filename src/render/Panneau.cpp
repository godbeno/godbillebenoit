#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <iostream>

#include "Panneau.h"
#include "state/Personnage.h"
#include "state/Etat.h"
#include "state/TypePersonnage.h"
#include <string>

using namespace render;

Panneau::Panneau()
{
    
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
    estSelect = false;
}