// Generated by dia2code
#ifndef RENDER__MESSAGE__H
#define RENDER__MESSAGE__H

#include <ctime>
#include <SFML/Graphics.hpp>

namespace render {

  /// class Message - 
  class Message {
    // Attributes
  private:
    sf::Font font;
    sf::Text texte;
    bool active;
    bool tour;
    clock_t temps;
    bool fin;
    // Operations
  public:
    Message ();
    void dessiner (sf::RenderWindow* window);
    void changerTour ();
    void finDePartie (bool b);
    void finAffichage ();
  };

};

#endif
