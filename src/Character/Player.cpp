#include <SFML/Graphics.hpp>
#include "../../include/character/Player.h"

#define SPEED 0.5f

Player::Player()
{
    //ctor
    init();
}

Player::~Player()
{
    //dtor
}

void Player::init(){

    setX(100);
    setY(50);

    rect_player.setPosition(sf::Vector2f(getX(), getY()));
    rect_player.setOutlineThickness(4);
    rect_player.setOutlineColor(sf::Color::Blue);
    rect_player.setSize(sf::Vector2f(50,50));
//    rect_player.setRotation(120);
    rect_player.setFillColor(sf::Color::Blue);

}

void Player::up(float frame){

    rect_player.move(0, -SPEED*frame);
}

void Player::down(float frame){

    rect_player.move(0, SPEED*frame);
}

void Player::left(float frame){

    rect_player.move(-SPEED*frame, 0);
}

void Player::right(float frame){

    rect_player.move(SPEED*frame, 0);
}

void Player::display(sf::RenderWindow &window){


    window.draw(rect_player);
}

void Player::setX(int x){

    this->x = x;
}

void Player::setY(int y){

    this->y = y;
}

int Player::getX() const{

    return this->x;
}

int Player::getY() const{

    return this->y;
}

void Player::changeColor(sf::Color color){

    rect_player.setOutlineColor(color);
    rect_player.setFillColor(color);
}

void Player::rotatation(float frame){

    rect_player.rotate(0.05*frame);
}
