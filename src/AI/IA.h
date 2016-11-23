// Generated by dia2code
#ifndef AI__IA__H
#define AI__IA__H

#include <ctime>

namespace state {
  class Etat;
};
namespace engine {
  class Moteur;
}

#include "Niveau.h"
#include "state/Etat.h"

namespace AI {

  /// class IA - 
  class IA {
    // Associations
    // Attributes
  private:
    int i;
    Niveau niveau;
    bool attendre;
    clock_t temps;
    bool archer;
  protected:
    state::Etat* etat;
    bool equipe;
    /// 			
    engine::Moteur* moteur;
    // Operations
  public:
    IA (state::Etat* etat, engine::Moteur* moteur, Niveau niv);
    ~IA ();
    bool appliquerAleatoire (bool equipe);
    bool estFini ();
    void reset ();
    state::CaseTerrain* getMeilleureCase (state::Personnage* p);
    void jouer ();
    bool appliquerHeuristique (bool equipe);
    bool appliquerMinMax ();
    int minmax (int prof);
    int fonctionEvaluation (state::Etat* etat);
  };

};

#endif
