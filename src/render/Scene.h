// Generated by dia2code
#ifndef RENDER__SCENE__H
#define RENDER__SCENE__H

#include <SFML/Graphics.hpp>

namespace render {
  class Couche;
}

#include "Couche.h"

namespace render {

  /// class Scene - 
  class Scene {
    // Associations
    // Attributes
  public:
    sf::RenderWindow* window;
  private:
    Couche* couchePersonnage;
    Couche* coucheTerrain;
    state::Etat* etat;
    // Operations
  public:
    Scene (state::Etat* etat, sf::RenderWindow* window);
    void changementEtat (state::EvenementEtat& e);
    void afficher ();
  };

};

#endif
