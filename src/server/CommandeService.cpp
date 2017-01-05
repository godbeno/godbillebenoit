#include "CommandeService.h"

using namespace server;

CommandeService::CommandeService(CommandeDB& commandeDB) : AbstractService("/commande"), cmdDB(commandeDB)
{
}

HttpStatus CommandeService::get(Json::Value& out, int epoch) const
{
    //On récupère les commandes de cette époque
    vector<Commande> liste = cmdDB.getCommandes(epoch);
    //On les renvoie au format JSON
    
}

HttpStatus CommandeService::put(Json::Value& in)
{
    Commande cmd;
    cmd.epoch = in["epoch"];
    cmd.type = in["type"];
    cmd.joueur = in["joueur"];
    cmd.ancx = in["ancx"];
    cmd.ancy = in["ancy"];
    cmd.newx = in["newx"];
    cmd.newy = in["newy"];
    cmd.degat = in["degat"];
    cmd.sauvEquipe = in["sauvEquipe"];
    cmd.sauvType = in["sauvType"];
    cmd.afficher = in["afficher"];
    cmdDB.addCommande(cmd);
    return HttpStatus(200);
}
