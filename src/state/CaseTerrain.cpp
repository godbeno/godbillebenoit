#include "CaseTerrain.h"
  
CaseTerrain::CaseTerrain (int id = 0)
{
    /*
     * 0 : herbe
     * 1-6 : riviere
     * 7 : pierre
     * 8-9 : pont
     * 10 : buisson
     * 11-19 : montagne
     * 20-25 : porte
     * 26-35 : remparts
     * 36-39 : escaliers
     * 40-43 : entrées montagne
     */
    this->id = id;
    liste_acces.clear();
    hauteur = 0;
    switch(id)
    {
        case 0: //Herbe
            liste_acces.push_back(Nord);
            liste_acces.push_back(Sud);
            liste_acces.push_back(Est);
            liste_acces.push_back(Ouest);
            hauteur = 0;
            break;
        case 7:
            liste_acces.push_back(Nord);
            liste_acces.push_back(Sud);
            liste_acces.push_back(Est);
            liste_acces.push_back(Ouest);
            hauteur = 0;
            break;
        case 8:
            liste_acces.push_back(Nord);
            liste_acces.push_back(Sud);
            hauteur = 0;
            break;
        case 9:
            liste_acces.push_back(Est);
            liste_acces.push_back(Ouest);
            hauteur = 0;
            break;
        case 10:
            hauteur = 1;
            break;
        case 11:
            liste_acces.push_back(Sud);
            liste_acces.push_back(Est);
            hauteur = 2;
            break;
        case 12:
            liste_acces.push_back(Nord);
            liste_acces.push_back(Est);
            hauteur = 2;
            break;
        case 13:
            liste_acces.push_back(Sud);
            liste_acces.push_back(Ouest);
            hauteur = 2;
            break;
        case 14:
            liste_acces.push_back(Nord);
            liste_acces.push_back(Ouest);
            hauteur = 2;
            break;
        case 15:
            liste_acces.push_back(Sud);
            hauteur = 2;
            break;
        case 16:
            liste_acces.push_back(Est);
            hauteur = 2;
            break;
        case 17:
            liste_acces.push_back(Nord);
            hauteur = 2;
            break;
        case 18:
            liste_acces.push_back(Ouest);
            hauteur = 2;
            break;
        case 19:
            liste_acces.push_back(Sud);
            liste_acces.push_back(Est);
            liste_acces.push_back(Nord);
            liste_acces.push_back(Ouest);
            hauteur = 2;
            break;
        case 20:
            liste_acces.push_back(Est);
            liste_acces.push_back(Ouest);
            hauteur = 2;
            break;
        case 21:
            liste_acces.push_back(Est);
            liste_acces.push_back(Ouest);
            hauteur = 2;
            break;
        case 22:
            liste_acces.push_back(Est);
            liste_acces.push_back(Ouest);
            hauteur = 2;
            break;
        case 23:
            liste_acces.push_back(Nord);
            liste_acces.push_back(Sud);
            hauteur = 2;
            break;
        case 24:
            liste_acces.push_back(Nord);
            liste_acces.push_back(Sud);
            hauteur = 2;
            break;
        case 25:
            liste_acces.push_back(Nord);
            liste_acces.push_back(Sud);
            hauteur = 2;
            break;
        case 26:
            liste_acces.push_back(Nord);
            liste_acces.push_back(Ouest);
            hauteur = 2;
            break;
        case 27:
            liste_acces.push_back(Nord);
            liste_acces.push_back(Est);
            hauteur = 2;
            break;
        case 28:
            liste_acces.push_back(Nord);
            liste_acces.push_back(Sud);
            hauteur = 2;
            break;
        case 29:
            liste_acces.push_back(Est);
            liste_acces.push_back(Ouest);
            hauteur = 2;
            break;
        case 30:
            liste_acces.push_back(Sud);
            liste_acces.push_back(Ouest);
            hauteur = 2;
            break;
        case 31:
            liste_acces.push_back(Sud);
            liste_acces.push_back(Est);
            hauteur = 2;
            break;
        case 32:
            liste_acces.push_back(Sud);
            liste_acces.push_back(Ouest);
            liste_acces.push_back(Est);
            hauteur = 2;
            break;
        case 33:
            liste_acces.push_back(Nord);
            liste_acces.push_back(Ouest);
            liste_acces.push_back(Est);
            hauteur = 2;
            break;
        case 34:
            liste_acces.push_back(Nord);
            liste_acces.push_back(Ouest);
            liste_acces.push_back(Sud);
            hauteur = 2;
            break;
        case 35:
            liste_acces.push_back(Nord);
            liste_acces.push_back(Est);
            liste_acces.push_back(Sud);
            hauteur = 2;
            break;
        case 36:
            liste_acces.push_back(Nord);
            hauteur = 1;
            break;
        case 37:
            liste_acces.push_back(Est);
            hauteur = 1;
            break;
        case 38:
            liste_acces.push_back(Sud);
            hauteur = 1;
            break;
        case 39:
            liste_acces.push_back(Ouest);
            hauteur = 1;
            break;
        case 40:
            liste_acces.push_back(Nord);
            liste_acces.push_back(Sud);
            liste_acces.push_back(Est);
            liste_acces.push_back(Ouest);
            hauteur = 1;
            break;
        case 41:
            liste_acces.push_back(Nord);
            liste_acces.push_back(Sud);
            liste_acces.push_back(Est);
            liste_acces.push_back(Ouest);
            hauteur = 1;
            break;
        case 42:
            liste_acces.push_back(Nord);
            liste_acces.push_back(Sud);
            liste_acces.push_back(Est);
            liste_acces.push_back(Ouest);
            hauteur = 1;
            break;
        case 43:
            liste_acces.push_back(Nord);
            liste_acces.push_back(Sud);
            liste_acces.push_back(Est);
            liste_acces.push_back(Ouest);
            hauteur = 1;
            break;
        default:
            liste_acces.push_back(Nord);
            liste_acces.push_back(Sud);
            liste_acces.push_back(Est);
            liste_acces.push_back(Ouest);
            hauteur = 0;
            break;
    }
}
bool const CaseTerrain::estPersonnage ()
{
    return false;
}
int CaseTerrain::getType ()
{
    return id;
}