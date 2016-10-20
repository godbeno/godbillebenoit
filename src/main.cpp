#include <iostream>
#include "state/Etat.h"
#include "render/Scene.h"
#include "render/TuileStatique.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

using namespace std;
using namespace state;
using namespace render;
using namespace sf;

int main(int argc,char* argv[]) 
{   
    
    // Test Unitaire - Etat du jeu 
    RenderWindow *window = new RenderWindow(VideoMode(1366,768,16), "Test Affichage", Style::Fullscreen);
    Etat *etat = new Etat;

    etat->initialiserTerrain(false);
    Scene* scene = new Scene(etat, window);
    etat->enregistrerObservateur(scene);
    etat->ajouterPersonnage(true, 1, 3, 3);
    etat->ajouterPersonnage(true, 2, 4, 4);
    etat->ajouterPersonnage(true, 3, 5, 5);
    etat->ajouterPersonnage(true, 4, 6, 6);

    
    
    

    while (window->isOpen())
    { 
        Event event;
        while (window->pollEvent(event))
        {
            // évènement "fermeture demandée" : on ferme la fenêtre
            if (event.type == Event::Closed)
                window->close();
        }
        scene->afficher();
        
    }
    

    
    delete scene;
    delete window;
    

    return 0;
}
