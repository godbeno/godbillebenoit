// Generated by dia2code
#ifndef RENDER__BOUTON__H
#define RENDER__BOUTON__H

#include <SFML/Graphics.hpp>

namespace render {

  /// class Bouton - 
  class Bouton {
    // Attributes
  private:
    int ID;
    sf::Sprite sprite;
    sf::Texture texture;
    sf::Text texte;
    sf::Font font;
    bool aTexte;
    int largeur;
    int hauteur;
    // Operations
  public:
    Bouton (int ID);
    void initBouton (int ID);
    void setID (int ID);
    int getID ();
    sf::Sprite getSprite ();
    bool getATexte ();
    sf::Text getTexte ();
  };

};

#endif