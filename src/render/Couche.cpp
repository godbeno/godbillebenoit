#include "Couche.h"
#include "TuileStatique.h"
#include "TuileAnimee.h"
#include <iostream>

using namespace render;

Couche::Couche(sf::RenderWindow* window)
{
    tuiles.clear();
    this->window = window;
    select = 0;
    font.loadFromFile("res/Fonts/arial.ttf");
    estDegat = false;
    
}
Couche::~Couche()
{
    for (unsigned int i = 0; i < tuiles.size(); i++)
        delete tuiles[i];
}
Tuile* Couche::getTuile (float i, float j, float incr)
{
    for (unsigned int k = 0; k < tuiles.size(); k++)
    {
        if ((int)tuiles[k]->getX() == (int)i && (int)tuiles[k]->getY() == (int)j)
            return tuiles[k];
    }
    return nullptr;
}
void Couche::setTuile (int i, int j, Tuile* tuile)
{
    for (unsigned int k = 0; k < tuiles.size(); k++)
        if ((int)tuiles[k]->getX() == (int)i && (int)tuiles[k]->getY() == (int)j)
        {
            delete tuiles[k];
            tuiles.erase(tuiles.begin()+k);
        }
    if (tuile)
        tuiles.push_back(tuile);
    
}
void Couche::addTuile(Tuile* tuile)
{
    tuiles.push_back(tuile);
}
void Couche::changementEtat(state::EvenementEtat& e)
{
    if (e.getTypeEvenement() == state::NouveauPersonnage)
    {
        std::cout << "Couche: Nouveau personnage" << std::endl;
    }
}
void Couche::afficher()
{
    //std::cout << "TUILES SIZE : " << tuiles.size() << std::endl;
    //TuileStatique tuile(50,50,0);
    clock_t t;
    for (unsigned int i = 0; i < tuiles.size(); i++)
    {
        if (tuiles[i]->estAnime())
        {
            t = clock();
            static_cast<TuileAnimee*>(tuiles[i])->update(t);
        }
        window->draw(tuiles[i]->getSprite());
        //window->draw((new TuileStatique(100,100,73,200))->getSprite());
    }
    for (unsigned int i = 0; i < brillance.size(); i++)
        window->draw(brillance[i]);
    for (unsigned int i = 0; i < rouge.size(); i++)
        window->draw(rouge[i]);
    if (select)
        window->draw(*select);
    if (estDegat)
        window->draw(degat);
}
void Couche::setSurbrillance(int x, int y, float tx)
{
    sf::RectangleShape rect(sf::Vector2f(tx,tx));
    rect.setFillColor(sf::Color(0,0,255,128));
    rect.setPosition(x,y);
    brillance.push_back(rect);
    
}
void Couche::deplacerCamera(float x, float y)
{
    for (unsigned int i = 0; i < tuiles.size(); i++)
    {
        tuiles[i]->setX(tuiles[i]->getX()+x);
        tuiles[i]->setY(tuiles[i]->getY()+y);
        static_cast<TuileStatique*>(tuiles[i])->updateSpritePosition(x, y);
    }
    if (select)
    {
        int ancienSelx = select->getPosition().x;
        int ancienSely = select->getPosition().y;
        select->setPosition(ancienSelx+x, ancienSely+y);
    }
        
    for (unsigned int i = 0; i < brillance.size(); i++)
    {
        int ancienBrix = brillance[i].getPosition().x;
        int ancienBriy = brillance[i].getPosition().y;
        brillance[i].setPosition(ancienBrix+x, ancienBriy+y);

    }
    for (unsigned int i = 0; i < rouge.size(); i++)
    {
        int ancienBrix = rouge[i].getPosition().x;
        int ancienBriy = rouge[i].getPosition().y;
        rouge[i].setPosition(ancienBrix+x, ancienBriy+y);
    }
}
void Couche::zoomCamera(float s)
{
    for (unsigned int i = 0; i < tuiles.size(); i++)
    {
        int anciennePosx = tuiles[i]->getX();
        int anciennePosy = tuiles[i]->getY();
        tuiles[i]->setX((int)((float)(anciennePosx)*s));
        tuiles[i]->setY((int)((float)(anciennePosy)*s));
        static_cast<TuileStatique*>(tuiles[i])->updateSpritePosition(+tuiles[i]->getX()-anciennePosx, tuiles[i]->getY()-anciennePosy);        
        static_cast<TuileStatique*>(tuiles[i])->updateSpriteScale(s);
    }
    if (select)
    {
        int ancienSelx = select->getPosition().x;
        int ancienSely = select->getPosition().y;
        select->setPosition(ancienSelx*s, ancienSely*s);
        select->setScale(select->getScale().x*s,select->getScale().y*s);
    }
    for (unsigned int i = 0; i < brillance.size(); i++)
    {
        int ancienBrix = brillance[i].getPosition().x;
        int ancienBriy = brillance[i].getPosition().y;
        brillance[i].setPosition(ancienBrix*s, ancienBriy*s);
        brillance[i].setScale(brillance[i].getScale().x*s,brillance[i].getScale().y*s);
    }
    for (unsigned int i = 0; i < rouge.size(); i++)
    {
        int ancienBrix = rouge[i].getPosition().x;
        int ancienBriy = rouge[i].getPosition().y;
        rouge[i].setPosition(ancienBrix*s, ancienBriy*s);
        rouge[i].setScale(rouge[i].getScale().x*s,rouge[i].getScale().y*s);
    }
}
void Couche::unsetSurbrillance()
{
    brillance.clear();
}
void Couche::setSelectionne(int x, int y, float tx)
{
    if (select)
    {
        delete select;
        std::cout << "Destruction de select" << std::endl;
    }
    select = new sf::RectangleShape(sf::Vector2f(tx, tx));
    //select->setPosition(x+(tx/4), y+(tx/4));
    select->setPosition(x, y);
    select->setOutlineColor(sf::Color(255,255,0));
    select->setOutlineThickness(1.5);
    select->setFillColor(sf::Color(0,0,0,0));
}
void Couche::unsetSelectionne()
{
    delete select;
    select = nullptr;
}
void Couche::setRouge(int x, int y, float tx)
{
    sf::RectangleShape rect(sf::Vector2f(tx,tx));
    rect.setFillColor(sf::Color(255,0,0,128));
    rect.setPosition(x,y);
    rouge.push_back(rect);
}
void Couche::unsetRouge()
{
    rouge.clear();
}
void Couche::setDegat(float x, float y, int nbDegat)
{
    degat.setFont(font);
    degat.setString("-" + std::to_string(nbDegat));
    degat.setPosition(x+20, y-20);
    degat.setColor(sf::Color::Red);
    degat.setCharacterSize(20);
    estDegat = true;
}
void Couche::stopDegat()
{
    estDegat = false;
}
void Couche::monterDegat()
{
    degat.setPosition(degat.getPosition().x, degat.getPosition().y-0.5);
}