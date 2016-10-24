#include "ListeActions.h"

using namespace engine;

ListeActions::ListeActions(state::Etat& s)
{
   actions.clear();
   this->s = s;
}

ListeActions::~ListeActions()
{
    for (unsigned int i = 0; i < actions.taille(); i++)
    {
        delete elements[i];
    }
}

int ListeActions::taille()
{
   return actions.size();
}

Action* const get (int i)
{
    if (static_cast<unsigned int>(i) <actions.size()) 
        return actions[i];
    else
        return nullptr;
}

void ajouter (Action* action)
{
   actions.push_back(action);
}


