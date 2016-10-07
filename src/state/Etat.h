// Generated by dia2code
#ifndef ETAT__H
#define ETAT__H

#include "GrilleElement.h"
#include "TypePersonnage.h"
/// class Etat - 
class Etat {
  // Associations
  // Attributes
protected:
  ListeElement *liste;
  GrilleElement *grille;
  // Operations
public:
  Etat ();
  ~Etat ();
  Etat* const clone ();
  void copy (const Etat& e);
  bool const equals (const Etat& other);
  GrilleElement getGrille ();
  ListeElement getListe ();
  void setGrille (const GrilleElement& grille);
  void setListe (const ListeElement& list);
  void initialiserTerrain();
  void ajouterPersonnage(bool equipe, int id);
};

#endif
