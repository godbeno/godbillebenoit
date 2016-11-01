// Generated by dia2code
#ifndef RENDER__TUILESTATIQUE__H
#define RENDER__TUILESTATIQUE__H

#include <SFML/Graphics.hpp>

namespace render {
  class TuileStatique;
  class Tuile;
}

#include "Tuile.h"

namespace render {

  /// class TuileStatique - 
  class TuileStatique : public render::Tuile {
    // Attributes
  private:
    int hauteur;
    int largeur;
    sf::Texture texture;
    sf::Sprite sprite;
    int id;
    int w;
    bool estAffiche;
    // Operations
  public:
    TuileStatique (int x, int y, int id, float w);
    ~TuileStatique ();
    int const getHauteur ();
    int const getLargeur ();
    void setHauteur (int hauteur);
    void setLargeur (int largeur);
    const sf::Sprite& getSprite ();
    bool estAnime ();
    TuileStatique* copy ();
    bool getEstAffiche ();
    void setEstAffiche (bool b);
    void updateSpritePosition (int x, int y);
    void updateSpriteScale (float s);
  };

};

#endif
