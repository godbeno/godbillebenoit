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
        }
        scene->afficher();
        m->update(clock());
        
    }
    

    
    delete scene;
    delete window;
    

    return 0;
}
