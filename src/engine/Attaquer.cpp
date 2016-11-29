#include "Attaquer.h"
#include <iostream>

using namespace engine;


Attaquer::Attaquer (int Attaquantx, int Attaquanty, int Ciblex, int Cibley, bool afficher)
{
   this->attaquantX = Attaquantx;
   this->attaquantY = Attaquanty;
   this->cibleX = Ciblex;
   this->cibleY = Cibley;
   this->afficher = afficher;
}
void Attaquer::appliquer(state::Etat* etat)
{
    degat = etat->getGrille().getCellulePersonnage(cibleX, cibleY)->getPV();
    sauvEquipe = etat->getGrille().getCellulePersonnage(cibleX, cibleY)->getEquipe();
    sauvType = etat->getGrille().getCellulePersonnage(cibleX, cibleY)->getType();
    etat->attaquer(attaquantX, attaquantY, cibleX, cibleY, afficher);
}
state::CaseTerrain* Attaquer::getCaseArrivee(state::Etat* etat)
{
    return etat->getGrille().getCelluleDecor(cibleX, cibleY);
}
void Attaquer::annuler(state::Etat* etat)
{
    /*std::cout << "Attaque[";
    printOrigine();
    printArrivee();
    std::cout << "]->";*/
    etat->getGrille().getCellulePersonnage(attaquantX, attaquantY)->setPArestant(etat->getGrille().getCellulePersonnage(attaquantX, attaquantY)->getPA() + 2);
    if (etat->getGrille().getCellulePersonnage(cibleX, cibleY) == nullptr)  // Si personnage mort on le recréé
    {
        etat->ajouterPersonnage(sauvEquipe, (int)sauvType, cibleX, cibleY, false);
    }        
    etat->getGrille().getCellulePersonnage(cibleX, cibleY)->setPVrestant(degat);
}
void Attaquer::printOrigine()
{
    std::cout << "(" << attaquantX << ", " << attaquantY << ")->";
}
void Attaquer::printArrivee()
{
    std::cout << "(" << cibleX << ", " << cibleY << ")";
}