#include "IA.h"
#include "engine.h"
#include "state.h"
#include <iostream>
#include <unistd.h>
#include <algorithm>

using namespace AI;
using namespace engine;
using namespace state;


IA::IA (state::Etat* etat, engine::Moteur* moteur, Niveau niv)
{
   this->etat = etat;
   this->moteur = moteur;
   i = 575;
   niveau = niv;
   attendre = false;
}

bool IA::appliquerHeuristique(bool equipe)
{
    state::Personnage* currentPersonnage = nullptr;
    if (etat->getGrille().get(i)->estPersonnage())
    {
        if(static_cast<Personnage*>(etat->getGrille().get(i))->getEquipe()==equipe)
        {
            currentPersonnage = static_cast<Personnage*>(etat->getGrille().get(i));

            std::cout << "NOUVEAU PERSONNAGE UTILISABLE " << std::endl;
            //etat->setSelectionne(static_cast<Personnage*>(etat->getGrille().get(i))->getX(), static_cast<Personnage*>(etat->getGrille().get(i))->getY());
            if (etat->getSelectionne() == nullptr || etat->getSelectionne() != currentPersonnage)
            {
                moteur->ajouterAction(new Selection(currentPersonnage->getX(), currentPersonnage->getY()));
                moteur->convertirCommande();
                return false;
            }
            std::cout << "PA du perso courant = " << static_cast<Personnage*>(etat->getGrille().get(i))->getPA() << std::endl;
            std::cout << "PA du perso courant = " << etat->getSelectionne()->getPA() << std::endl;
            if (currentPersonnage->getPA() <= 0)
            {
                i++;
                moteur->ajouterAction(new Selection(-1, -1));
                moteur->convertirCommande();
                return false;
            }
            if (currentPersonnage->getPA() > 1 && etat->getCaseAttaquable(currentPersonnage).size() != 0)
            {  
                std::cout << "Il attaque depuis " << etat->getGrille().get(i)->getX() << " , " << etat->getGrille().get(i)->getY() << " vers " << etat->getCaseAttaquable(static_cast<Personnage*>(etat->getGrille().get(i)))[0]->getX() << " , " << etat->getCaseAttaquable(static_cast<Personnage*>(etat->getGrille().get(i)))[0]->getY() << std::endl;
                moteur->ajouterAction(new Attaquer(currentPersonnage->getX(),currentPersonnage->getY(), etat->getCaseAttaquable(currentPersonnage)[0]->getX(), etat->getCaseAttaquable(currentPersonnage)[0]->getY()));
                //etat->attaquer(etat->getGrille().get(i)->getX(),etat->getGrille().get(i)->getY(), etat->getCaseAttaquable(static_cast<Personnage*>(etat->getGrille().get(i)))[0]->getX(), etat->getCaseAttaquable(static_cast<Personnage*>(etat->getGrille().get(i)))[0]->getY());
            } 
            else if (etat->getCaseAtteignable(currentPersonnage).size() != 0)
            {
                state::CaseTerrain* ct = getMeilleureCase(currentPersonnage);
                if (ct != nullptr)
                    moteur->ajouterAction(new Deplacement(currentPersonnage->getX(), currentPersonnage->getY(), ct->getX(), ct->getY()));
                else
                {
                    std::cout << "Auncune case satisfaisante trouvée" << std::endl;
                    i++;
                    moteur->ajouterAction(new Selection(-1, -1));
                    moteur->convertirCommande();
                    return false;
                }
            }
            //moteur->ajouterAction(new Selection(-1, -1));
            moteur->convertirCommande();
            return true;
        }
        else
        {
            i++;
            moteur->ajouterAction(new Selection(-1, -1));
            moteur->convertirCommande();
            return false;
        }
    }
    else
    {
        i++;
        moteur->ajouterAction(new Selection(-1, -1));
        moteur->convertirCommande();
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
    if(i >= this->etat->getListe().size())
    {
        moteur->ajouterAction(new Selection(-1, -1));
        moteur->ajouterAction(new ChangerTour());
        moteur->convertirCommande();
        reset();
        etat->finDuTour();
        return true;
    }
    else
        return false;
}

bool IA::appliquerAleatoire(bool equipe)
{
    if (etat->getGrille().get(i)->estPersonnage())
    {
        if(static_cast<Personnage*>(etat->getGrille().get(i))->getEquipe()==equipe)
        {

            std::cout << "NOUVEAU PERSONNAGE UTILISABLE " << std::endl;
            //etat->setSelectionne(static_cast<Personnage*>(etat->getGrille().get(i))->getX(), static_cast<Personnage*>(etat->getGrille().get(i))->getY());
            if (etat->getSelectionne() == nullptr)
            {
                moteur->ajouterAction(new Selection(etat->getGrille().get(i)->getX(), etat->getGrille().get(i)->getY()));
                moteur->convertirCommande();
                return false;
            }
            std::cout << "PA du perso courant = " << static_cast<Personnage*>(etat->getGrille().get(i))->getPA() << std::endl;
            std::cout << "PA du perso courant = " << etat->getSelectionne()->getPA() << std::endl;
            if (static_cast<Personnage*>(etat->getGrille().get(i))->getPA() <= 0)
            {
                i++;
                moteur->ajouterAction(new Selection(-1, -1));
                moteur->convertirCommande();
                return false;
            }
            if (static_cast<Personnage*>(etat->getGrille().get(i))->getPA() > 1 && etat->getCaseAttaquable(static_cast<Personnage*>(etat->getGrille().get(i))).size() != 0)
            {  
                std::cout << "Il attaque depuis " << etat->getGrille().get(i)->getX() << " , " << etat->getGrille().get(i)->getY() << " vers " << etat->getCaseAttaquable(static_cast<Personnage*>(etat->getGrille().get(i)))[0]->getX() << " , " << etat->getCaseAttaquable(static_cast<Personnage*>(etat->getGrille().get(i)))[0]->getY() << std::endl;
                moteur->ajouterAction(new Attaquer(static_cast<Personnage*>(etat->getGrille().get(i))->getX(),static_cast<Personnage*>(etat->getGrille().get(i))->getY(), etat->getCaseAttaquable(static_cast<Personnage*>(etat->getGrille().get(i)))[0]->getX(), etat->getCaseAttaquable(static_cast<Personnage*>(etat->getGrille().get(i)))[0]->getY()));
                //etat->attaquer(etat->getGrille().get(i)->getX(),etat->getGrille().get(i)->getY(), etat->getCaseAttaquable(static_cast<Personnage*>(etat->getGrille().get(i)))[0]->getX(), etat->getCaseAttaquable(static_cast<Personnage*>(etat->getGrille().get(i)))[0]->getY());
            } 
            else if (etat->getCaseAtteignable(static_cast<Personnage*>(etat->getGrille().get(i))).size() != 0)
            {
                std::cout << "Il se déplace de " << static_cast<Personnage*>(etat->getGrille().get(i))->getX() << " , " << static_cast<Personnage*>(etat->getGrille().get(i))->getY() << " vers " << etat->getCaseAtteignable(static_cast<Personnage*>(etat->getGrille().get(i)))[0]->getX() << " , "<< etat->getCaseAtteignable(static_cast<Personnage*>(etat->getGrille().get(i)))[0]->getY() << std::endl;
                Deplacement* dep;
                int compt = -1;
                {
                    compt++;
                    dep = new Deplacement(static_cast<Personnage*>(etat->getGrille().get(i))->getX(),static_cast<Personnage*>(etat->getGrille().get(i))->getY(),etat->getCaseAtteignable(static_cast<Personnage*>(etat->getGrille().get(i)))[compt]->getX(),etat->getCaseAtteignable(static_cast<Personnage*>(etat->getGrille().get(i)))[compt]->getY());
                } while (dep->getDistance() > static_cast<Personnage*>(etat->getGrille().get(i))->getPA() && static_cast<unsigned int>(compt) < etat->getCaseAtteignable(static_cast<Personnage*>(etat->getGrille().get(i))).size());
                //moteur->ajouterAction(new Deplacement(static_cast<Personnage*>(etat->getGrille().get(i))->getX(),static_cast<Personnage*>(etat->getGrille().get(i))->getY(),etat->getCaseAtteignable(static_cast<Personnage*>(etat->getGrille().get(i)))[0]->getX(),etat->getCaseAtteignable(static_cast<Personnage*>(etat->getGrille().get(i)))[0]->getY()));
                if (static_cast<unsigned int>(compt) < etat->getCaseAtteignable(static_cast<Personnage*>(etat->getGrille().get(i))).size())
                {
                    moteur->ajouterAction(dep);
                }
                    //etat->deplacerElement(static_cast<Personnage*>(etat->getGrille().get(i))->getX(),static_cast<Personnage*>(etat->getGrille().get(i))->getY(),etat->getCaseAtteignable(static_cast<Personnage*>(etat->getGrille().get(i)))[0]->getX(),etat->getCaseAtteignable(static_cast<Personnage*>(etat->getGrille().get(i)))[0]->getX());
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
            moteur->convertirCommande();
            return false;
        }
    }
    else
    {
        i++;
        moteur->ajouterAction(new Selection(-1, -1));
        moteur->convertirCommande();
        return false;
        //std::cout << "PERSONNAGE NON UTILISABLE" << std::endl;
    }
}
void IA::reset()
{
    i = 575;
}
state::CaseTerrain* IA::getMeilleureCase(state::Personnage* p)
{
    std::vector<state::CaseTerrain*> v = etat->getCaseAtteignable(p);
    state::Personnage* ennemi = etat->getPlusProcheEnnemi(p);
    int distMin = 50;
    state::CaseTerrain* ct = nullptr;
    if (abs(p->getX()-ennemi->getX()) + abs(p->getY()-ennemi->getY()) > p->getPorteeMax())
    {
        for (unsigned int i = 0; i < v.size(); i++)
        {
            if (abs(v[i]->getX()-ennemi->getX()) + abs(v[i]->getY()-ennemi->getY()) < distMin
                && abs(v[i]->getX()-ennemi->getX()) + abs(v[i]->getY()-ennemi->getY()) >= p->getPorteeMax())
            {
                distMin = abs(v[i]->getX()-ennemi->getX()) + abs(v[i]->getY()-ennemi->getY());
                ct = v[i];
            }
        }
    }
    else
    {
        for (unsigned int i = 0; i < v.size(); i++)
        {
            if (abs(v[i]->getX()-ennemi->getX()) + abs(v[i]->getY()-ennemi->getY()) < distMin
                && abs(v[i]->getX()-ennemi->getX()) + abs(v[i]->getY()-ennemi->getY()) >= p->getPorteeMin())
            {
                distMin = abs(v[i]->getX()-ennemi->getX()) + abs(v[i]->getY()-ennemi->getY());
                ct = v[i];
            }
        }
    }
    return ct;
}
void IA::jouer()
{
    if (etat->joueurIA() && (!attendre || (attendre && double(clock()-temps)/CLOCKS_PER_SEC > 1)))
    {
        switch(niveau)
        {
            case Aleatoire:
                attendre = appliquerAleatoire(etat->getTour());
                if (attendre)
                    temps = clock();
                break;
            case Heuristique:
                attendre = appliquerHeuristique(etat->getTour());
                if (attendre)
                    temps = clock();
                break;
        }
    }
    estFini();
}