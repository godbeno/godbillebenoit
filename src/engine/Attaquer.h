// Generated by dia2code
#ifndef ENGINE__ATTAQUER__H
#define ENGINE__ATTAQUER__H


namespace engine {
  class Action;
}

#include "Action.h"

namespace engine {

  /// class Attaquer - 
  class Attaquer : public engine::Action {
    // Attributes
  protected:
    int Attaquantx;
    int Attaquanty;
    int Ciblex;
    int Cibley;
    // Operations
  public:
    Attaquer (int Attaquantx, int Attaquanty, int Ciblex, int Cibley);
  };

};

#endif
