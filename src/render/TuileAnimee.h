// Generated by dia2code
#ifndef RENDER__TUILEANIMEE__H
#define RENDER__TUILEANIMEE__H

#include <vector>
#include <ctime>
#include <ctime>
#include <SFML/Graphics.hpp>

namespace render {
  class Tuile;
  class Couche;
}

#include "Tuile.h"
#include "Couche.h"

namespace render {

  /// class TuileAnimee - 
  class TuileAnimee : public render::Tuile {
    // Attributes
  private:
    std::vector<Tuile*> tuiles;
    float nbr;
    float vitesse;
    clock_t debut;
    Couche* parent;
    // Operations
  public:
    TuileAnimee (float x, float y, int id, float vitesse, Couche* couche, int TrueX, int TrueY);
    ~TuileAnimee ();
    bool estAnime ();
    const float getPourcentage ();
    void setPourcentage (float rate);
    Tuile* getTuile (int i);
    void setVitesse (float speed);
    const float getVitesse ();
    void ajouterTuile (Tuile* tuile);
    void setTuile (int i, Tuile* tuile);
    void update (clock_t time);
    const sf::Sprite& getSprite ();
    void updateSpritePosition (float x, float y);
  };

};

#endif
