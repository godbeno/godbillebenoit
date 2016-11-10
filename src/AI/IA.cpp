#include "IA.h"


IA (state::Etat* etat, bool equipe)
{
   this->etat = etat;
   this->equipe = equipe;

   for (int i=0;i< etat->getListe().size();i++)
   {
      if (etat->getListe()->get(i)->estPersonnage() && etat->getListe()->get(i)->getEquipe()==bool)
      {
         while ( etat->getListe()->get(i)->getPA() > 0)
         {
            if (getCaseAttaquable(etat->getListe()->get(i)).size() != 0)
            {  
               Attaquer(etat->getListe()->get(i)->getX(),etat->getListe()->get(i)->getY(), getCaseAttaquable(etat->getListe()->get(i))[0]->getX(), getCaseAttaquable(etat->getListe()->get(i))[0]->getY();
	    }
	    {
	       Deplacement(etat->getListe()->get(i)->getX(),etat->getListe()->get(i)->getY(),etat->getListe()->get(i)->getX()+1,etat->getListe()->get(i)->getY()+1);
	    }
         }
      }   
   }
}
 	

