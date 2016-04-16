#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include <cstdlib>
#include <sstream>
#include "include/character/Manager.h"
#include "include/Fps.h"


#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600


Manager managerCharacters;
sf::RenderWindow window;
sf::ContextSettings settings;

int rouge,vert,bleu;
float frame;
Fps mainFps;

int main(){

    settings.antialiasingLevel = 16;
    window.create(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "001", sf::Style::Default, settings);
    window.setFramerateLimit(60);


    rouge = 0; vert = 0; bleu = 0;

    while (window.isOpen()){

        sf::Event event;
        while (window.pollEvent(event)){

            if (event.type == sf::Event::Closed){

                window.close();
            }
        }

        if(!managerCharacters.getContinue()){

            managerCharacters.restart();
        }

        managerCharacters.displays(window);
        managerCharacters.progress(frame);




        frame = mainFps.getFrameTime();
        if(frame > 30){

            frame = 29;
        }


        window.display();
        window.clear(sf::Color(managerCharacters.getRed(),managerCharacters.getGreen(),managerCharacters.getBlue()));
    }

    return 0;
}



