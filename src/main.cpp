#include <iostream>
#include "state/Etat.h"
#include "render/Scene.h"
#include "render/TuileStatique.h"
#include "engine/Moteur.h"
#include "engine/CommandeClic.h"
#include "engine/Direction.h"
#include "engine/CommandeFleche.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

using namespace std;
using namespace state;
using namespace render;
using namespace engine;
using namespace sf;

int main(int argc,char* argv[]) 
{   
    
    // Test Unitaire - Etat du jeu 
    RenderWindow *window = new RenderWindow(VideoMode(1366,768,16), "Test Affichage", Style::Fullscreen);
    Etat *etat = new Etat;
    Moteur *m = new Moteur(etat);

    etat->initialiserTerrain(true);
    Scene* scene = new Scene(etat, window);
    etat->enregistrerObservateur(scene);
    etat->ajouterPersonnage(true, 5, 10, 10);
    etat->ajouterPersonnage(true, 3, 12, 10);
    etat->ajouterPersonnage(true, 4, 10, 8);
    etat->ajouterPersonnage(true, 2, 8, 8);   
    etat->ajouterPersonnage(true, 1, 6, 8);
    etat->ajouterPersonnage(false, 6, 10, 6);
    etat->setSelectionne(12,10);
    m->setMode(Mode::jeu);
    
    std::cout << " COEFFICIENT : " << scene->getCoeff() << std::endl;
    
    

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
                {
                    m->ajouterCommande(new CommandeClic((int)(event.mouseButton.x/scene->getCoeff())+scene->getCamerax(), (int)(event.mouseButton.y/scene->getCoeff())+scene->getCameray()));
                    std::cout << "commande x : " << (int)(event.mouseButton.x/scene->getCoeff())+scene->getCamerax() << std::endl;
                    std::cout << "commande y : " << (int)(event.mouseButton.y/scene->getCoeff())+scene->getCameray() << std::endl;
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
        }
        scene->afficher();
        m->update(clock());
        
    }
    

    
    delete scene;
    delete window;
    

    return 0;
}
