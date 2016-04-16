#include <SFML/Graphics.hpp>
#include "Item.h"

Item::Item()
{
    //ctor
    init();
}

Item::~Item()
{
    //dtor
}

void Item::init(){

    setX(400);
    setY(50);
    setDimension(5);

    circItem.setPosition(sf::Vector2f(getX(), getY()));
    circItem.setOutlineThickness(4);
    circItem.setOutlineColor(sf::Color::Blue);
    circItem.setRadius(getDimension());//.setSize(sf::Vector2f(50,50));
    circItem.setFillColor(sf::Color::Blue);

}

void Item::coordinateGenerator(){

    srand(time(0));
    aleaWidth = (rand() % 700) + 1;
    aleaHeight = (rand() % 500) + 1;

    setX(aleaWidth);
    setY(aleaHeight);
}

void Item::display(sf::RenderWindow &window){

    window.draw(circItem);
}

void Item::setX(int x){

    this->x = x;
    circItem.setPosition(sf::Vector2f(getX(), getY()));
}

void Item::setY(int y){

    this->y = y;
    circItem.setPosition(sf::Vector2f(getX(), getY()));
}

int Item::getX() const{

    return this->x;
}

int Item::getY() const{

    return this->y;
}

int Item::getDimension() const{

    return this->dimension;
}

void Item::setDimension(int dimension){

    this->dimension = dimension;
}
