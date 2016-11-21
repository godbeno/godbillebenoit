// Generated by dia2code
#ifndef ENGINE__ATTAQUER__H
#define ENGINE__ATTAQUER__H


namespace state {
  class Etat;
};
namespace engine {
  class Action;
}

#include "Action.h"

namespace engine {

  /// class Attaquer - 
  class Attaquer : public engine::Action {
    // Attributes
  public:
    int degat;
  protected:
    int attaquantX;
    int attaquantY;
    int cibleX;
    int cibleY;
    // Operations
  public:
    Attaquer (int Attaquantx, int Attaquanty, int Ciblex, int Cibley);
    void appliquer (state::Etat* etat, bool afficher);
    state::CaseTerrain* getCaseArrivee (state::Etat* etat);
    void annuler (state::Etat* etat, bool afficher);
  };

};

#endif
