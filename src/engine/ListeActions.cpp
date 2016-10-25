#include "ListeActions.h"

using namespace engine;

ListeActions::ListeActions()
{
    
}
ListeActions::ListeActions(state::Etat* s)
{
   actions.clear();
   this->s = s;
}

ListeActions::~ListeActions()
{
    for (unsigned int i = 0; i < actions.size(); i++)
    {
        delete actions[i];
    }
}


Action* const ListeActions::get (int i)
{
    if (static_cast<unsigned int>(i) <actions.size()) 
        return actions[i];
    else
        return nullptr;
}

void ListeActions::ajouter (Action* action)
{
   actions.push_back(action);
}
void ListeActions::appliquer()
{
    for(unsigned int i = 0; i < actions.size(); i++)
        actions[i]->appliquer(s);
}
int ListeActions::taille()
{
    return actions.size();
}


