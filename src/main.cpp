#include <iostream>
#include "state/Etat.h"
#include "render/Scene.h"
#include "render/TuileStatique.h"
#include "engine/Moteur.h"
#include "engine/CommandeClic.h"
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
    m->setMode(Mode::deplacement);

    etat->initialiserTerrain(true);
    Scene* scene = new Scene(etat, window);
    etat->enregistrerObservateur(scene);
    etat->ajouterPersonnage(true, 5, 10, 10);
    etat->ajouterPersonnage(true, 3, 12, 10);
    etat->ajouterPersonnage(true, 4, 10, 8);
    etat->ajouterPersonnage(true, 2, 8, 8);   
    etat->ajouterPersonnage(true, 1, 6, 8);
    etat->ajouterPersonnage(true, 0, 10, 12);
    etat->setSelectionne(12,10);
    
    

    while (window->isOpen())
    { 
        Event event;
        while (window->pollEvent(event))
        {
            // évènement "fermeture demandée" : on ferme la fenêtre
            if (event.type == Event::Closed)
                window->close();
            if (event.mouseButton.button == sf::Mouse::Left)
            {
                m->ajouterCommande(new CommandeClic(event.mouseButton.x, event.mouseButton.y));
            }
            if (event.type == sf::Event::KeyPressed)
            {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            {
                              m->ajouterCommande(new CommandeFleche(4);
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            {
                              m->ajouterCommande(new CommandeFleche(3);
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
                              m->ajouterCommande(new CommandeFleche(1);
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
                              m->ajouterCommande(new CommandeFleche(2);
            
        }
        scene->afficher();
        m->update(clock());
        
    }
    

    
    delete scene;
    delete window;
    

    return 0;
}
