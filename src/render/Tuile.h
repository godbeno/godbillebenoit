// Generated by dia2code
#ifndef RENDER__TUILE__H
#define RENDER__TUILE__H

#include <SFML/Graphics.hpp>

namespace render {

  /// class Tuile - 
  class Tuile {
    // Attributes
  protected:
    float x;
    float y;
    int id;
    int trueX;
    int trueY;
    // Operations
  public:
    Tuile (float x, float y, int id);
    virtual ~Tuile ();
    virtual bool estAnime () = 0;
    int const getID ();
    float const getX ();
    float const getY ();
    void setX (float x);
    void setY (float y);
    void setID (int id);
    virtual const sf::Sprite& getSprite () = 0;
  };

};

#endif
