// Generated by dia2code
#ifndef RENDER__SCENE__H
#define RENDER__SCENE__H


namespace render {
  class Couche;
}

#include "Couche.h"

namespace render {

  /// class Scene - 
  class Scene {
    // Associations
    // Attributes
  private:
    Couche* couchePersonnage;
    Couche* coucheTerrain;
    // Operations
  public:
    Scene ();
    void changementEtat (state::EvenementEtat& e);
  };

};

#endif
