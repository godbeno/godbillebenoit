// Generated by dia2code
#ifndef ENGINE__ACTION__H
#define ENGINE__ACTION__H


namespace state {
  class Etat;
}

namespace engine {

  /// class Action - 
  class Action {
    // Operations
  public:
    virtual ~Action ();
    virtual void appliquer (state::Etat* etat) = 0;
  };

};

#endif
