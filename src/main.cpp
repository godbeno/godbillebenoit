#include <iostream>
#include "state/Etat.h"
#include "render/Scene.h"
#include "render/TuileStatique.h"
#include "engine/Moteur.h"
#include "engine/CommandeClic.h"
#include "engine/Direction.h"
#include "engine/CommandeFleche.h"
#include "engine/CommandeZoomCamera.h"
#include "AI/IA.h"
#include "engine/Regulateur.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <ctime>
#include <unistd.h>
#include <thread>

using namespace std; 
using namespace state;
using namespace render;
using namespace engine;
using namespace sf;
using namespace AI;

int main(int argc,char* argv[]) 
{   
    
    // Test Unitaire - Etat du jeu 
    std::cout << "--------------------INITIALISATION-------------" << std::endl;
    srand(time(NULL));
    RenderWindow *window = new RenderWindow(VideoMode(1366,768,16), "Medieval Minimal War");
    Etat *etat = new Etat;
    Moteur *m = new Moteur(etat);
    IA *ia = new IA(etat,m, Niveau::Heuristique);
    etat->initialiserTerrain(false);
    Scene* scene = new Scene(etat, window);
    etat->enregistrerObservateur(scene);
    
    //Définition de personnage
    //etat->ajouterPersonnage(true, 1, 14, 15);
    etat->ajouterPersonnage(true, 2, 13, 5, true);
    etat->ajouterPersonnage(false, 3, 10, 5, true);
    //etat->ajouterPersonnage(false, 4, 4, 15);    
    etat->ajouterPersonnage(true, 5, 12, 5, true);
    etat->ajouterPersonnage(false, 6, 11, 5, true);
    //etat->ajouterPersonnage(false, 1,10, 15);    
    etat->ajouterPersonnage(true, 2, 16, 5, true);
    etat->ajouterPersonnage(false, 3, 6, 6, true);
    //etat->ajouterPersonnage(false, 4, 5, 16);    
    etat->ajouterPersonnage(true, 5, 15, 7, true);
    etat->ajouterPersonnage(false, 6, 6, 8, true);
    //etat->ajouterPersonnage(false, 1, 5, 12);    
    //etat->ajouterPersonnage(true, 2, 15, 13);
    etat->ajouterPersonnage(false, 3, 6, 11, true);
    //etat->ajouterPersonnage(false, 4, 5, 10, true);
    
    m->setMode(Mode::initialisation);
    
    int largeur = sf::VideoMode::getDesktopMode().width;
    int hauteur = sf::VideoMode::getDesktopMode().height;
    
    //On spécifie que les deux joueurs sont des IAs
    etat->configurerJoueur(false,false);
    etat->changerTour(true);
    
    
    std::cout << std::endl << "--------------------FIN INITIALISATION-------------" << std::endl;
    
    thread th(&Moteur::updateThread, m); 
    
    while (window->isOpen())
    {
        Event event;
        while (window->pollEvent(event))
        {
            // évènement "fermeture demandée" : on ferme la fenêtre
            if (event.type == Event::Closed)
                window->close();
            if (event.type == sf::Event::MouseButtonPressed)
                if (event.mouseButton.button == sf::Mouse::Left)
    /*A+*/      {   if (event.mouseButton.x > 80 && event.mouseButton.x < 110 && event.mouseButton.y > 25 && event.mouseButton.y < 55)
                        m->ajouterCommande(new CommandeClic((int)(event.mouseButton.x/scene->getCoeff())+scene->getCamerax(), (int)(event.mouseButton.y/scene->getCoeff())+scene->getCameray(),17));
    /*A-*/          else if (event.mouseButton.x > 80 && event.mouseButton.x < 110 && event.mouseButton.y > 65 && event.mouseButton.y < 95)
                        m->ajouterCommande(new CommandeClic((int)(event.mouseButton.x/scene->getCoeff())+scene->getCamerax(), (int)(event.mouseButton.y/scene->getCoeff())+scene->getCameray(),-17));
    /*B+*/          else if (event.mouseButton.x > 80 && event.mouseButton.x < 110 && event.mouseButton.y > 145 && event.mouseButton.y < 175)
                        m->ajouterCommande(new CommandeClic((int)(event.mouseButton.x/scene->getCoeff())+scene->getCamerax(), (int)(event.mouseButton.y/scene->getCoeff())+scene->getCameray(),18));
    /*B-*/          else if (event.mouseButton.x > 80 && event.mouseButton.x < 110 && event.mouseButton.y > 185 && event.mouseButton.y < 215)
                        m->ajouterCommande(new CommandeClic((int)(event.mouseButton.x/scene->getCoeff())+scene->getCamerax(), (int)(event.mouseButton.y/scene->getCoeff())+scene->getCameray(),-18));
    /*C+*/          else if (event.mouseButton.x > 80 && event.mouseButton.x < 110 && event.mouseButton.y > 265 && event.mouseButton.y < 295)
                        m->ajouterCommande(new CommandeClic((int)(event.mouseButton.x/scene->getCoeff())+scene->getCamerax(), (int)(event.mouseButton.y/scene->getCoeff())+scene->getCameray(),19));
    /*C-*/          else if (event.mouseButton.x > 80 && event.mouseButton.x < 110 && event.mouseButton.y > 305 && event.mouseButton.y < 335)
                        m->ajouterCommande(new CommandeClic((int)(event.mouseButton.x/scene->getCoeff())+scene->getCamerax(), (int)(event.mouseButton.y/scene->getCoeff())+scene->getCameray(),-19));
    /*D+*/          else if (event.mouseButton.x > 80 && event.mouseButton.x < 110 && event.mouseButton.y > 385 && event.mouseButton.y < 415)
                        m->ajouterCommande(new CommandeClic((int)(event.mouseButton.x/scene->getCoeff())+scene->getCamerax(), (int)(event.mouseButton.y/scene->getCoeff())+scene->getCameray(),20));
    /*D-*/          else if (event.mouseButton.x > 80 && event.mouseButton.x < 110 && event.mouseButton.y > 425 && event.mouseButton.y < 455)
                        m->ajouterCommande(new CommandeClic((int)(event.mouseButton.x/scene->getCoeff())+scene->getCamerax(), (int)(event.mouseButton.y/scene->getCoeff())+scene->getCameray(),-20));
    /*E+*/          else if (event.mouseButton.x > 80 && event.mouseButton.x < 110 && event.mouseButton.y > 505 && event.mouseButton.y < 535)
                        m->ajouterCommande(new CommandeClic((int)(event.mouseButton.x/scene->getCoeff())+scene->getCamerax(), (int)(event.mouseButton.y/scene->getCoeff())+scene->getCameray(),21));
    /*E-*/          else if (event.mouseButton.x > 80 && event.mouseButton.x < 110 && event.mouseButton.y > 545 && event.mouseButton.y < 575)
                        m->ajouterCommande(new CommandeClic((int)(event.mouseButton.x/scene->getCoeff())+scene->getCamerax(), (int)(event.mouseButton.y/scene->getCoeff())+scene->getCameray(),-21));
    /*F+*/          else if (event.mouseButton.x > 80 && event.mouseButton.x < 110 && event.mouseButton.y > 625 && event.mouseButton.y < 655)
                        m->ajouterCommande(new CommandeClic((int)(event.mouseButton.x/scene->getCoeff())+scene->getCamerax(), (int)(event.mouseButton.y/scene->getCoeff())+scene->getCameray(),22));
    /*F-*/          else if (event.mouseButton.x > 80 && event.mouseButton.x < 110 && event.mouseButton.y > 645 && event.mouseButton.y < 675)
                        m->ajouterCommande(new CommandeClic((int)(event.mouseButton.x/scene->getCoeff())+scene->getCamerax(), (int)(event.mouseButton.y/scene->getCoeff())+scene->getCameray(),-22));
                    else if (event.mouseButton.x > largeur/2 -115 && event.mouseButton.x < largeur/2 - 45 && event.mouseButton.y > hauteur-105 && event.mouseButton.y < hauteur-35)
                        m->ajouterCommande(new CommandeClic((int)(event.mouseButton.x/scene->getCoeff())+scene->getCamerax(), (int)(event.mouseButton.y/scene->getCoeff())+scene->getCameray(), 2));
                    else if(event.mouseButton.x > 3*largeur/4+50 && event.mouseButton.y > hauteur-100) 
                        m->ajouterCommande(new CommandeClic(0,0,3));
                    else
                        m->ajouterCommande(new CommandeClic((int)(event.mouseButton.x/scene->getCoeff())+scene->getCamerax(), (int)(event.mouseButton.y/scene->getCoeff())+scene->getCameray(), 0));
                }
            if (event.type == sf::Event::KeyPressed)
            {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
                      m->ajouterCommande(new CommandeFleche(Direction(4)));
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
                      m->ajouterCommande(new CommandeFleche(Direction(3)));
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
                      m->ajouterCommande(new CommandeFleche(Direction(1)));
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
                      m->ajouterCommande(new CommandeFleche(Direction(2)));
            }
            if (event.type == sf::Event::MouseWheelMoved)
                m->ajouterCommande(new CommandeZoomCamera((int)(event.mouseWheel.delta)));
        }
        scene->afficher();
        ia->jouer();
    }
    m->quit();
    th.join();
    delete scene;
    delete window;

    return 0;
}
