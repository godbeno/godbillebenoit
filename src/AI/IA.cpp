#include "IA.h"
#include "engine.h"
#include "state.h"
#include <iostream>
#include <unistd.h>

using namespace AI;
using namespace engine;
using namespace state;


IA::IA (state::Etat* etat)
{
   this->etat = etat;
}

void IA::appliquer(bool equipe)
{
    std::cout << "Etonnant !" << std::endl;
   for (int i=0;i< this->etat->getListe().size();i++)
   {           
       if (etat->getListe().get(i)->estPersonnage())
       {
           if(static_cast<Personnage*>(etat->getListe().get(i))->getEquipe()==equipe)
           {
               
               while (static_cast<Personnage*>(etat->getListe().get(i))->getPA() > 0)
               {        
                   std::cout << "PA du perso courant = " << static_cast<Personnage*>(etat->getListe().get(i))->getPA() << std::endl;
                   if (etat->getCaseAttaquable(static_cast<Personnage*>(etat->getListe().get(i))).size() != 0)
                   {  std::cout << "Il attaque depuis " << etat->getListe().get(i)->getX() << " , " << etat->getListe().get(i)->getY() << " vers " << etat->getCaseAttaquable(static_cast<Personnage*>(etat->getListe().get(i)))[0]->getX() << " , " << etat->getCaseAttaquable(static_cast<Personnage*>(etat->getListe().get(i)))[0]->getX() << std::endl;
                       etat->attaquer(etat->getListe().get(i)->getX(),etat->getListe().get(i)->getY(), etat->getCaseAttaquable(static_cast<Personnage*>(etat->getListe().get(i)))[0]->getX(), etat->getCaseAttaquable(static_cast<Personnage*>(etat->getListe().get(i)))[0]->getY());
                   }        
                   { std::cout << "Il se déplace de " << static_cast<Personnage*>(etat->getListe().get(i))->getX() << " , " << static_cast<Personnage*>(etat->getListe().get(i))->getY() << " vers " << etat->getCaseAtteignable(static_cast<Personnage*>(etat->getListe().get(i)))[0]->getX() << " , "<< etat->getCaseAtteignable(static_cast<Personnage*>(etat->getListe().get(i)))[0]->getX() << std::endl;
                       etat->deplacerElement(static_cast<Personnage*>(etat->getListe().get(i))->getX(),static_cast<Personnage*>(etat->getListe().get(i))->getY(),etat->getCaseAtteignable(static_cast<Personnage*>(etat->getListe().get(i)))[0]->getX(),etat->getCaseAtteignable(static_cast<Personnage*>(etat->getListe().get(i)))[0]->getX());
                   }
               }
           }
       }
    }
}
 	
IA::~IA()
{
    delete this;
}
