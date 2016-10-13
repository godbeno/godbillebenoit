#include "TuileAnimee.h"

using namespace render;

TuileAnimee::TuileAnimee(int x, int y, int id, float rate, float vitesse) : Tuile(x,y,id)
{
    this->pourcentage = rate;
    this->vitesse = vitesse;
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

