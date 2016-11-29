#include "TuileAnimee.h"
#include "TuileStatique.h"
#include <iostream>
#include <ctime>

using namespace render;

TuileAnimee::TuileAnimee(float x, float y, int id, float vitesse, Couche* couche,int TrueX,int TrueY, Scene* scene) : Tuile(x,y,id,TrueX,TrueY)
{
    nbr = 0;
    this->vitesse = vitesse;
    float tx = vitesse;
    debut = clock();
    parent = couche;
    switch(id)
    {
        /* Ordre:
         *  - Lancier
         *  - Archer
         *  - Spadassin
         *  - Cavalier
         *  - Roi
         *  - Canon
         *
         * 0-5 : Attaque Personnage rouge
         * 6-11 : Attaque personnage bleu
         * 12-17 : Personnage rouge touché
         * 18-24 : Personnage bleu touché
         * 24-26 : Personnage rouge mort
         * 27-29 : personnage bleu mort
         *
         */
        case 0: 
            tuiles.push_back(new TuileStatique(x, y, 60, tx,TrueX,TrueY, scene));
            tuiles.push_back(new TuileStatique(x, y, 45, tx,TrueX,TrueY, scene));
            tuiles.push_back(new TuileStatique(x, y, 60, tx,TrueX,TrueY, scene));
            tuiles.push_back(new TuileStatique(x, y, 45, tx,TrueX,TrueY, scene));
            break;
        case 1: 
            tuiles.push_back(new TuileStatique(x, y, 63, tx,TrueX,TrueY, scene));
            tuiles.push_back(new TuileStatique(x, y, 64, tx,TrueX,TrueY, scene));
            tuiles.push_back(new TuileStatique(x, y, 63, tx,TrueX,TrueY, scene));
            tuiles.push_back(new TuileStatique(x, y, 64, tx,TrueX,TrueY, scene));
            tuiles.push_back(new TuileStatique(x, y, 47, tx,TrueX,TrueY, scene));
            break;
        case 2:
            tuiles.push_back(new TuileStatique(x, y, 66, tx,TrueX,TrueY, scene));
            tuiles.push_back(new TuileStatique(x, y, 49, tx,TrueX,TrueY, scene));
            tuiles.push_back(new TuileStatique(x, y, 66, tx,TrueX,TrueY, scene));
            tuiles.push_back(new TuileStatique(x, y, 49, tx,TrueX,TrueY, scene));
            break;
        case 3:
            tuiles.push_back(new TuileStatique(x, y, 68, tx,TrueX,TrueY, scene));
            tuiles.push_back(new TuileStatique(x, y, 51, tx,TrueX,TrueY, scene));
            tuiles.push_back(new TuileStatique(x, y, 68, tx,TrueX,TrueY, scene));
            tuiles.push_back(new TuileStatique(x, y, 51, tx,TrueX,TrueY, scene));
            break;
        case 4:
            tuiles.push_back(new TuileStatique(x, y, 70, tx,TrueX,TrueY, scene));
            tuiles.push_back(new TuileStatique(x, y, 53, tx,TrueX,TrueY, scene));
            tuiles.push_back(new TuileStatique(x, y, 70, tx,TrueX,TrueY, scene));
            tuiles.push_back(new TuileStatique(x, y, 53, tx,TrueX,TrueY, scene));
            break;
        case 5:
            tuiles.push_back(new TuileStatique(x, y, 72, tx,TrueX,TrueY, scene));
            tuiles.push_back(new TuileStatique(x, y, 55, tx,TrueX,TrueY, scene));
            tuiles.push_back(new TuileStatique(x, y, 72, tx,TrueX,TrueY, scene));
            tuiles.push_back(new TuileStatique(x, y, 55, tx,TrueX,TrueY, scene));
            break;
        case 6: 
            tuiles.push_back(new TuileStatique(x, y, 59, tx,TrueX,TrueY));
            tuiles.push_back(new TuileStatique(x, y, 44, tx,TrueX,TrueY));
            tuiles.push_back(new TuileStatique(x, y, 59, tx,TrueX,TrueY));
            tuiles.push_back(new TuileStatique(x, y, 44, tx,TrueX,TrueY));
            break;
        case 7: 
            tuiles.push_back(new TuileStatique(x, y, 61, tx,TrueX,TrueY));
            tuiles.push_back(new TuileStatique(x, y, 62, tx,TrueX,TrueY));
            tuiles.push_back(new TuileStatique(x, y, 61, tx,TrueX,TrueY));
            tuiles.push_back(new TuileStatique(x, y, 62, tx,TrueX,TrueY));
            tuiles.push_back(new TuileStatique(x, y, 46, tx,TrueX,TrueY));
            break;
        case 8:
            tuiles.push_back(new TuileStatique(x, y, 65, tx,TrueX,TrueY));
            tuiles.push_back(new TuileStatique(x, y, 48, tx,TrueX,TrueY));
            tuiles.push_back(new TuileStatique(x, y, 65, tx,TrueX,TrueY));
            tuiles.push_back(new TuileStatique(x, y, 48, tx,TrueX,TrueY));
            break;
        case 9:
            tuiles.push_back(new TuileStatique(x, y, 67, tx,TrueX,TrueY));
            tuiles.push_back(new TuileStatique(x, y, 50, tx,TrueX,TrueY));
            tuiles.push_back(new TuileStatique(x, y, 67, tx,TrueX,TrueY));
            tuiles.push_back(new TuileStatique(x, y, 50, tx,TrueX,TrueY));
            break;
        case 10:
            tuiles.push_back(new TuileStatique(x, y, 69, tx,TrueX,TrueY));
            tuiles.push_back(new TuileStatique(x, y, 52, tx,TrueX,TrueY));
            tuiles.push_back(new TuileStatique(x, y, 69, tx,TrueX,TrueY));
            tuiles.push_back(new TuileStatique(x, y, 52, tx,TrueX,TrueY));
            break;
        case 11:
            tuiles.push_back(new TuileStatique(x, y, 71, tx,TrueX,TrueY));
            tuiles.push_back(new TuileStatique(x, y, 54, tx,TrueX,TrueY));
            tuiles.push_back(new TuileStatique(x, y, 71, tx,TrueX,TrueY));
            tuiles.push_back(new TuileStatique(x, y, 54, tx,TrueX,TrueY));
            break;
        case 12:
            tuiles.push_back(new TuileStatique(x, y, -1, tx,TrueX,TrueY));
            tuiles.push_back(new TuileStatique(x, y, 45, tx,TrueX,TrueY));
            tuiles.push_back(new TuileStatique(x, y, -1, tx,TrueX,TrueY));
            tuiles.push_back(new TuileStatique(x, y, 45, tx,TrueX,TrueY));
            break;
        case 13:
            tuiles.push_back(new TuileStatique(x, y, -1, tx,TrueX,TrueY));
            tuiles.push_back(new TuileStatique(x, y, 47, tx,TrueX,TrueY));
            tuiles.push_back(new TuileStatique(x, y, -1, tx,TrueX,TrueY));
            tuiles.push_back(new TuileStatique(x, y, 47, tx,TrueX,TrueY));
            break;
        case 14:
            tuiles.push_back(new TuileStatique(x, y, -1, tx,TrueX,TrueY));
            tuiles.push_back(new TuileStatique(x, y, 49, tx,TrueX,TrueY));
            tuiles.push_back(new TuileStatique(x, y, -1, tx,TrueX,TrueY));
            tuiles.push_back(new TuileStatique(x, y, 49, tx,TrueX,TrueY));
            break;
        case 15: 
            tuiles.push_back(new TuileStatique(x, y, -1, tx,TrueX,TrueY));
            tuiles.push_back(new TuileStatique(x, y, 51, tx,TrueX,TrueY));
            tuiles.push_back(new TuileStatique(x, y, -1, tx,TrueX,TrueY));
            tuiles.push_back(new TuileStatique(x, y, 51, tx,TrueX,TrueY));
            break;
        case 16:
            tuiles.push_back(new TuileStatique(x, y, -1, tx,TrueX,TrueY));
            tuiles.push_back(new TuileStatique(x, y, 53, tx,TrueX,TrueY));
            tuiles.push_back(new TuileStatique(x, y, -1, tx,TrueX,TrueY));
            tuiles.push_back(new TuileStatique(x, y, 53, tx,TrueX,TrueY));
            break;
        case 17:
            tuiles.push_back(new TuileStatique(x, y, -1, tx,TrueX,TrueY));
            tuiles.push_back(new TuileStatique(x, y, 55, tx,TrueX,TrueY));
            tuiles.push_back(new TuileStatique(x, y, -1, tx,TrueX,TrueY));
            tuiles.push_back(new TuileStatique(x, y, 55, tx,TrueX,TrueY));
            break;
        case 18:
            tuiles.push_back(new TuileStatique(x, y, -1, tx,TrueX,TrueY));
            tuiles.push_back(new TuileStatique(x, y, 44, tx,TrueX,TrueY));
            tuiles.push_back(new TuileStatique(x, y, -1, tx,TrueX,TrueY));
            tuiles.push_back(new TuileStatique(x, y, 44, tx,TrueX,TrueY));
            break;
        case 19:
            tuiles.push_back(new TuileStatique(x, y, -1, tx,TrueX,TrueY));
            tuiles.push_back(new TuileStatique(x, y, 46, tx,TrueX,TrueY));
            tuiles.push_back(new TuileStatique(x, y, -1, tx,TrueX,TrueY));
            tuiles.push_back(new TuileStatique(x, y, 46, tx,TrueX,TrueY));
            break;
        case 20:
            tuiles.push_back(new TuileStatique(x, y, -1, tx,TrueX,TrueY));
            tuiles.push_back(new TuileStatique(x, y, 48, tx,TrueX,TrueY));
            tuiles.push_back(new TuileStatique(x, y, -1, tx,TrueX,TrueY));
            tuiles.push_back(new TuileStatique(x, y, 48, tx,TrueX,TrueY));
            break;
        case 21:
            tuiles.push_back(new TuileStatique(x, y, -1, tx,TrueX,TrueY));
            tuiles.push_back(new TuileStatique(x, y, 50, tx,TrueX,TrueY));
            tuiles.push_back(new TuileStatique(x, y, -1, tx,TrueX,TrueY));
            tuiles.push_back(new TuileStatique(x, y, 50, tx,TrueX,TrueY));
            break;
        case 22:
            tuiles.push_back(new TuileStatique(x, y, -1, tx,TrueX,TrueY));
            tuiles.push_back(new TuileStatique(x, y, 52, tx,TrueX,TrueY));
            tuiles.push_back(new TuileStatique(x, y, -1, tx,TrueX,TrueY));
            tuiles.push_back(new TuileStatique(x, y, 52, tx,TrueX,TrueY));
            break;
        case 23:
            tuiles.push_back(new TuileStatique(x, y, -1, tx,TrueX,TrueY));
            tuiles.push_back(new TuileStatique(x, y, 54, tx,TrueX,TrueY));
            tuiles.push_back(new TuileStatique(x, y, -1, tx,TrueX,TrueY));
            tuiles.push_back(new TuileStatique(x, y, 54, tx,TrueX,TrueY));
            break;
        case 24:
            tuiles.push_back(new TuileStatique(x, y, -1, tx,TrueX,TrueY));
            tuiles.push_back(new TuileStatique(x, y, 45, tx,TrueX,TrueY));
            tuiles.push_back(new TuileStatique(x, y, -1, tx,TrueX,TrueY));
            tuiles.push_back(new TuileStatique(x, y, 45, tx,TrueX,TrueY));
            tuiles.push_back(new TuileStatique(x, y, -1, tx,TrueX,TrueY));
            tuiles.push_back(new TuileStatique(x, y, 56, tx,TrueX,TrueY));
            break;
        case 25:
            tuiles.push_back(new TuileStatique(x, y, -1, tx,TrueX,TrueY));
            tuiles.push_back(new TuileStatique(x, y, 47, tx,TrueX,TrueY));
            tuiles.push_back(new TuileStatique(x, y, -1, tx,TrueX,TrueY));
            tuiles.push_back(new TuileStatique(x, y, 47, tx,TrueX,TrueY));
            tuiles.push_back(new TuileStatique(x, y, -1, tx,TrueX,TrueY));
            tuiles.push_back(new TuileStatique(x, y, 47, tx,TrueX,TrueY));
            tuiles.push_back(new TuileStatique(x, y, -1, tx,TrueX,TrueY));
            break;
        case 26:
            tuiles.push_back(new TuileStatique(x, y, -1, tx,TrueX,TrueY));
            tuiles.push_back(new TuileStatique(x, y, 49, tx,TrueX,TrueY));
            tuiles.push_back(new TuileStatique(x, y, -1, tx,TrueX,TrueY));
            tuiles.push_back(new TuileStatique(x, y, 49, tx,TrueX,TrueY));
            tuiles.push_back(new TuileStatique(x, y, -1, tx,TrueX,TrueY));
            tuiles.push_back(new TuileStatique(x, y, 49, tx,TrueX,TrueY));
            tuiles.push_back(new TuileStatique(x, y, -1, tx,TrueX,TrueY));
            break;
        case 27: 
            tuiles.push_back(new TuileStatique(x, y, -1, tx,TrueX,TrueY));
            tuiles.push_back(new TuileStatique(x, y, 51, tx,TrueX,TrueY));
            tuiles.push_back(new TuileStatique(x, y, -1, tx,TrueX,TrueY));
            tuiles.push_back(new TuileStatique(x, y, 51, tx,TrueX,TrueY));
            tuiles.push_back(new TuileStatique(x, y, -1, tx,TrueX,TrueY));
            tuiles.push_back(new TuileStatique(x, y, 51, tx,TrueX,TrueY));
            tuiles.push_back(new TuileStatique(x, y, -1, tx,TrueX,TrueY));
            break;
        case 28:
            tuiles.push_back(new TuileStatique(x, y, -1, tx,TrueX,TrueY));
            tuiles.push_back(new TuileStatique(x, y, 53, tx,TrueX,TrueY));
            tuiles.push_back(new TuileStatique(x, y, -1, tx,TrueX,TrueY));
            tuiles.push_back(new TuileStatique(x, y, 53, tx,TrueX,TrueY));
            tuiles.push_back(new TuileStatique(x, y, -1, tx,TrueX,TrueY));
            tuiles.push_back(new TuileStatique(x, y, 53, tx,TrueX,TrueY));
            tuiles.push_back(new TuileStatique(x, y, -1, tx,TrueX,TrueY));
            break;
        case 29:
            tuiles.push_back(new TuileStatique(x, y, -1, tx,TrueX,TrueY));
            tuiles.push_back(new TuileStatique(x, y, 55, tx,TrueX,TrueY));
            tuiles.push_back(new TuileStatique(x, y, -1, tx,TrueX,TrueY));
            tuiles.push_back(new TuileStatique(x, y, 55, tx,TrueX,TrueY));
            tuiles.push_back(new TuileStatique(x, y, -1, tx,TrueX,TrueY));
            tuiles.push_back(new TuileStatique(x, y, 55, tx,TrueX,TrueY));
            tuiles.push_back(new TuileStatique(x, y, -1, tx,TrueX,TrueY));
            break;
        case 30:
            tuiles.push_back(new TuileStatique(x, y, -1, tx,TrueX,TrueY));
            tuiles.push_back(new TuileStatique(x, y, 44, tx,TrueX,TrueY));
            tuiles.push_back(new TuileStatique(x, y, -1, tx,TrueX,TrueY));
            tuiles.push_back(new TuileStatique(x, y, 44, tx,TrueX,TrueY));
            tuiles.push_back(new TuileStatique(x, y, -1, tx,TrueX,TrueY));
            tuiles.push_back(new TuileStatique(x, y, 44, tx,TrueX,TrueY));
            tuiles.push_back(new TuileStatique(x, y, -1, tx,TrueX,TrueY));
            break;
        case 31:
            tuiles.push_back(new TuileStatique(x, y, -1, tx,TrueX,TrueY));
            tuiles.push_back(new TuileStatique(x, y, 46, tx,TrueX,TrueY));
            tuiles.push_back(new TuileStatique(x, y, -1, tx,TrueX,TrueY));
            tuiles.push_back(new TuileStatique(x, y, 46, tx,TrueX,TrueY));
            tuiles.push_back(new TuileStatique(x, y, -1, tx,TrueX,TrueY));
            tuiles.push_back(new TuileStatique(x, y, 46, tx,TrueX,TrueY));
            tuiles.push_back(new TuileStatique(x, y, -1, tx,TrueX,TrueY));

            break;
        case 32:
            tuiles.push_back(new TuileStatique(x, y, -1, tx,TrueX,TrueY));
            tuiles.push_back(new TuileStatique(x, y, 48, tx,TrueX,TrueY));
            tuiles.push_back(new TuileStatique(x, y, -1, tx,TrueX,TrueY));
            tuiles.push_back(new TuileStatique(x, y, 48, tx,TrueX,TrueY));
            tuiles.push_back(new TuileStatique(x, y, -1, tx,TrueX,TrueY));
            tuiles.push_back(new TuileStatique(x, y, 48, tx,TrueX,TrueY));
            tuiles.push_back(new TuileStatique(x, y, -1, tx,TrueX,TrueY));
            break;
        case 33:
            tuiles.push_back(new TuileStatique(x, y, -1, tx,TrueX,TrueY));
            tuiles.push_back(new TuileStatique(x, y, 50, tx,TrueX,TrueY));
            tuiles.push_back(new TuileStatique(x, y, -1, tx,TrueX,TrueY));
            tuiles.push_back(new TuileStatique(x, y, 50, tx,TrueX,TrueY));
            tuiles.push_back(new TuileStatique(x, y, -1, tx,TrueX,TrueY));
            tuiles.push_back(new TuileStatique(x, y, 50, tx,TrueX,TrueY));
            tuiles.push_back(new TuileStatique(x, y, -1, tx,TrueX,TrueY));
            break;
        case 34:
            tuiles.push_back(new TuileStatique(x, y, -1, tx,TrueX,TrueY));
            tuiles.push_back(new TuileStatique(x, y, 52, tx,TrueX,TrueY));
            tuiles.push_back(new TuileStatique(x, y, -1, tx,TrueX,TrueY));
            tuiles.push_back(new TuileStatique(x, y, 52, tx,TrueX,TrueY));
            tuiles.push_back(new TuileStatique(x, y, -1, tx,TrueX,TrueY));
            tuiles.push_back(new TuileStatique(x, y, 52, tx,TrueX,TrueY));
            tuiles.push_back(new TuileStatique(x, y, -1, tx,TrueX,TrueY));
            break;
        case 35:
            tuiles.push_back(new TuileStatique(x, y, -1, tx,TrueX,TrueY));
            tuiles.push_back(new TuileStatique(x, y, 54, tx,TrueX,TrueY));
            tuiles.push_back(new TuileStatique(x, y, -1, tx,TrueX,TrueY));
            tuiles.push_back(new TuileStatique(x, y, 54, tx,TrueX,TrueY));
            tuiles.push_back(new TuileStatique(x, y, -1, tx,TrueX,TrueY));
            tuiles.push_back(new TuileStatique(x, y, 54, tx,TrueX,TrueY));
            tuiles.push_back(new TuileStatique(x, y, -1, tx,TrueX,TrueY));
            break;
    }
}
TuileAnimee::~TuileAnimee()
{
    for (unsigned int i = 0; i < tuiles.size(); i++)
        delete tuiles[i];
}
bool TuileAnimee::estAnime()
{
    return true;
}
const float TuileAnimee::getPourcentage ()
{
    return nbr;
}
void TuileAnimee::setPourcentage (float rate)
{
    nbr = rate;
}
Tuile* TuileAnimee::getTuile (int i)
{
    if (static_cast<unsigned int>(i) < tuiles.size())
        return tuiles[i];
    else 
        return nullptr;
}
void TuileAnimee::setVitesse (float speed)
{
    vitesse = speed;
}
const float TuileAnimee::getVitesse ()
{
    return vitesse;
}
void TuileAnimee::ajouterTuile (Tuile* tuile)
{
    tuiles.push_back(tuile);
}
void TuileAnimee::setTuile (int i, Tuile* tuile)
{
    if (static_cast<unsigned int>(i) < tuiles.size())
        tuiles[i] = tuile;
    
}
void TuileAnimee::update (clock_t time)
{
    //if (double(time-debut)/ CLOCKS_PER_SEC > 0.2)
    parent->monterDegat();
    if (double(time-debut)/ CLOCKS_PER_SEC > 0.1)
    {
        nbr++;
        debut = clock();
    }
    if (nbr > tuiles.size()-1)
    {   
        parent->setTuile(trueX,trueY,static_cast<TuileStatique*>(tuiles[tuiles.size()-1])->copy());
        parent->stopDegat();
    }
}
const sf::Sprite& TuileAnimee::getSprite()
{
    return tuiles[nbr]->getSprite();
}
void TuileAnimee::updateSpritePosition(float x, float y)
{
    for (unsigned int i = 0; i < tuiles.size(); i++)
    {
        tuiles[i]->updateSpritePosition(x,y);
        tuiles[i]->setX(this->x);
        tuiles[i]->setY(this->y);
    }
}
void TuileAnimee::updateSpriteScale(float s)
{
    for(unsigned int i = 0; i < tuiles.size(); i++)
        tuiles[i]->updateSpriteScale(s);
}