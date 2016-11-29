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
    archer = false;
    iAtt = 0;
    iDep = 0;
    amax = -10000;
    nbAtt = -1;
    nbDep = -1;
}

bool IA::appliquerHeuristique(bool equipe)
{
    state::Personnage* currentPersonnage = nullptr;
    if (etat->getGrille().get(i)->estPersonnage())
    {
        if(static_cast<Personnage*>(etat->getGrille().get(i))->getEquipe()==equipe)
        {
            currentPersonnage = static_cast<Personnage*>(etat->getGrille().get(i));
            if (etat->getSelectionne() == nullptr || etat->getSelectionne() != currentPersonnage)
            {
                moteur->ajouterAction(new Selection(currentPersonnage->getX(), currentPersonnage->getY(), true));
                //std::cout << "IA->";
                //moteur->convertirCommande(true);
                return false;
            }
            if (currentPersonnage->getPA() <= 0)
            {
                i++;
                moteur->ajouterAction(new Selection(-1, -1, true));
                //std::cout << "IA->";
                //moteur->convertirCommande(true);
                return false;
            }
            if (currentPersonnage->getPA() > 1 && etat->getCaseAttaquable(currentPersonnage).size() != 0)
            {  
                moteur->ajouterAction(new Attaquer(currentPersonnage->getX(),currentPersonnage->getY(), etat->getCaseAttaquable(currentPersonnage)[0]->getX(), etat->getCaseAttaquable(currentPersonnage)[0]->getY(), true));
                if (currentPersonnage->getType() == TypePersonnage::Archer)
                    archer = true;
                else
                    archer = false;
            } 
            else if (etat->getCaseAtteignable(currentPersonnage).size() != 0)
            {
                state::CaseTerrain* ct = getMeilleureCase(currentPersonnage);
                if (ct != nullptr)
                    moteur->ajouterAction(new Deplacement(currentPersonnage->getX(), currentPersonnage->getY(), ct->getX(), ct->getY(), true));
                else
                {
                    i++;
                    moteur->ajouterAction(new Selection(-1, -1, true));
                    std::cout << "IA->";
                    //moteur->convertirCommande(true);
                    return true;
                }
            }
            //std::cout << "IA->";
            //moteur->convertirCommande(true);
            return true;
        }
        else
        {
            i++;
            moteur->ajouterAction(new Selection(-1, -1, true));
            //std::cout << "IA->";
            //moteur->convertirCommande(true);
            return false;
        }
    }
    else
    {
        i++;
        moteur->ajouterAction(new Selection(-1, -1, true));
        //std::cout << "IA->";
        //moteur->convertirCommande(true);
        return false;
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
        moteur->ajouterAction(new ChangerMode(3,0,0,moteur, true));
        moteur->ajouterAction(new ChangerTour(true));
        //moteur->convertirCommande(true);
        reset();
        attendre = true;
        return true;
    }
    else
    {
        return false;
    }
}

bool IA::appliquerAleatoire(bool equipe)
{
    if (etat->getGrille().get(i)->estPersonnage())
    {
        if(static_cast<Personnage*>(etat->getGrille().get(i))->getEquipe()==equipe)
        {

            if (etat->getSelectionne() == nullptr)
            {
                moteur->ajouterAction(new Selection(etat->getGrille().get(i)->getX(), etat->getGrille().get(i)->getY(), true));
                std::cout << "IA->";
                //moteur->convertirCommande(true);
                return false;
            }
            if (static_cast<Personnage*>(etat->getGrille().get(i))->getPA() <= 0)
            {
                i++;
                moteur->ajouterAction(new Selection(-1, -1, true));
                std::cout << "IA->";
                //moteur->convertirCommande(true);
                return false;
            }
            if (static_cast<Personnage*>(etat->getGrille().get(i))->getPA() > 1 && etat->getCaseAttaquable(static_cast<Personnage*>(etat->getGrille().get(i))).size() != 0)
            {  
                moteur->ajouterAction(new Attaquer(static_cast<Personnage*>(etat->getGrille().get(i))->getX(),static_cast<Personnage*>(etat->getGrille().get(i))->getY(), etat->getCaseAttaquable(static_cast<Personnage*>(etat->getGrille().get(i)))[0]->getX(), etat->getCaseAttaquable(static_cast<Personnage*>(etat->getGrille().get(i)))[0]->getY(), true));
                if (static_cast<Personnage*>(etat->getGrille().get(i))->getType() == TypePersonnage::Archer)
                    archer = true;
                else
                    archer = false;
            } 
            else if (etat->getCaseAtteignable(static_cast<Personnage*>(etat->getGrille().get(i))).size() != 0)
            {
                Deplacement* dep;
                int compt = -1;
                {
                    compt++;
                    dep = new Deplacement(static_cast<Personnage*>(etat->getGrille().get(i))->getX(),static_cast<Personnage*>(etat->getGrille().get(i))->getY(),etat->getCaseAtteignable(static_cast<Personnage*>(etat->getGrille().get(i)))[compt]->getX(),etat->getCaseAtteignable(static_cast<Personnage*>(etat->getGrille().get(i)))[compt]->getY(), true);
                } while (dep->getDistance() > static_cast<Personnage*>(etat->getGrille().get(i))->getPA() && static_cast<unsigned int>(compt) < etat->getCaseAtteignable(static_cast<Personnage*>(etat->getGrille().get(i))).size());
                if (static_cast<unsigned int>(compt) < etat->getCaseAtteignable(static_cast<Personnage*>(etat->getGrille().get(i))).size())
                {
                    moteur->ajouterAction(dep);
                }
            }
            //std::cout << "IA->";
            //moteur->convertirCommande(true);
            return true;
        }
        else
        {
            i++;
            moteur->ajouterAction(new Selection(-1, -1, true));
            //std::cout << "IA->";
            //moteur->convertirCommande(true);
            return false;
        }
    }
    else
    {
        i++;
        moteur->ajouterAction(new Selection(-1, -1, true));
        std::cout << "IA->";
        //moteur->convertirCommande(true);
        return false;
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
    int paUt = 100;
    state::CaseTerrain* ct = nullptr;
    if (abs(p->getX()-ennemi->getX()) + abs(p->getY()-ennemi->getY()) > p->getPorteeMax())
    {
        for (unsigned int i = 0; i < v.size(); i++)
        {
            if (abs(v[i]->getX()-ennemi->getX()) + abs(v[i]->getY()-ennemi->getY()) <= distMin
                && abs(v[i]->getX()-ennemi->getX()) + abs(v[i]->getY()-ennemi->getY()) >= p->getPorteeMax())
            {
                if (abs(v[i]->getX()-ennemi->getX()) + abs(v[i]->getY()-ennemi->getY()) == distMin)
                {
                    if (abs(v[i]->getX()-p->getX()) + abs(v[i]->getY()-p->getY())< paUt)
                    {
                        distMin = abs(v[i]->getX()-ennemi->getX()) + abs(v[i]->getY()-ennemi->getY());
                        ct = v[i];
                        paUt = abs(v[i]->getX()-p->getX()) + abs(v[i]->getY()-p->getY());
                    }
                }
                else
                {
                    distMin = abs(v[i]->getX()-ennemi->getX()) + abs(v[i]->getY()-ennemi->getY());
                    ct = v[i];
                    paUt = abs(v[i]->getX()-p->getX()) + abs(v[i]->getY()-p->getY());
                }
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
                if (abs(v[i]->getX()-ennemi->getX()) + abs(v[i]->getY()-ennemi->getY()) == distMin)
                {
                    if (abs(v[i]->getX()-p->getX()) + abs(v[i]->getY()-p->getY())< paUt)
                    {
                        distMin = abs(v[i]->getX()-ennemi->getX()) + abs(v[i]->getY()-ennemi->getY());
                        ct = v[i];
                        paUt = abs(v[i]->getX()-p->getX()) + abs(v[i]->getY()-p->getY());
                    }
                }
                else
                {
                    distMin = abs(v[i]->getX()-ennemi->getX()) + abs(v[i]->getY()-ennemi->getY());
                    ct = v[i];
                    paUt = abs(v[i]->getX()-p->getX()) + abs(v[i]->getY()-p->getY());
                }
            }
        }
    }
    return ct;
}
void IA::jouer()
{
    if (!etat->partieContinue() && etat->joueurIA() && (!attendre || (attendre && double(clock()-temps)/CLOCKS_PER_SEC > 0.5*(archer+1))))
    {
        //std::cout << "On va jouer à nouveau ! " << std::endl;
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
            case MinMax:
                attendre = appliquerMinMax();
                if (attendre)
                    temps = clock();
                break;
        }
    }
    estFini();
}

bool IA::appliquerMinMax()
{
    int tmp = 0;
    state::Personnage* currentPersonnage = nullptr;
    if (etat->getGrille().get(i)->estPersonnage())
    {
        if(static_cast<Personnage*>(etat->getGrille().get(i))->getEquipe()==etat->getTour())
        {
            currentPersonnage = static_cast<Personnage*>(etat->getGrille().get(i));
            if (etat->getSelectionne() == nullptr || etat->getSelectionne() != currentPersonnage)
            {
                moteur->ajouterAction(new Selection(currentPersonnage->getX(), currentPersonnage->getY(), true));
                std::cout << "IA->";
                //moteur->convertirCommande(true);
                return false;
            }
            if (currentPersonnage->getPA() > 0)
            {
                moteur->commencerEnregistrement();
                std::vector<CaseTerrain*> va = etat->getCaseAttaquable(currentPersonnage);
                std::cout << "DEBUT DU CALCUL POUR UN JOUEUR(ATTAQUE)(" << i << ")" << std::endl;
                //for (unsigned int j = 0; j < va.size(); j++)
                //{
                if (iAtt < va.size())
                {
                    moteur->ajouterAction(new Attaquer(currentPersonnage->getX(),currentPersonnage->getY(), va[iAtt]->getX(), va[iAtt]->getY(), false));
                    std::cout << "IA->";
                    //moteur->convertirCommande(false);
                    tmp = minmax(1);
                    if (tmp > amax)
                    { 
                        amax = tmp;
                        nbAtt = iAtt;
                    }
                    std::cout << "[Annulation]IA->";
                    moteur->annuler();
                    iAtt++;
                    return false;
                }
                //}
                std::vector<CaseTerrain*> vd = etat->getCaseAtteignable(currentPersonnage);
                std::cout << "DEBUT DU CALCUL POUR UN JOUEUR(DEPLACEMENT)(" << i << ")" << std::endl;
                //for (unsigned int j = 0; j < vd.size(); j++)
                //{
                if (iDep < vd.size())
                {
                    std::cout << "DEBUT DU CALCUL POUR LE DEPLACEMENT " << iDep << "/" << vd.size() << "  (" << i << ") " << std::endl;
                    moteur->ajouterAction(new Deplacement(currentPersonnage->getX(),currentPersonnage->getY(), vd[iDep]->getX(), vd[iDep]->getY(), false));
                    //std::cout << "IA->";
                    //moteur->convertirCommande(false);
                    tmp = minmax(1);
                    if (tmp > amax)
                    {
                        amax = tmp;
                        nbAtt = -1;
                        nbDep = iDep;
                    }
                    //std::cout << "[Annulation]IA->";
                    iDep++;
                    moteur->annuler();
                    return false;
                }
                //}
                std::cout << "FIN DU CALCUL POUR UN JOUEUR: DECISION" << std::endl;
                if (nbAtt != -1)
                    moteur->ajouterAction(new Attaquer(currentPersonnage->getX(),currentPersonnage->getY(), va[nbAtt]->getX(), va[nbAtt]->getY(), true));
                else if (nbDep != -1)
                    moteur->ajouterAction(new Deplacement(currentPersonnage->getX(),currentPersonnage->getY(), vd[nbDep]->getX(), vd[nbDep]->getY(), true));
                std::cout << "IA->";
                iAtt = 0;
                iDep = 0;
                amax = -10000;
                nbAtt = -1;
                nbDep = -1;
                //moteur->convertirCommande(true);
                return true;
            }
            else
            {
                i++;
                moteur->ajouterAction(new Selection(-1, -1, true));
                std::cout << "IA->";
                //moteur->convertirCommande(true);
                return false;
            }
        }
        else
            i++;
    }
    else
        i++;
    return false;
}
        
int IA::minmax(int prof)
{
    //Pour l'instant ne marche que pour le max
    int tmp = -1, max  = -1000000; 
    state::Personnage* currentPersonnage = nullptr;
    int j = 575;
    if (prof <= 0)
    {
        return fonctionEvaluation(etat);
    }
    while (j < etat->getGrille().size())
    {
        //std::cout << j << " : " << etat->getGrille().size() << std::endl;
        if (etat->getGrille().get(j)->estPersonnage())
        {
            if(static_cast<Personnage*>(etat->getGrille().get(j))->getEquipe()==etat->getTour())
            {
                currentPersonnage = static_cast<Personnage*>(etat->getGrille().get(j));
                if (etat->getSelectionne() == nullptr || etat->getSelectionne() != currentPersonnage)
                {
                    moteur->ajouterAction(new Selection(currentPersonnage->getX(), currentPersonnage->getY(), false));
                    //std::cout << "IA->";
                    //moteur->convertirCommande(false);
                }
                if (currentPersonnage->getPA() > 0)
                {
                    std::vector<CaseTerrain*> va = etat->getCaseAttaquable(currentPersonnage);
                    std::vector<CaseTerrain*> vd = etat->getCaseAtteignable(currentPersonnage); 
                    //std::cout << std::endl << "Bloc simulation attaque sous-fils " << j << " (" << va.size() << ")" << std::endl;
                    for (unsigned int k = 0; k < va.size(); k++)
                    {
                        moteur->ajouterAction(new Attaquer(currentPersonnage->getX(),currentPersonnage->getY(), va[k]->getX(), va[k]->getY(), false));
                        //std::cout << "IA->" << std::endl;
                        //moteur->convertirCommande(false);
                        tmp = minmax(prof-1);
                        if (tmp > max)
                        {
                            max = tmp;
                        }
                        //std::cout << "[Annulation]IA->" << std::endl;
                        moteur->annuler();
                    }
                    //std::cout << "Bloc simulation déplacement sous-fils " << j << " (" << vd.size() << ")" << std::endl;
                    for (unsigned int k = 0; k < vd.size(); k++)
                    {
                        moteur->ajouterAction(new Deplacement(currentPersonnage->getX(),currentPersonnage->getY(), vd[k]->getX(), vd[k]->getY(), false));
                        //std::cout << "IA->";
                        //moteur->convertirCommande(false);
                        //std::cout << "Simulation du déplacement du personnage " << j << " coup " << k << " prof " << prof << std::endl;
                        tmp = minmax(prof-1);
                        if (tmp > max)
                        {
                            max = tmp;
                        }
                        //std::cout << "[Annulation]IA->";
                        moteur->annuler();                        
                        //std::cout << "Fin de Simulation du déplacement du personnage " << j << " coup " << k << " prof " << prof << std::endl;
                    }
                    j++;
                }
                else
                {
                    j++;
                }
            }
            else
                j++;
        }
        else
            j++;
    }
    //std::cout << "ON A TROUVE LA VALEUR : " << max << std::endl;
    return max;
}
int IA::fonctionEvaluation(state::Etat* etat)
{
    int eval = 0;
    int pv = 0;
    int coeff;
    //Evaluation des forces en présences (nbPersonnages + nbPV);
    for (int k = 575; k < etat->getGrille().size(); k++)
    {
        if (etat->getGrille().get(k)->estPersonnage())
        {
            coeff = (static_cast<Personnage*>(etat->getGrille().get(k))->getEquipe() == etat->getTour());
            coeff = (!coeff)*(-1) + coeff;
            eval += coeff*500;
            pv += coeff*static_cast<Personnage*>(etat->getGrille().get(k))->getPV();
        }
    }
    return pv+eval;
    //Evaluation des positions
}