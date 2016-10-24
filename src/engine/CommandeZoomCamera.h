// Generated by dia2code
#ifndef ENGINE__COMMANDEZOOMCAMERA__H
#define ENGINE__COMMANDEZOOMCAMERA__H


namespace engine {
  class Commande;
}

#include "CategorieCommande.h"
#include "Commande.h"

namespace engine {

  /// class CommandeZoomCamera - 
  class CommandeZoomCamera : public engine::Commande {
    // Attributes
  private:
    bool estHaut;
    /// 		
    int x;
    int y;
    // Operations
  public:
    CommandeZoomCamera (bool haut, int i, int j);
    CategorieCommande getCategorie ();
    bool getDirection ();
    int getX ();
    int getY ();
  };

};

#endif
