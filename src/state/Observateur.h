// Generated by dia2code
#ifndef STATE__OBSERVATEUR__H
#define STATE__OBSERVATEUR__H


namespace state {
  class EvenementEtat;
}

#include "EvenementEtat.h"

namespace state {

  /// class Observateur - 
  class Observateur {
    // Operations
  public:
    virtual void changementEtat (EvenementEtat& e) = 0;
  };

};

#endif