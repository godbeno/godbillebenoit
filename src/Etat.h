// Generated by dia2code
#ifndef ETAT__H
#define ETAT__H

/// class Etat - 
class Etat {
  // Associations
  // Attributes
protected:
  ListeElement liste;
  GrilleElement grille;
  // Operations
public:
  State ();
  ~State ();
  State* const clone ();
  void copy (const Etat& other);
  bool const equals (const Etat& other);
  const GrilleElement& const getGrille ();
  GrilleElement getGrille ();
  const ListeElement& const getListe ();
  ListeElement& getListe ();
  const Element* const getElement (int idx);
  Element* getElement (int idx);
  void setGrille (const GrilleElement& grille);
  void setListe (const ListeElement& list);
};

#endif
