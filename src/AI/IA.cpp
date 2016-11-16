#include "IA.h"
#include "engine.h"
#include "state.h"
#include <iostream>
#include <unistd.h>
#include <algorithm>

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
    state::Personnage* currentPersonnage = nullptr;
    if (etat->getGrille().get(i)->estPersonnage())
    {
        if(static_cast<Personnage*>(etat->getGrille().get(i))->getEquipe()==equipe)
        {
            currentPersonnage = static_cast<Personnage*>(etat->getGrille().get(i));

            std::cout << "NOUVEAU PERSONNAGE UTILISABLE " << std::endl;
            //etat->setSelectionne(static_cast<Personnage*>(etat->getGrille().get(i))->getX(), static_cast<Personnage*>(etat->getGrille().get(i))->getY());
            if (etat->getSelectionne() == nullptr)
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
                    i++;
                    moteur->ajouterAction(new Selection(-1, -1));
                    moteur->convertirCommande();
                    return false;
                }
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
 	
IA::~IA()
{
    delete this;
}
bool IA::estFini()
{
    if(i >= this->etat->getListe().size())
    {
        moteur->ajouterAction(new Selection(-1, -1));
        moteur->convertirCommande();
        return true;
    }
    else
        return false;
}
/*
 * IA RANDOM QUI MARCHE
 * bool IA::appliquer(bool equipe)
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
                } while (dep->getDistance() > static_cast<Personnage*>(etat->getGrille().get(i))->getPA() && compt < etat->getCaseAtteignable(static_cast<Personnage*>(etat->getGrille().get(i))).size());
                //moteur->ajouterAction(new Deplacement(static_cast<Personnage*>(etat->getGrille().get(i))->getX(),static_cast<Personnage*>(etat->getGrille().get(i))->getY(),etat->getCaseAtteignable(static_cast<Personnage*>(etat->getGrille().get(i)))[0]->getX(),etat->getCaseAtteignable(static_cast<Personnage*>(etat->getGrille().get(i)))[0]->getY()));
                if (compt < etat->getCaseAtteignable(static_cast<Personnage*>(etat->getGrille().get(i))).size())
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
}*/
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
    for (unsigned int i = 0; i < v.size(); i++)
    {
        if (abs(v[i]->getX()-ennemi->getX()) + abs(v[i]->getY()-ennemi->getY()) < distMin)
        {
            distMin = abs(v[i]->getX()-ennemi->getX()) + abs(v[i]->getY()-ennemi->getY());
            ct = v[i];
        }
    }
    if (abs(ct->getX()-ennemi->getX()) + abs(ct->getY()-ennemi->getY()) < abs(p->getX()-ennemi->getX()) + abs(p->getY()-ennemi->getY()))
        return ct;
    else
        return nullptr;
}
//Brouillon déplacement

/*Personnage* enn = etat->getPlusProcheEnnemi(static_cast<Personnage*>(etat->getGrille().get(i)));
                int dx = enn->getX();
                int dy = enn->getY();
                int px = static_cast<Personnage*>(etat->getGrille().get(i))->getX();
                int py = static_cast<Personnage*>(etat->getGrille().get(i))->getY();
                int bx(0), by(0);
                bx = dx-px;
                by = dy-py;
                if (by != 0)
                    by = (by/abs(by))*(abs(by)-1);
                else
                    bx = (bx/abs(bx))*(abs(bx)-1);
                if (static_cast<Personnage*>(etat->getGrille().get(i))->getPA() < abs(bx))
                {
                    bx = (bx/abs(bx))*static_cast<Personnage*>(etat->getGrille().get(i))->getPA();
                    by = 0;
                }
                else if (static_cast<Personnage*>(etat->getGrille().get(i))->getPA() < abs(bx)+abs(by))
                    by = (by/abs(by))*(static_cast<Personnage*>(etat->getGrille().get(i))->getPA()-abs(bx));
                if (bx != 0 || by != 0)
                {
                    std::vector<state::CaseTerrain*> v = etat->getCaseAtteignable(etat->getSelectionne());
                    state::CaseTerrain* ct = etat->getGrille().getCelluleDecor(px+bx, py+by);
                    while(std::find(v.begin(), v.end(), ct) == v.end())
                    {
                        if (rand()%2 == 0)
                            if (bx != 0)
                                bx = (bx/abs(bx))*(abs(bx)-1);
                        else
                            if (by != 0)
                                by = (by/abs(by))*(abs(by)-1);
                        ct = etat->getGrille().getCelluleDecor(px+bx, py+by);
                        if (bx == 0 && by == 0)
                        {
                            i++;
                            moteur->ajouterAction(new Selection(-1, -1));
                            moteur->convertirCommande();
                            return false;
                        }
                    } 
                    moteur->ajouterAction(new Deplacement(px, py, px+bx, py+by));
                }
                else
                {
                    i++;
                    moteur->ajouterAction(new Selection(-1, -1));
                    moteur->convertirCommande();
                    return false;
                }*/