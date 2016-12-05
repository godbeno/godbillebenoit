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
    bool tour;
    bool joueur1IA;
    bool joueur2IA;
    std::vector<int> donneesInit;
    // Operations
  public:
    Etat ();
    ~Etat ();
    Etat* const clone ();
    void copy (const Etat& other);
    bool const equals (const Etat& other);
    GrilleElement&  getGrille ();
    ListeElement&  getListe ();
    void setGrille (const GrilleElement& grille);
    void setListe (const ListeElement& list);
    void initialiserTerrain (bool estChateau);
    void ajouterPersonnage (bool equipe, int id, int x, int y, bool afficher);
    void deplacerElement (int i1, int j1, int i2, int j2, bool afficher, bool annuler);
    Personnage* getSelectionne ();
    void setSelectionne (int i, int j, bool afficher);
    void attaquer (int i1, int j1, int i2, int j2, bool afficher);
    std::vector<CaseTerrain*> getCaseAtteignable (Personnage* p);
    std::vector<CaseTerrain*> rechercheCaseRec (CaseTerrain* ct, Personnage* p);
    void setCamerax (int cx);
    int getCamerax ();
    void setCameray (int cy);
    int getCameray ();
    void setZoom (float z);
    float getZoom ();
    void setBrillant (bool b, CaseTerrain* ct);
    float getCoeff ();
    std::vector<CaseTerrain*> getCaseAttaquable (Personnage* p);
    void setRouge (bool b, CaseTerrain* ct);
    void finDuTour ();
    Personnage* getPlusProcheEnnemi (Personnage* p);
    int partieContinue ();
    void configurerJoueur (bool joueur1estIA, bool joueur2estIA);
    void changerTour (bool afficher);
    bool getTour ();
    bool joueurIA ();
    int getDonneesInit (int indice);
    void setDonneesInit (int indice, int donnee);
  };

};

#endif
