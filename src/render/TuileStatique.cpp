#include <SFML/Graphics/Sprite.hpp>
#include <iostream>

#include "TuileStatique.h"

using namespace render;
using namespace sf;


TuileStatique::TuileStatique(float x, float y, int id, float w) : Tuile(x,y,id)
{
    hauteur = x;
    largeur = y;
    this->id = id;
    this->w = w;
    switch(id)
    {
        case 0: //Herbe
            texture.loadFromFile("res/Textures/herbe.png");
            break;
        case 1: //RiviereEO
            texture.loadFromFile("res/Textures/riviere-EO.png");
            break;
        case 2: //RiviereNS
            texture.loadFromFile("res/Textures/riviere-NS.png");
            break;           
        case 3: //RiviereNE
            texture.loadFromFile("res/Textures/riviere-NE.png");
            break;
        case 4: //RiviereNO
            texture.loadFromFile("res/Textures/riviere-NO.png");
            break;
        case 5: //RiviereSE
            texture.loadFromFile("res/Textures/riviere-SE.png");
            break;
        case 6: //RiviereSO
            texture.loadFromFile("res/Textures/riviere-SO.png");
            break;                      
        case 7: //Pierres-chateau
            texture.loadFromFile("res/Textures/Pierres-chateau.png");
            break;                      
        case 8: //PontEO
            texture.loadFromFile("res/Textures/riviere-pont-EO.png");
            break;
        case 9: //PontNS
            texture.loadFromFile("res/Textures/riviere-pont-NS.png");
            break;
        case 10: //herbe+buisson
            texture.loadFromFile("res/Textures/herbe+buisson.png");
            break;            
        case 11: //Montagne
            texture.loadFromFile("res/Textures/montagne.png");
            break;           
        case 12: //Montagne
            texture.loadFromFile("res/Textures/montagne-N.png");
            break;
        case 13: //Montagne
            texture.loadFromFile("res/Textures/montagne-E.png");
            break;
        case 14: //Montagne
            texture.loadFromFile("res/Textures/montagne-S.png");
            break;
        case 15: //Montagne
            texture.loadFromFile("res/Textures/montagne-O.png");
            break;
        case 16: //Montagne
            texture.loadFromFile("res/Textures/montagne-NE.png");
            break;
        case 17: //Montagne
            texture.loadFromFile("res/Textures/montagne-NO.png");
            break;
        case 18: //Montagne
            texture.loadFromFile("res/Textures/montagne-SE.png");
            break;
        case 19: //Montagne
            texture.loadFromFile("res/Textures/montagne-SO.png");
            break;
        case 20: //Porte
            texture.loadFromFile("res/Textures/porte-h.png");
            break;
        case 21: //Porte
            texture.loadFromFile("res/Textures/porte-v.png");
            break;
        case 22: //Porte
            texture.loadFromFile("res/Textures/porte-h-c.png");
            break;
        case 23: //Porte
            texture.loadFromFile("res/Textures/porte-v-c.png");
            break;
        case 24: //Porte
            texture.loadFromFile("res/Textures/porte-h-t.png");
            break;
        case 25: //Porte
            texture.loadFromFile("res/Textures/porte-v-t.png");
            break;            
        case 26: //Rempart
            texture.loadFromFile("res/Textures/rempart-NO.png");
            break;            
        case 27: //Rempart
            texture.loadFromFile("res/Textures/rempart-NS.png");
            break;
        case 28: //Rempart
            texture.loadFromFile("res/Textures/rempart-NE.png");
            break;             
        case 29: //Rempart
            texture.loadFromFile("res/Textures/rempart-EO.png");
            break;            
        case 30: //Rempart
            texture.loadFromFile("res/Textures/rempart-SE.png");
            break;            
        case 31: //Rempart
            texture.loadFromFile("res/Textures/rempart-SO.png");
            break;            
        case 32: //Rempart
            texture.loadFromFile("res/Textures/rempart-T-EOS.png");
            break;            
        case 33: //Rempart
            texture.loadFromFile("res/Textures/rempart-T-NES.png");
            break;            
        case 34: //Rempart
            texture.loadFromFile("res/Textures/rempart-T-NOE.png");
            break;            
        case 35: //Rempart
            texture.loadFromFile("res/Textures/rempart-T-NOS.png");
            break;            
        case 36: //Escalier
            texture.loadFromFile("res/Textures/Escalier-N.png");
            break;
        case 37: //Escalier
            texture.loadFromFile("res/Textures/Escalier-S.png");
            break;
        case 38: //Escalier
            texture.loadFromFile("res/Textures/Escalier-E.png");
            break;            
        case 39: //Escalier
            texture.loadFromFile("res/Textures/Escalier-O.png");
            break;            
        case 40: //Acces montagne
            texture.loadFromFile("res/Textures/montagne-passage-N.png");
            break;            
        case 41: //Acces montagne
            texture.loadFromFile("res/Textures/montagne-passage-S.png");
            break;            
        case 42: //Acces montagne
            texture.loadFromFile("res/Textures/montagne-passage-E.png");
            break;            
        case 43: //Acces montagne
            texture.loadFromFile("res/Textures/montagne-passage-O.png");
            break; 
            
       /* -----------------------PERSONNAGES-------------------------- */
            
        case 44: //Lancier bleu
            texture.loadFromFile("res/Textures/Lancier-repos-bleu.png");
            break;             
        case 45: //Lancier rouge
            texture.loadFromFile("res/Textures/Lancier-repos.png");
            break;             
        case 46: //Archer bleu
            texture.loadFromFile("res/Textures/Archer-repos-bleu.png");
            break;             
        case 47: //Archer rouge
            texture.loadFromFile("res/Textures/Archer-repos.png");
            break;             
        case 48: //Spadassin bleu
            texture.loadFromFile("res/Textures/Capitaine-repos-bleu.png");
            break;             
        case 49: //Spadassin rouge
            texture.loadFromFile("res/Textures/Capitaine-repos.png");
            break;             
        case 50: //Chevalier bleu 
            texture.loadFromFile("res/Textures/chevalier-repos-bleu.png");
            break;             
        case 51: //Chevalier rouge
            texture.loadFromFile("res/Textures/chevalier-repos.png");
            break;             
        case 52: //Roi bleu
            texture.loadFromFile("res/Textures/Roi-repos-bleu.png");
            break;             
        case 53: //Roi rouge
            texture.loadFromFile("res/Textures/Roi-repos.png");
            break;             
        case 54: //Canon bleu
            texture.loadFromFile("res/Textures/canon-repos-bleu.png");
            break;             
        case 55: //Canon rouge
            texture.loadFromFile("res/Textures/canon-repos.png");
            break;             
        //case 56: //Cadavre fantassin
           // texture.loadFromFile("res/Textures/Cadavre-infanterie.png");
          //  break;             
        //case 57: //Cadavre cavalier
          //  texture.loadFromFile("res/Textures/Cadavre-cavalier.png");
          //  break;             
        //case 58: // Cadavre canon
         //   texture.loadFromFile("res/Textures/Cadavre-canon.png");
         //   break;
        case 59: //Lancier bleu attaque
            texture.loadFromFile("res/Textures/Lancier-attaque-bleu.png");
            break;
        case 60: //Lancier rouge attaque
            texture.loadFromFile("res/Textures/Lancier-attaque.png");
            break;
        case 61: //Archer attaque bleu 1
            texture.loadFromFile("res/Textures/Archer-attaque-bleu.png");
            break;
        case 62: //Archer attaque bleu 2
            texture.loadFromFile("res/Textures/Archer-post-attaque-bleu.png");
            break;
        case 63: //Archer attaque rouge 1
            texture.loadFromFile("res/Textures/Archer-attaque.png");
            break;
        case 64: //Archer attaque rouge 2
            texture.loadFromFile("res/Textures/Archer-post-attaque.png");
            break;
        case 65: //Attaque spadassin bleu
            texture.loadFromFile("res/Textures/Capitaine-attaque-bleu.png");
            break;
        case 66: //Attaque spadassin rouge
            texture.loadFromFile("res/Textures/Capitaine-attaque.png");
            break;
        case 67: // Attaque Chevalier bleu
            texture.loadFromFile("res/Textures/chevalier-attaque2-bleu.png");
            break;
        case 68: // Attaque Chevalier rouge
            texture.loadFromFile("res/Textures/chevalier-attaque2.png");
            break;
        case 69: // Attaque roi bleu
            texture.loadFromFile("res/Textures/Roi-attaque-bleu.png");
            break;
        case 70: // Attaque roi rouge
            texture.loadFromFile("res/Textures/Roi-attaque.png");
            break;
        case 71: // Attaque Canon bleu
            texture.loadFromFile("res/Textures/canon-tir-bleu.png");
            break;
        case 72: // Attaque Canon rouge
            texture.loadFromFile("res/Textures/canon-tir.png");
            break;
        case 73: // Barre des tâches
            texture.loadFromFile("res/Textures/Barre-menu.png");
            break;
    }
            
            
    
    sprite.setTexture(texture);
    sprite.setPosition(x,y);
    if (id > 43)
        sprite.setScale(w/100, w/100);
    else if(id > 73)
        sprite.setScale(w/100,w/100);
    else
        sprite.setScale(w/100,w/100);
    //std::cout << "Sprite position : (" << sprite.getPosition().x << ", " << sprite.getPosition().y << ") " << std::endl;
}
TuileStatique::~TuileStatique()
{
    
}
int const TuileStatique::getHauteur()
{
    return hauteur;
}
int const TuileStatique::getLargeur()
{
    return largeur;
}
void TuileStatique::setHauteur(int hauteur)
{
    this->hauteur = hauteur;
}
void TuileStatique::setLargeur(int largeur)
{
    this->largeur = largeur;
}
const sf::Sprite& TuileStatique::getSprite ()
{
    return sprite;
}
bool TuileStatique::estAnime ()
{
    return false;
}
TuileStatique* TuileStatique::copy()
{
    TuileStatique* t = new TuileStatique(x, y, id, w);
    t->hauteur = hauteur;
    t->largeur = largeur;
    return t;
    
}
void TuileStatique::setEstAffiche(bool b)
{
    this->estAffiche = b;
}
bool TuileStatique::getEstAffiche()
{
    return this->estAffiche;
}
void TuileStatique::updateSpritePosition(float x, float y)
{
    sprite.setPosition(sprite.getPosition().x+x, sprite.getPosition().y+y);
}
void TuileStatique::updateSpriteScale(float s)
{
    sprite.setScale(sprite.getScale().x*s,sprite.getScale().y*s);
}