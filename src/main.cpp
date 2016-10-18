#include <iostream>
#include "state/Etat.h"
#include "render/Scene.h"
#include "render/TuileStatique.h"
#include <SFML/Graphics.hpp>

using namespace std;
using namespace state;
using namespace render;
using namespace sf;

int main(int argc,char* argv[]) 
{   
    // Test Unitaire - Etat du jeu 
    RenderWindow *window = new RenderWindow(VideoMode(1600,900,16), "Test Affichage", Style::Fullscreen);
    Etat *etat = new Etat;

    etat->initialiserTerrain(true);
    etat->ajouterPersonnage(true, 2, 3,3);
    
    
    Scene* scene = new Scene(etat, window);
    scene->jouerMusique();
    
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
