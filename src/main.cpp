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

using namespace std; 
using namespace state;
using namespace render;
using namespace engine;
using namespace sf;
using namespace AI;

int main(int argc,char* argv[]) 
{   
    
    // Test Unitaire - Etat du jeu 
    srand(time(NULL));
    RenderWindow *window = new RenderWindow(VideoMode(1366,768,16), "Test Affichage");
    Etat *etat = new Etat;
    Moteur *m = new Moteur(etat);
    IA *ia = new IA(etat,m);

    etat->initialiserTerrain(true);
    Scene* scene = new Scene(etat, window);
    etat->enregistrerObservateur(scene);
    etat->ajouterPersonnage(true, 5, 10, 10);
    etat->ajouterPersonnage(true, 3, 12, 10);
    etat->ajouterPersonnage(true, 4, 10, 8);
    etat->ajouterPersonnage(true, 2, 8, 8);   
    etat->ajouterPersonnage(false, 1, 6, 8);
    etat->ajouterPersonnage(false, 6, 10, 6);
    etat->setSelectionne(12,10);
    m->setMode(Mode::jeu);
    
    std::cout << " COEFFICIENT : " << scene->getCoeff() << std::endl;
    int largeur = sf::VideoMode::getDesktopMode().width;
    int hauteur = sf::VideoMode::getDesktopMode().height;
    bool monTour = true;
    
    

    while (window->isOpen())
    { 
        Event event;
        while (window->pollEvent(event))
        {
            // évènement "fermeture demandée" : on ferme la fenêtre
            if (event.type == Event::Closed)
                window->close();
            if (event.type == sf::Event::MouseButtonPressed && monTour)
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    if (event.mouseButton.x > largeur/2 -185 && event.mouseButton.x < largeur/2 - 115 && event.mouseButton.y > hauteur-105 && event.mouseButton.y < hauteur-35)
                        m->ajouterCommande(new CommandeClic((int)(event.mouseButton.x/scene->getCoeff())+scene->getCamerax(), (int)(event.mouseButton.y/scene->getCoeff())+scene->getCameray(), 1));
                    else if (event.mouseButton.x > largeur/2 -115 && event.mouseButton.x < largeur/2 - 45 && event.mouseButton.y > hauteur-105 && event.mouseButton.y < hauteur-35)
                        
                        m->ajouterCommande(new CommandeClic((int)(event.mouseButton.x/scene->getCoeff())+scene->getCamerax(), (int)(event.mouseButton.y/scene->getCoeff())+scene->getCameray(), 2));
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
        m->update(clock());
        
    }
    

    
    delete scene;
    delete window;
    

    return 0;
}
