// Generated by dia2code
#ifndef ENGINE__COMMANDEFLECHE__H
#define ENGINE__COMMANDEFLECHE__H


namespace engine {
  class Commande;
}

#include "Direction.h"
#include "CategorieCommande.h"
#include "Commande.h"

namespace engine {

  /// class CommandeFleche - 
  class CommandeFleche : public engine::Commande {
    // Attributes
  private:
    Direction direction;
    // Operations
  public:
    CommandeFleche (Direction direction);
    CategorieCommande getCategorie ();
    Direction getDirection ();
  };

};

#endif
