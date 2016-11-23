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
}

bool IA::appliquerHeuristique(bool equipe)
{
    state::Personnage* currentPersonnage = nullptr;
    std::cout << i << " : " << etat->getGrille().size() << std::endl;
    if (etat->getGrille().get(i)->estPersonnage())
    {
        if(static_cast<Personnage*>(etat->getGrille().get(i))->getEquipe()==equipe)
        {
            currentPersonnage = static_cast<Personnage*>(etat->getGrille().get(i));

            std::cout << "NOUVEAU PERSONNAGE UTILISABLE " << std::endl;
            if (etat->getSelectionne() == nullptr || etat->getSelectionne() != currentPersonnage)
            {
                moteur->ajouterAction(new Selection(currentPersonnage->getX(), currentPersonnage->getY()));
                moteur->convertirCommande(true);
                return false;
            }
            std::cout << "PA du perso courant = " << static_cast<Personnage*>(etat->getGrille().get(i))->getPA() << std::endl;
            //std::cout << "PA du perso courant = " << etat->getSelectionne()->getPA() << std::endl;
            if (currentPersonnage->getPA() <= 0)
            {
                i++;
                moteur->ajouterAction(new Selection(-1, -1));
                moteur->convertirCommande(true);
                return false;
            }
            if (currentPersonnage->getPA() > 1 && etat->getCaseAttaquable(currentPersonnage).size() != 0)
            {  
                std::cout << "IA décide : Il attaque depuis " << etat->getGrille().get(i)->getX() << " , " << etat->getGrille().get(i)->getY() << " vers " << etat->getCaseAttaquable(static_cast<Personnage*>(etat->getGrille().get(i)))[0]->getX() << " , " << etat->getCaseAttaquable(static_cast<Personnage*>(etat->getGrille().get(i)))[0]->getY() << std::endl;
                moteur->ajouterAction(new Attaquer(currentPersonnage->getX(),currentPersonnage->getY(), etat->getCaseAttaquable(currentPersonnage)[0]->getX(), etat->getCaseAttaquable(currentPersonnage)[0]->getY()));
                if (currentPersonnage->getType() == TypePersonnage::Archer)
                    archer = true;
                else
                    archer = false;
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
                    moteur->convertirCommande(true);
                    return true;
                }
            }
            moteur->convertirCommande(true);
            std::cout << "On va retourner true" << std::endl;
            return true;
        }
        else
        {
            i++;
            moteur->ajouterAction(new Selection(-1, -1));
            moteur->convertirCommande(true);
            return false;
        }
    }
    else
    {
        i++;
        moteur->ajouterAction(new Selection(-1, -1));
        moteur->convertirCommande(true);
        return false;
    }
}
 	
IA::~IA()
{
    delete this;
}
bool IA::estFini()
{
    //std::cout << "On vérifie si le tour est fini " << std::endl;
    if(i >= this->etat->getListe().size())
    {
        //std::cout << "Il l'est" << std::endl;
        moteur->ajouterAction(new Selection(-1, -1));
        moteur->ajouterAction(new ChangerTour());
        moteur->convertirCommande(true);
        reset();
        attendre = true;
        return true;
    }
    else
    {
        //std::cout << "Il ne l'est pas" << std::endl;
        return false;
    }
}

bool IA::appliquerAleatoire(bool equipe)
{
    if (etat->getGrille().get(i)->estPersonnage())
    {
        if(static_cast<Personnage*>(etat->getGrille().get(i))->getEquipe()==equipe)
        {

            std::cout << "NOUVEAU PERSONNAGE UTILISABLE " << std::endl;
            if (etat->getSelectionne() == nullptr)
            {
                moteur->ajouterAction(new Selection(etat->getGrille().get(i)->getX(), etat->getGrille().get(i)->getY()));
                moteur->convertirCommande(true);
                return false;
            }
            //std::cout << "PA du perso courant = " << static_cast<Personnage*>(etat->getGrille().get(i))->getPA() << std::endl;
            std::cout << "PA du perso courant = " << etat->getSelectionne()->getPA() << std::endl;
            if (static_cast<Personnage*>(etat->getGrille().get(i))->getPA() <= 0)
            {
                i++;
                moteur->ajouterAction(new Selection(-1, -1));
                moteur->convertirCommande(true);
                return false;
            }
            if (static_cast<Personnage*>(etat->getGrille().get(i))->getPA() > 1 && etat->getCaseAttaquable(static_cast<Personnage*>(etat->getGrille().get(i))).size() != 0)
            {  
                std::cout << "IA décide : Il attaque depuis " << etat->getGrille().get(i)->getX() << " , " << etat->getGrille().get(i)->getY() << " vers " << etat->getCaseAttaquable(static_cast<Personnage*>(etat->getGrille().get(i)))[0]->getX() << " , " << etat->getCaseAttaquable(static_cast<Personnage*>(etat->getGrille().get(i)))[0]->getY() << std::endl;
                moteur->ajouterAction(new Attaquer(static_cast<Personnage*>(etat->getGrille().get(i))->getX(),static_cast<Personnage*>(etat->getGrille().get(i))->getY(), etat->getCaseAttaquable(static_cast<Personnage*>(etat->getGrille().get(i)))[0]->getX(), etat->getCaseAttaquable(static_cast<Personnage*>(etat->getGrille().get(i)))[0]->getY()));
                //etat->attaquer(etat->getGrille().get(i)->getX(),etat->getGrille().get(i)->getY(), etat->getCaseAttaquable(static_cast<Personnage*>(etat->getGrille().get(i)))[0]->getX(), etat->getCaseAttaquable(static_cast<Personnage*>(etat->getGrille().get(i)))[0]->getY());
            } 
            else if (etat->getCaseAtteignable(static_cast<Personnage*>(etat->getGrille().get(i))).size() != 0)
            {
                std::cout << "IA décide : Il se déplace de " << static_cast<Personnage*>(etat->getGrille().get(i))->getX() << " , " << static_cast<Personnage*>(etat->getGrille().get(i))->getY() << " vers " << etat->getCaseAtteignable(static_cast<Personnage*>(etat->getGrille().get(i)))[0]->getX() << " , "<< etat->getCaseAtteignable(static_cast<Personnage*>(etat->getGrille().get(i)))[0]->getY() << std::endl;
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
            moteur->convertirCommande(true);
            return true;
        }
        else
        {
            i++;
            moteur->ajouterAction(new Selection(-1, -1));
            moteur->convertirCommande(true);
            return false;
        }
    }
    else
    {
        i++;
        moteur->ajouterAction(new Selection(-1, -1));
        moteur->convertirCommande(true);
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
    int max = -1, tmp = 0, nbAtt = -1, nbDep = -1;
    state::Personnage* currentPersonnage = nullptr;
    if (etat->getGrille().get(i)->estPersonnage())
    {
        if(static_cast<Personnage*>(etat->getGrille().get(i))->getEquipe()==equipe)
        {
            currentPersonnage = static_cast<Personnage*>(etat->getGrille().get(i));
            if (etat->getSelectionne() == nullptr || etat->getSelectionne() != currentPersonnage)
            {
                moteur->ajouterAction(new Selection(currentPersonnage->getX(), currentPersonnage->getY()));
                moteur->convertirCommande(true);
                return false;
            }
            if (currentPersonnage->getPA() > 0)
            {
                moteur->commencerEnregistrement();
                std::vector<CaseTerrain*> va = etat->getCaseAttaquable(currentPersonnage);
                for (unsigned int j = 0; j < va.size(); j++)
                {
                    moteur->ajouterAction(new Attaquer(currentPersonnage->getX(),currentPersonnage->getY(), va[j]->getX(), va[j]->getY()));
                    tmp = minmax(2);
                    if (tmp > max)
                    {
                        max = tmp;
                        nbAtt = j;
                    }
                    moteur->annuler();
                }
                std::vector<CaseTerrain*> vd = etat->getCaseAtteignable(currentPersonnage);
                for (unsigned int j = 0; j < vd.size(); j++)
                {
                    moteur->ajouterAction(new Deplacement(currentPersonnage->getX(),currentPersonnage->getY(), va[j]->getX(), va[j]->getY()));
                    tmp = minmax(2);
                    if (tmp > max)
                    {
                        max = tmp;
                        nbAtt = -1;
                        nbDep = j;
                    }
                    moteur->annuler();
                }
                if (nbAtt != -1)
                    moteur->ajouterAction(new Attaquer(currentPersonnage->getX(),currentPersonnage->getY(), va[tmp]->getX(), va[tmp]->getY()));
                else if (nbDep != -1)
                    moteur->ajouterAction(new Deplacement(currentPersonnage->getX(),currentPersonnage->getY(), va[tmp]->getX(), va[tmp]->getY()));
            }
            else
            {
                i++;
                moteur->ajouterAction(new Selection(-1, -1));
                moteur->convertirCommande(true);
                return false;
            }
        }
    }
    return false;
}
        
int IA::minmax(int prof)
{
    //Pour l'instant ne marche que pour le max
    int tmp = -1, nbAtt = -1, nbDep = -1, max  = -1; 
    state::Personnage* currentPersonnage = nullptr;
    int j = 0;
    while (j < etat->getGrille().size())
    {
        if (etat->getGrille().get(j)->estPersonnage())
        {
            if(static_cast<Personnage*>(etat->getGrille().get(j))->getEquipe()==equipe)
            {
                currentPersonnage = static_cast<Personnage*>(etat->getGrille().get(j));
                if (etat->getSelectionne() == nullptr || etat->getSelectionne() != currentPersonnage)
                {
                    moteur->ajouterAction(new Selection(currentPersonnage->getX(), currentPersonnage->getY()));
                    moteur->convertirCommande(false);
                }
                if (currentPersonnage->getPA() > 0)
                {
                    std::vector<CaseTerrain*> va = etat->getCaseAttaquable(currentPersonnage);
                    std::vector<CaseTerrain*> vd = etat->getCaseAtteignable(currentPersonnage);
                    for (unsigned int k = 0; k < va.size(); k++)
                    {
                        moteur->ajouterAction(new Attaquer(currentPersonnage->getX(),currentPersonnage->getY(), va[k]->getX(), va[k]->getY()));
                        moteur->convertirCommande(false);
                        tmp = minmax(prof--);
                        if (tmp > max)
                        {
                            max = tmp;
                            nbAtt = k;
                        }
                        moteur->annuler();
                    }
                    for (unsigned int k = 0; k < vd.size(); k++)
                    {
                        moteur->ajouterAction(new Deplacement(currentPersonnage->getX(),currentPersonnage->getY(), va[k]->getX(), va[k]->getY()));
                        tmp = minmax(prof--);
                        if (tmp > max)
                        {
                            max = tmp;
                            nbAtt = -1;
                            nbDep = k;
                        }
                        moteur->annuler();
                    }
                    if (nbAtt != -1)
                        moteur->ajouterAction(new Attaquer(currentPersonnage->getX(),currentPersonnage->getY(), va[tmp]->getX(), va[tmp]->getY()));
                    else if (nbDep != -1)
                        moteur->ajouterAction(new Deplacement(currentPersonnage->getX(),currentPersonnage->getY(), va[tmp]->getX(), va[tmp]->getY()));
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
}