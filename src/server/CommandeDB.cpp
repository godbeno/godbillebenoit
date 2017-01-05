#include "CommandeDB.h"

using namespace server;

CommandeDB::CommandeDB()
{
    lsCommandes.clear();
}
std::vector<Commande> CommandeDB::getCommandes (int ep)
{
    std::vector<Commande> tmp;
    for (unsigned int i = 0; i < lsCommandes.size(); i++)
        if (lsCommandes[i].epoch == ep)
            tmp.push_back(lsCommandes[i]);
    return tmp;
}
void CommandeDB::addCommande (Commande cmd)
{
    lsCommandes.push_back(cmd);
}