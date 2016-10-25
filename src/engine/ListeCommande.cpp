#include "ListeCommande.h"

using namespace engine;

ListeCommande::ListeCommande()
{
    
}
ListeCommande::~ListeCommande()
{
    for (int i = 0; i < 4; i++)
    {
        if (commandes[i+1])
            delete commandes[i+1];
    }
}
Commande* ListeCommande::get(int categorie)
{
    if (categorie > 0 && categorie < 5)
    {
        return commandes[categorie];
    }
    return nullptr;
}
void ListeCommande::set (Commande* cmd)
{
    int x = static_cast<int>(cmd->getCategorie());
    if (commandes[x])
        delete commandes[x];
    commandes[x] = cmd;
}
int ListeCommande::taille ()
{
    int c = 0;
    for (int i = 1; i < 5; i++)
        if (commandes[i])
            c++;
    return c;
}