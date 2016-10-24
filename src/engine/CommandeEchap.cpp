#include "CommandeEchap.h"

using namespace engine;

CommandeEchap::CommandeEchap()
{
    
}
CategorieCommande CommandeEchap::getCategorie()
{
    return CategorieCommande::echap;
}