// Generated by dia2code
#ifndef ENGINE__LISTEACTIONS__H
#define ENGINE__LISTEACTIONS__H

#include <vector>

namespace state {
  class Etat;
};
namespace engine {
  class Action;
}

#include "Action.h"

namespace engine {

  /// class ListeActions - 
  class ListeActions {
    // Associations
    // Attributes
  protected:
    state::Etat& s;
    std::vector<Action*> actions;
    // Operations
  public:
    void ListeActions (state::Etat& s);
    ~ListeActions ();
    int taille ();
    Action* const get (int i);
    void ajouter (Action* action);
  };

};

#endif
