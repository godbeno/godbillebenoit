// Generated by dia2code
#ifndef AI__IA__H
#define AI__IA__H


namespace state {
  class Etat;
}

#include "state/Etat.h"

namespace AI {

  /// class IA - 
  class IA {
    // Attributes
  protected:
    state::Etat* etat;
    bool equipe;
    // Operations
  public:
    IA (state::Etat* etat);
    ~IA ();
    void appliquer ( bool);
  };

};

#endif
