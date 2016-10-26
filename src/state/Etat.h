// Generated by dia2code
#ifndef STATE__ETAT__H
#define STATE__ETAT__H

#include <vector>

namespace state {
  class ListeElement;
  class GrilleElement;
  class Personnage;
  class Etat;
  class CaseTerrain;
  class Observable;
}

#include "Observable.h"
#include "Personnage.h"
#include "GrilleElement.h"

namespace state {

  /// class Etat - 
  class Etat : public state::Observable {
    // Associations
    // Attributes
  protected:
    ListeElement* liste;
    GrilleElement* grille;
    Personnage* selectionne;
    float zoom;
    int camerax;
    int cameray;
    // Operations
  public:
    Etat ();
    ~Etat ();
    Etat* const clone ();
    void copy (const Etat& other);
    bool const equals (const Etat& other);
    GrilleElement&  getGrille ();
    const ListeElement&  getListe ();
    void setGrille (const GrilleElement& grille);
    void setListe (const ListeElement& list);
    void initialiserTerrain (bool estChateau);
    void ajouterPersonnage (bool equipe, int id, int x, int y);
    void deplacerElement (int i1, int j1, int i2, int j2);
    Personnage* getSelectionne ();
    void setSelectionne (int i, int j);
    void attaquer (int i1, int j1, int i2, int j2);
    std::vector<CaseTerrain*> getCaseAtteignable (Personnage* p);
    std::vector<CaseTerrain*> rechercheCaseRec (CaseTerrain* ct, Personnage* p);
    void setCamerax (int cx);
    int getCamerax ();
    void setCameray (int cy);
    int getCameray ();
    void setZoom (float z);
    float getZoom ();
    void setBrillant (bool b, CaseTerrain* ct);
  };

};

#endif
