#include <SFML/Graphics/Text.hpp>
#include <iostream>

#include "Message.h"

using namespace render;

Message::Message()
{
    int largeur = sf::VideoMode::getDesktopMode().width;
    int hauteur = sf::VideoMode::getDesktopMode().height;
    font.loadFromFile("res/Fonts/arial.ttf");
    texte.setFont(font);
    texte.setPosition(largeur/2 - 200, hauteur/2);
    texte.setColor(sf::Color::Red);
    texte.setCharacterSize(30);
    temps = clock();
    
    active = false;
    tour = true;
    fin = false;
    
    Rectangle = new sf::RectangleShape(sf::Vector2f(largeur-4, hauteur-4));
    //select->setPosition(x+(tx/4), y+(tx/4));
    Rectangle->setPosition(2,2);
    
    Rectangle->setOutlineColor(sf::Color(255,255,0));
    Rectangle->setOutlineThickness(2);
    Rectangle->setFillColor(sf::Color(0,0,0,0));
}
void Message::dessiner(sf::RenderWindow* window)
{   
    window->draw(*Rectangle);
    if (active)
        window->draw(texte);
    if (double(clock()-temps)/CLOCKS_PER_SEC > .5 && !fin)
        finAffichage();
}
void Message::changerTour()
{
    tour = !tour;

    if (tour)
    {   Rectangle->setOutlineColor(sf::Color::Blue);
        texte.setString("Tour de l'equipe bleue ! ");
        texte.setColor(sf::Color::Blue);
    }
    else
    {   Rectangle->setOutlineColor(sf::Color::Red);
        texte.setString("Tour de l'equipe rouge ! ");
        texte.setColor(sf::Color::Red);
    }
    active = true;
    temps = clock();
}
void Message::finDePartie(bool b)
{
    if (b)
    {
        texte.setString("Victoire de l'equipe bleue ! ");
        texte.setColor(sf::Color::Blue);
    }
    else
    {
        texte.setString("Victoire de l'equipe rouge ! ");
        texte.setColor(sf::Color::Red);
    }
    active = true;
    fin = true;
}
void Message::finAffichage()
{
    active = false;
}