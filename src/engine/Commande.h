// Generated by dia2code
#ifndef ENGINE__COMMANDE__H
#define ENGINE__COMMANDE__H


#include "CategorieCommande.h"

namespace engine {

  /// class Commande - 
  class Commande {
    // Operations
  public:
    virtual CategorieCommande getCategorie () = 0;
  };

};

#endif