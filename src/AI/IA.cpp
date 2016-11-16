#include "IA.h"
#include "engine.h"
#include "state.h"
#include <iostream>
#include <unistd.h>

using namespace AI;
using namespace engine;
using namespace state;


IA::IA (state::Etat* etat, engine::Moteur* moteur)
{
   this->etat = etat;
   this->moteur = moteur;
   i = 575;
}

bool IA::appliquer(bool equipe)
{
    std::cout << "1" << std::endl;
    if (etat->getGrille().get(i)->estPersonnage())
    {
        std::cout << "2" << std::endl;
        if(static_cast<Personnage*>(etat->getGrille().get(i))->getEquipe()==equipe)
        {

            std::cout << "NOUVEAU PERSONNAGE UTILISABLE " << std::endl;
            //etat->setSelectionne(static_cast<Personnage*>(etat->getListe().get(i))->getX(), static_cast<Personnage*>(etat->getListe().get(i))->getY());
            if (etat->getSelectionne() == nullptr)
            {
                moteur->ajouterAction(new Selection(etat->getGrille().get(i)->getX(), etat->getGrille().get(i)->getY()));
                moteur->convertirCommande();
                return false;
            }
            std::cout << "PA du perso courant = " << static_cast<Personnage*>(etat->getListe().get(i))->getPA() << std::endl;
            //std::cout << "PA du perso courant = " << etat->getSelectionne()->getPA() << std::endl;
            if (static_cast<Personnage*>(etat->getListe().get(i))->getPA() <= 0)
            {
                i++;
                moteur->ajouterAction(new Selection(-1, -1));
                return false;
            }
            if (static_cast<Personnage*>(etat->getListe().get(i))->getPA() > 1 && etat->getCaseAttaquable(static_cast<Personnage*>(etat->getListe().get(i))).size() != 0)
            {  
                std::cout << "Il attaque depuis " << etat->getListe().get(i)->getX() << " , " << etat->getListe().get(i)->getY() << " vers " << etat->getCaseAttaquable(static_cast<Personnage*>(etat->getListe().get(i)))[0]->getX() << " , " << etat->getCaseAttaquable(static_cast<Personnage*>(etat->getListe().get(i)))[0]->getY() << std::endl;
                moteur->ajouterAction(new Attaquer(static_cast<Personnage*>(etat->getListe().get(i))->getX(),static_cast<Personnage*>(etat->getListe().get(i))->getY(), etat->getCaseAttaquable(static_cast<Personnage*>(etat->getListe().get(i)))[0]->getX(), etat->getCaseAttaquable(static_cast<Personnage*>(etat->getListe().get(i)))[0]->getY()));
                //etat->attaquer(etat->getListe().get(i)->getX(),etat->getListe().get(i)->getY(), etat->getCaseAttaquable(static_cast<Personnage*>(etat->getListe().get(i)))[0]->getX(), etat->getCaseAttaquable(static_cast<Personnage*>(etat->getListe().get(i)))[0]->getY());
            } 
            else if (etat->getCaseAtteignable(static_cast<Personnage*>(etat->getListe().get(i))).size() != 0)
            {
                std::cout << "Il se déplace de " << static_cast<Personnage*>(etat->getListe().get(i))->getX() << " , " << static_cast<Personnage*>(etat->getListe().get(i))->getY() << " vers " << etat->getCaseAtteignable(static_cast<Personnage*>(etat->getListe().get(i)))[0]->getX() << " , "<< etat->getCaseAtteignable(static_cast<Personnage*>(etat->getListe().get(i)))[0]->getY() << std::endl;
                Deplacement* dep;
                int compt = -1;
                {
                    compt++;
                    dep = new Deplacement(static_cast<Personnage*>(etat->getListe().get(i))->getX(),static_cast<Personnage*>(etat->getListe().get(i))->getY(),etat->getCaseAtteignable(static_cast<Personnage*>(etat->getListe().get(i)))[compt]->getX(),etat->getCaseAtteignable(static_cast<Personnage*>(etat->getListe().get(i)))[compt]->getY());
                } while (dep->getDistance() > static_cast<Personnage*>(etat->getListe().get(i))->getPA() && compt < etat->getCaseAtteignable(static_cast<Personnage*>(etat->getListe().get(i))).size());
                //moteur->ajouterAction(new Deplacement(static_cast<Personnage*>(etat->getListe().get(i))->getX(),static_cast<Personnage*>(etat->getListe().get(i))->getY(),etat->getCaseAtteignable(static_cast<Personnage*>(etat->getListe().get(i)))[0]->getX(),etat->getCaseAtteignable(static_cast<Personnage*>(etat->getListe().get(i)))[0]->getY()));
                if (compt < etat->getCaseAtteignable(static_cast<Personnage*>(etat->getListe().get(i))).size())
                {
                    moteur->ajouterAction(dep);
                }
                    //etat->deplacerElement(static_cast<Personnage*>(etat->getListe().get(i))->getX(),static_cast<Personnage*>(etat->getListe().get(i))->getY(),etat->getCaseAtteignable(static_cast<Personnage*>(etat->getListe().get(i)))[0]->getX(),etat->getCaseAtteignable(static_cast<Personnage*>(etat->getListe().get(i)))[0]->getX());
            }
            else
            {
                std::cout << "Cas douteux de d'Alembert" << std::endl;
            }
            moteur->convertirCommande();
            return true;
        }
        else
        {
            i++;
            moteur->ajouterAction(new Selection(-1, -1));
            return false;
        }
    }
    else
    {
        i++;
        moteur->ajouterAction(new Selection(-1, -1));
        return false;
        //std::cout << "PERSONNAGE NON UTILISABLE" << std::endl;
    }
}
 	
IA::~IA()
{
    delete this;
}
bool IA::estFini()
{
    return (i >= this->etat->getListe().size()); 
}
/*void IA::appliquer(bool equipe)
{
    std::cout << "Etonnant !" << std::endl;
   for (int i=0;i< this->etat->getListe().size();i++)
   { 
       std::cout << "CHANGEMENT DE PERSONNAGE " << std::endl;
       if (etat->getListe().get(i)->estPersonnage())
       {
           if(static_cast<Personnage*>(etat->getListe().get(i))->getEquipe()==equipe)
           {
               
               std::cout << "NOUVEAU PERSONNAGE UTILISABLE " << std::endl;
               etat->setSelectionne(static_cast<Personnage*>(etat->getListe().get(i))->getX(), static_cast<Personnage*>(etat->getListe().get(i))->getY());
               int paTmp = static_cast<Personnage*>(etat->getListe().get(i))->getPA();
               while (paTmp > 0)
               {        
                   std::cout << "PA du perso courant = " << static_cast<Personnage*>(etat->getListe().get(i))->getPA() << std::endl;
                   if (static_cast<Personnage*>(etat->getListe().get(i))->getPA() > 1 && etat->getCaseAttaquable(static_cast<Personnage*>(etat->getListe().get(i))).size() != 0)
                   {  
                       std::cout << "Il attaque depuis " << etat->getListe().get(i)->getX() << " , " << etat->getListe().get(i)->getY() << " vers " << etat->getCaseAttaquable(static_cast<Personnage*>(etat->getListe().get(i)))[0]->getX() << " , " << etat->getCaseAttaquable(static_cast<Personnage*>(etat->getListe().get(i)))[0]->getY() << std::endl;
                       moteur->ajouterAction(new Attaquer(etat->getListe().get(i)->getX(),etat->getListe().get(i)->getY(), etat->getCaseAttaquable(static_cast<Personnage*>(etat->getListe().get(i)))[0]->getX(), etat->getCaseAttaquable(static_cast<Personnage*>(etat->getListe().get(i)))[0]->getY()));
                       paTmp -= 2;
                       //etat->attaquer(etat->getListe().get(i)->getX(),etat->getListe().get(i)->getY(), etat->getCaseAttaquable(static_cast<Personnage*>(etat->getListe().get(i)))[0]->getX(), etat->getCaseAttaquable(static_cast<Personnage*>(etat->getListe().get(i)))[0]->getY());
                   } 
                   else if (etat->getCaseAtteignable(static_cast<Personnage*>(etat->getListe().get(i))).size() != 0)
                   {
                       std::cout << "Il se déplace de " << static_cast<Personnage*>(etat->getListe().get(i))->getX() << " , " << static_cast<Personnage*>(etat->getListe().get(i))->getY() << " vers " << etat->getCaseAtteignable(static_cast<Personnage*>(etat->getListe().get(i)))[0]->getX() << " , "<< etat->getCaseAtteignable(static_cast<Personnage*>(etat->getListe().get(i)))[0]->getY() << std::endl;
                       Deplacement* dep;
                       int compt = -1;
                       {
                           compt++;
                           dep = new Deplacement(static_cast<Personnage*>(etat->getListe().get(i))->getX(),static_cast<Personnage*>(etat->getListe().get(i))->getY(),etat->getCaseAtteignable(static_cast<Personnage*>(etat->getListe().get(i)))[compt]->getX(),etat->getCaseAtteignable(static_cast<Personnage*>(etat->getListe().get(i)))[compt]->getY());
                       } while (dep->getDistance() > paTmp && compt < etat->getCaseAtteignable(static_cast<Personnage*>(etat->getListe().get(i))).size());
                       //moteur->ajouterAction(new Deplacement(static_cast<Personnage*>(etat->getListe().get(i))->getX(),static_cast<Personnage*>(etat->getListe().get(i))->getY(),etat->getCaseAtteignable(static_cast<Personnage*>(etat->getListe().get(i)))[0]->getX(),etat->getCaseAtteignable(static_cast<Personnage*>(etat->getListe().get(i)))[0]->getY()));
                       if (compt < etat->getCaseAtteignable(static_cast<Personnage*>(etat->getListe().get(i))).size())
                       {
                           moteur->ajouterAction(dep);
                           paTmp -= dep->getDistance();
                       }
                       else
                       {
                           std::cout << "Aucun case n'est atteignable" << std::endl;
                           paTmp = -1;
                       }
                       //etat->deplacerElement(static_cast<Personnage*>(etat->getListe().get(i))->getX(),static_cast<Personnage*>(etat->getListe().get(i))->getY(),etat->getCaseAtteignable(static_cast<Personnage*>(etat->getListe().get(i)))[0]->getX(),etat->getCaseAtteignable(static_cast<Personnage*>(etat->getListe().get(i)))[0]->getX());
                   }
                   else
                   {
                       std::cout << "Cas douteux de d'Alembert" << std::endl;
                       paTmp = -1;
                   }
                   moteur->convertirCommande();
                   //scene->afficher();
                   std::cout << "Fin convertir commande" << std::endl;
                   //sleep(2);
                   std::cout << "Fin su sleep" << std::endl;
               }
           }
       }
    }
    std::cout << "Fin de IA appliquer" << std::endl;
}*/