// Generated by dia2code
#ifndef RENDER__TUILEANIMEE__H
#define RENDER__TUILEANIMEE__H

#include <vector>
#include <stdint.h>

namespace render {
  class Tuile;
}

#include "Tuile.h"

namespace render {

  /// class TuileAnimee - 
  class TuileAnimee : public render::Tuile {
    // Attributes
  private:
    std::vector<Tuile*> tuiles;
    float pourcentage;
    float vitesse;
    int64_t debut;
    // Operations
  public:
    TuileAnimee (int x, int y, int id, float rate, float vitesse);
    ~TuileAnimee ();
    bool estAnime ();
    const float getPourcentage ();
    void setPourcentage (float rate);
    Tuile* getTuile (int i);
    void setVitesse (float speed);
    const float getVitesse ();
    void ajouterTuile (Tuile* tuile);
    void setTuile (int i, Tuile* tuile);
    void update (int64_t time);
    void sync (int64_t temps);
  };

};

#endif