#include "TuileStatique.h"

using namespace render;
using namespace sf;

/*
private:
    int hauteur;
    int largeur;
    sf::Texture texture;
    sf::Sprite sprite;
    // Operations
  public:
    TuileStatique (int id);
    ~TuileStatique ();
    int const getHauteur ();
    int const getLargeur ();
    void setHauteur (int hauteur);
    void setLargeur (int largeur);
    const sf::Sprite& getSprite ();
    bool estAnime ();*/
TuileStatique::TuileStatique(int id)
{
    hauteur = 100;
    largeur = 100;
    switch(id)
    {
        case 0: //Herbe
            texture.load("res/herbe.png");
            break;
    }
}