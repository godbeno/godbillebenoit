// Generated by dia2code
#ifndef STATE__EVENEMENTETAT__H
#define STATE__EVENEMENTETAT__H


namespace state {
  class Etat;
}

#include "TypeEvenementEtat.h"

namespace state {

  /// class EvenementEtat - 
  class EvenementEtat {
    // Associations
    // Attributes
  private:
    TypeEvenementEtat id;
    Etat* etat;
    // Operations
  public:
    EvenementEtat (TypeEvenementEtat id, Etat* etat);
  };

};

#endif
