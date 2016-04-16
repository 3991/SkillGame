#include <SFML/Graphics.hpp>
#include "../../include/character/Mob.h"
#include <ctime>
#include <iostream>
#include <cstdlib>


Mob::Mob()
{
    //ctor
    init();
}

Mob::~Mob()
{
    //dtor
}

void Mob::init(){

    setSpeed(0.5f);
    srand(time(0));
    aleaWidth = (rand() % 700) + 1;
    aleaHeight = (rand() % 500) + 1;

    setX(aleaWidth);
    setY(aleaHeight);

    rect_mob.setPosition(sf::Vector2f(getX(), getY()));
    rect_mob.setOutlineThickness(4);
    rect_mob.setOutlineColor(sf::Color::Red);
    rect_mob.setFillColor(sf::Color::Red);
    rect_mob.setSize(sf::Vector2f(50,50));
}

void Mob::up(float frame){

    rect_mob.move(0, -getSpeed()*frame);
}

void Mob::down(float frame){

    rect_mob.move(0, getSpeed()*frame);
}

void Mob::left(float frame){

    rect_mob.move(-getSpeed()*frame, 0);
}

void Mob::right(float frame){

    rect_mob.move(getSpeed()*frame, 0);
}

void Mob::diagUpRight(float frame){

    rect_mob.move(getSpeed()*frame/2, -getSpeed()*frame/2);
}

void Mob::diagUpLeft(float frame){

    rect_mob.move(-getSpeed()*frame/2, -getSpeed()*frame/2);
}

void Mob::diagDownLeft(float frame){

    rect_mob.move(-getSpeed()*frame/2, getSpeed()*frame/2);
}

void Mob::diagDownRight(float frame){

    rect_mob.move(getSpeed()*frame/2, getSpeed()*frame/2);
}

void Mob::setX(int aleaWidth){

    rect_mob.setPosition(sf::Vector2f(aleaWidth, getY()));
    //this->aleaWidth = aleaWidth;
}

void Mob::setY(int aleaHeight){

    //this->aleaHeight = aleaHeight;
    rect_mob.setPosition(sf::Vector2f(getX(), aleaHeight));
}

int Mob::getX() const{

    return rect_mob.getPosition().x;
}

int Mob::getY() const{

    return rect_mob.getPosition().y;
}

void Mob::display(sf::RenderWindow &window){

    window.draw(rect_mob);
}

void Mob::rotatation(float frame){

    rect_mob.rotate(0.05*frame);
}

sf::Vector2f Mob::getTopLeft(){

    return rect_mob.getTransform().transformPoint(sf::Vector2f(0,0));
}

sf::Vector2f Mob::getTopRight(){

    return rect_mob.getTransform().transformPoint(sf::Vector2f(rect_mob.getSize().x,0));
}

sf::Vector2f Mob::getBottomLeft() {

    return rect_mob.getTransform().transformPoint(sf::Vector2f(0,rect_mob.getSize().y));
}

sf::Vector2f Mob::getBottomRight(){

    return rect_mob.getTransform().transformPoint(sf::Vector2f(rect_mob.getSize().x,rect_mob.getSize().y));
}

void Mob::setSpeed(float speed){

    this->speed = speed;
}

float Mob::getSpeed(){

    return this->speed;
}
