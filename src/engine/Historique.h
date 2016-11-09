// Generated by dia2code
#ifndef ENGINE__HISTORIQUE__H
#define ENGINE__HISTORIQUE__H


namespace state {
  class Etat;
};
namespace engine {
  class ListeActions;
  class Action;
  class Moteur;
}

#include "Moteur.h"

namespace engine {

  /// class Historique - 
  class Historique {
    // Associations
    // Attributes
  private:
    state::Etat* etatPrecedent;
    ListeActions* lsHistorique;
    // Operations
  public:
    Historique (state::Etat* sauvegarde);
    void ajouterAction (Action* action);
    void annulerUneAction (state::Etat* etat);
    void annulerToutesActions (state::Etat* etat);
    void retourSauvegarde (state::Etat* etat);
  };

};

#endif
