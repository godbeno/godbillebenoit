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
}
void Message::dessiner(sf::RenderWindow* window)
{
    if (active)
        window->draw(texte);
    if (double(clock()-temps)/CLOCKS_PER_SEC > 1 && !fin)
        finAffichage();
}
void Message::changerTour()
{
    tour = !tour;
    if (tour)
    {
        texte.setString("Tour de l'équipe bleue ! ");
        texte.setColor(sf::Color::Blue);
    }
    else
    {
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