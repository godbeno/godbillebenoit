#include "TuileAnimee.h"
#include "TuileStatique.h"

using namespace render;

TuileAnimee::TuileAnimee(int x, int y, int id, float rate, float vitesse) : Tuile(x,y,id)
{
    this->pourcentage = rate;
    this->vitesse = vitesse;
    switch(id)
    {
        /*
         * 0-5 : Attaque Personnage rouge
         * 6-11 : Attaque personnage bleu
         * 12-17 : Personnage rouge touché
         * 17-23 : Personnage bleu touché
         * 24-26 : Personnage rouge mort
         * 27-29 : personnage bleu mort
         *
         */
        float tx = sf::VideoMode::getDesktopMode().height/24.;
        case 0:
            tuiles.push_back(new TuileStatique(x, y, id1, tx));
            tuiles.push_back();
            tuiles.push_back();
            tuiles.push_back();
            break;
        case 1: 
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
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
    return pourcentage;
}
void TuileAnimee::setPourcentage (float rate)
{
    pourcentage = rate;
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
void TuileAnimee::update (int64_t time)
{
    
}
void TuileAnimee::sync (int64_t temps)
{
    
}

