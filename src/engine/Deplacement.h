// Generated by dia2code
#ifndef ENGINE__DEPLACEMENT__H
#define ENGINE__DEPLACEMENT__H


namespace engine {
  class Action;
}

#include "Action.h"

namespace engine {

  /// class Deplacement - 
  class Deplacement : public engine::Action {
    // Attributes
  public:
    int Originex;
    int Originey;
    int Ciblex;
    int Cibley;
    // Operations
  public:
    Deplacement (int Originex, int Originey, int Ciblex, int Cibley);
  };

};

#endif
