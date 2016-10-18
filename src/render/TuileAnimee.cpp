#include "TuileAnimee.h"
#include "TuileStatique.h"
#include <iostream>
#include <ctime>

using namespace render;

TuileAnimee::TuileAnimee(int x, int y, int id, float vitesse) : Tuile(x,y,id)
{
    nbr = 0;
    this->vitesse = vitesse;
    float tx = sf::VideoMode::getDesktopMode().height/24.;
    debut = clock();
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
         * 17-23 : Personnage bleu touché
         * 24-26 : Personnage rouge mort
         * 27-29 : personnage bleu mort
         *
         */
        case 0: 
            tuiles.push_back(new TuileStatique(x, y, 60, tx));
            tuiles.push_back(new TuileStatique(x, y, 45, tx));
            tuiles.push_back(new TuileStatique(x, y, 60, tx));
            tuiles.push_back(new TuileStatique(x, y, 45, tx));
            break;
        case 1: 
            tuiles.push_back(new TuileStatique(x, y, 63, tx));
            tuiles.push_back(new TuileStatique(x, y, 64, tx));
            tuiles.push_back(new TuileStatique(x, y, 63, tx));
            tuiles.push_back(new TuileStatique(x, y, 64, tx));
            tuiles.push_back(new TuileStatique(x, y, 47, tx));
            break;
        case 2:
            tuiles.push_back(new TuileStatique(x, y, 66, tx));
            tuiles.push_back(new TuileStatique(x, y, 49, tx));
            tuiles.push_back(new TuileStatique(x, y, 66, tx));
            tuiles.push_back(new TuileStatique(x, y, 49, tx));
            break;
        case 3:
            tuiles.push_back(new TuileStatique(x, y, 68, tx));
            tuiles.push_back(new TuileStatique(x, y, 51, tx));
            tuiles.push_back(new TuileStatique(x, y, 68, tx));
            tuiles.push_back(new TuileStatique(x, y, 51, tx));
            break;
        case 4:
            tuiles.push_back(new TuileStatique(x, y, 70, tx));
            tuiles.push_back(new TuileStatique(x, y, 53, tx));
            tuiles.push_back(new TuileStatique(x, y, 70, tx));
            tuiles.push_back(new TuileStatique(x, y, 53, tx));
            break;
        case 5:
            tuiles.push_back(new TuileStatique(x, y, 72, tx));
            tuiles.push_back(new TuileStatique(x, y, 55, tx));
            tuiles.push_back(new TuileStatique(x, y, 72, tx));
            tuiles.push_back(new TuileStatique(x, y, 55, tx));
            break;
        case 6: 
            tuiles.push_back(new TuileStatique(x, y, 60, tx));
            tuiles.push_back(new TuileStatique(x, y, 45, tx));
            tuiles.push_back(new TuileStatique(x, y, 60, tx));
            tuiles.push_back(new TuileStatique(x, y, 45, tx));
            break;
        case 7: 
            tuiles.push_back(new TuileStatique(x, y, 63, tx));
            tuiles.push_back(new TuileStatique(x, y, 64, tx));
            tuiles.push_back(new TuileStatique(x, y, 63, tx));
            tuiles.push_back(new TuileStatique(x, y, 64, tx));
            tuiles.push_back(new TuileStatique(x, y, 47, tx));
            break;
        case 8:
            tuiles.push_back(new TuileStatique(x, y, 66, tx));
            tuiles.push_back(new TuileStatique(x, y, 49, tx));
            tuiles.push_back(new TuileStatique(x, y, 66, tx));
            tuiles.push_back(new TuileStatique(x, y, 49, tx));
            break;
        case 9:
            tuiles.push_back(new TuileStatique(x, y, 68, tx));
            tuiles.push_back(new TuileStatique(x, y, 51, tx));
            tuiles.push_back(new TuileStatique(x, y, 68, tx));
            tuiles.push_back(new TuileStatique(x, y, 51, tx));
            break;
        case 10:
            tuiles.push_back(new TuileStatique(x, y, 70, tx));
            tuiles.push_back(new TuileStatique(x, y, 53, tx));
            tuiles.push_back(new TuileStatique(x, y, 70, tx));
            tuiles.push_back(new TuileStatique(x, y, 53, tx));
            break;
        case 11:
            tuiles.push_back(new TuileStatique(x, y, 72, tx));
            tuiles.push_back(new TuileStatique(x, y, 55, tx));
            tuiles.push_back(new TuileStatique(x, y, 72, tx));
            tuiles.push_back(new TuileStatique(x, y, 55, tx));
            break;
        case 6:
            break;
        case 7:
            break;
        case 8:
            break; 
        case 9:
            break;
        case 10:
            break;
        case 11:
            break;
        case 12:
            break;
        case 13:
            break;
        case 14:
            break;
        case 15: 
            break;
        case 16:
            break;
        case 17:
            break;
        case 18:
            break;
        case 19:
            break;
        case 20:
            break;
        case 21:
            break;
        case 22:
            break;
        case 23:
            break;
        case 24:
            break;
        case 25: 
            break;
        case 26:
            break;
        case 27:
            break;
        case 28:
            break;
        case 29:
            break;
    }
    /*
     * Tests avec l'Id pour choisir l'animation à afficher [initialisation tuiles]
     * Initialisation start avec horloge (à suivre)
     *  
     */
}
TuileAnimee::~TuileAnimee()
{
    
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
    std::cout << double(time-debut)/ CLOCKS_PER_SEC << std::endl;
    if (double(time-debut)/ CLOCKS_PER_SEC > 0.2)
    {
        nbr++;
        debut = clock();
    }
    if (nbr > tuiles.size()-1)
        nbr = 0;
}
const sf::Sprite& TuileAnimee::getSprite()
{
    return tuiles[nbr]->getSprite();
}
