#include <SFML/Graphics.hpp>
#include "Score.h"
#include <sstream>


Score::Score()
{
    //ctor
    setScore(0);
}

Score::~Score()
{
    //dtor
}

void Score::afficher(sf::RenderWindow &window){

    sf::Text text;
    sf::Font font;

    if (!font.loadFromFile("arial.ttf")){

        // erreur...
    }

    text.setFont(font);
    text.setPosition(10,600-50);

    // Cast du score (int) en string
    int a = getScore();
    std::stringstream ss;
    ss << a;
    std::string str = ss.str();
    text.setString(str);


    window.draw(text);
}

int Score::getScore(){

    return this->score;
}

void Score::setScore(int score){

    this->score = score;
}
