#include "IA.h"
#include "engine.h"
#include "state.h"

using namespace AI;
using namespace engine;
using namespace state;


IA::IA (state::Etat* etat)
{
   this->etat = etat;
}

void IA::appliquer(bool equipe)
{
   for (int i=0;i< this->etat->getListe().size();i++)
   {   
       if (etat->getListe().get(i)->estPersonnage())
       {
           if(static_cast<Personnage*>(etat->getListe().get(i))->getEquipe()==equipe)
           {
               while (static_cast<Personnage*>(etat->getListe().get(i))->getPA() > 0)
               {
                   if (etat->getCaseAttaquable(static_cast<Personnage*>(etat->getListe().get(i))).size() != 0)
                   {  
                       engine::Attaquer(etat->getListe().get(i)->getX(),etat->getListe().get(i)->getY(), etat->getCaseAttaquable(static_cast<Personnage*>(etat->getListe().get(i)))[0]->getX(), etat->getCaseAttaquable(static_cast<Personnage*>(etat->getListe().get(i)))[0]->getY());
                   }
                   {
                       engine::Deplacement(static_cast<Personnage*>(etat->getListe().get(i))->getX(),static_cast<Personnage*>(etat->getListe().get(i))->getY(),static_cast<Personnage*>(etat->getListe().get(i))->getX()+1,static_cast<Personnage*>(etat->getListe().get(i))->getY()+1);
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
