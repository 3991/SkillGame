#include <SFML/Graphics.hpp>
#include <iostream>
#include "../../include/character/Manager.h"

#define SPEED 0.5f




Manager::Manager()
{
    //ctor
    srand(time(0));
    aleaDep = (rand() % 4) + 1;

    right = sf::FloatRect(800-1, 0, 100, 600);
    left = sf::FloatRect(-10, 0, 10, 600);
    bottom = sf::FloatRect(0, 600-1, 800, 100);
    top = sf::FloatRect(0, -10, 800, 10);
    pointerColor=581;
    blue = 0;red=255;green=255;
    setContinue(true);
}

Manager::~Manager()
{
    //dtor
}

void Manager::progress(float frame){

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){

        // Interaction mob - joueur
        if(mob.rect_mob.getGlobalBounds().intersects(player.rect_player.getGlobalBounds())){

//            player.down(frame);
            player.changeColor(sf::Color::Red);
            pointerColor+=0.8;
            get_RGB_Color(pointerColor);
        }else{

            player.changeColor(sf::Color::Blue);
        }

        player.up(frame);
        if(playerCollisionItem(frame)){

            item.coordinateGenerator();

    if(playerCollisionItem(frame)){

                int x = item.getX();
                if((x+=player.rect_player.getSize().x*2) < 800){

                    item.setX(x);
                }else{

                    x = item.getX();
                    x-=player.rect_player.getSize().x*2;
                    item.setX(x);
                }

                int y = item.getY();
                if((y+=player.rect_player.getSize().y*2) < 600){

                    item.setY(y);
                }else{

                    y = item.getY();
                    y-=player.rect_player.getSize().y*2;
                    item.setY(y);
                }
            }

            pts = score.getScore();
            score.setScore(++pts);
        }


        managePlayerCollisionScreen(frame);

        mob.rotatation(frame);

        manageMobMove(frame);
        manageMobDirection(frame);

    }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){

        if(mob.rect_mob.getGlobalBounds().intersects(player.rect_player.getGlobalBounds())){

//            player.up(frame);
            player.changeColor(sf::Color::Red);
            pointerColor+=0.8;
            get_RGB_Color(pointerColor);
        }else{

            player.changeColor(sf::Color::Blue);
        }

        player.down(frame);

        if(playerCollisionItem(frame)){

            item.coordinateGenerator();

             if(playerCollisionItem(frame)){

                int x = item.getX();
                if((x+=player.rect_player.getSize().x*2) < 800){

                    item.setX(x);
                }else{

                    x = item.getX();
                    x-=player.rect_player.getSize().x*2;
                    item.setX(x);
                }

                int y = item.getY();
                if((y+=player.rect_player.getSize().y*2) < 600){

                    item.setY(y);
                }else{

                    y = item.getY();
                    y-=player.rect_player.getSize().y*2;
                    item.setY(y);
                }
            }

            pts = score.getScore();
            score.setScore(++pts);
        }
        managePlayerCollisionScreen(frame);

        mob.rotatation(frame);

        manageMobMove(frame);
        manageMobDirection(frame);

    }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){

        if(mob.rect_mob.getGlobalBounds().intersects(player.rect_player.getGlobalBounds())){

//            player.right(frame);
            player.changeColor(sf::Color::Red);
            pointerColor+=0.8;
            get_RGB_Color(pointerColor);
        }else{

            player.changeColor(sf::Color::Blue);
        }

        player.left(frame);

        if(playerCollisionItem(frame)){

            item.coordinateGenerator();

            if(playerCollisionItem(frame)){

                int x = item.getX();
                if((x+=player.rect_player.getSize().x*2) < 800){

                    item.setX(x);
                }else{

                    x = item.getX();
                    x-=player.rect_player.getSize().x*2;
                    item.setX(x);
                }

                int y = item.getY();
                if((y+=player.rect_player.getSize().y*2) < 600){

                    item.setY(y);
                }else{

                    y = item.getY();
                    y-=player.rect_player.getSize().y*2;
                    item.setY(y);
                }
            }

            pts = score.getScore();
            score.setScore(++pts);
        }

        managePlayerCollisionScreen(frame);

        mob.rotatation(frame);

        manageMobMove(frame);
        manageMobDirection(frame);

    }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){

        if(mob.rect_mob.getGlobalBounds().intersects(player.rect_player.getGlobalBounds())){

//            player.left(frame);
            player.changeColor(sf::Color::Red);
            pointerColor+=0.8;
            get_RGB_Color(pointerColor);
        }else{

            player.changeColor(sf::Color::Blue);
        }

        player.right(frame);

        if(playerCollisionItem(frame)){

            item.coordinateGenerator();

            speed = mob.getSpeed();
            if(speed > 0){

                speed -= 0.1f;
                mob.setSpeed(speed);
            }

            if(playerCollisionItem(frame)){


                int x = item.getX();
                if((x+=player.rect_player.getSize().x*2) < 800){

                    item.setX(x);
                }else{

                    x = item.getX();
                    x-=player.rect_player.getSize().x*2;
                    item.setX(x);
                }

                int y = item.getY();
                if((y+=player.rect_player.getSize().y*2) < 600){

                    item.setY(y);
                }else{

                    y = item.getY();
                    y-=player.rect_player.getSize().y*2;
                    item.setY(y);
                }
            }

            pts = score.getScore();
            score.setScore(++pts);
        }
        managePlayerCollisionScreen(frame);

        mob.rotatation(frame);

        manageMobMove(frame);
        manageMobDirection(frame);
    }


}

void Manager::manageMobDirection(float frame){


    if(aleaDep==1){

        mob.diagUpRight(frame);

    }else if(aleaDep==2){

        mob.diagUpLeft(frame);

    }else if(aleaDep==3){

        mob.diagDownLeft(frame);

    }else if(aleaDep==4){

        mob.diagDownRight(frame);
    }
}



void Manager::manageMobMove(float frame){

    if(mob.rect_mob.getGlobalBounds().intersects(right)){

        mob.left(frame);

        speed = mob.getSpeed();
        if(speed < 1.5){

            speed += 0.1f;
            mob.setSpeed(speed);
        }

        if(aleaDep == 4){

            aleaDep = 3;
        }else if(aleaDep == 1){

            aleaDep = 2;
        }
    }else if(mob.rect_mob.getGlobalBounds().intersects(left)){

        mob.right(frame);

        speed = mob.getSpeed();
        if(speed < 1.5){

            speed += 0.1f;
            mob.setSpeed(speed);
        }

        if(aleaDep == 3){

            aleaDep = 4;
        }else if(aleaDep == 2){

            aleaDep = 1;
        }
    }else if(mob.rect_mob.getGlobalBounds().intersects(bottom)){

        mob.up(frame);


        speed = mob.getSpeed();
        if(speed < 1.5){

            speed += 0.1f;
            mob.setSpeed(speed);
        }

        if(aleaDep == 4){

            aleaDep = 1;
        }else if(aleaDep == 3){

            aleaDep = 2;
        }
    }else if(mob.rect_mob.getGlobalBounds().intersects(top)){

        mob.down(frame);


        speed = mob.getSpeed();
        if(speed < 1.5){

            speed += 0.1f;
            mob.setSpeed(speed);
        }

        if(aleaDep == 2){

            aleaDep = 3;
        }else if(aleaDep == 1){

            aleaDep = 4;
        }
    }
}

void Manager::managePlayerCollisionScreen(float frame){

    if(player.rect_player.getGlobalBounds().intersects(right)){

        player.left(frame);
        player.rect_player.setPosition(800-player.rect_player.getSize().y,player.rect_player.getPosition().y);
    }if(player.rect_player.getGlobalBounds().intersects(left)){

        player.right(frame);
        player.rect_player.setPosition(0,player.rect_player.getPosition().y);
    }if(player.rect_player.getGlobalBounds().intersects(bottom)){

        player.up(frame);
        player.rect_player.setPosition(player.rect_player.getPosition().x,600-player.rect_player.getSize().x);
    }if(player.rect_player.getGlobalBounds().intersects(top)){

        player.down(frame);
        player.rect_player.setPosition(player.rect_player.getPosition().x,0);
    }
}

bool Manager::playerCollisionItem(float frame){

    if(player.rect_player.getGlobalBounds().intersects(item.circItem.getGlobalBounds())){

        return true;
    }

    return false;
}

void Manager::displays(sf::RenderWindow &window){

    player.display(window);
    mob.display(window);
    item.display(window);
    score.afficher(window);
}

void Manager::get_RGB_Color(double pointerColor){

    if(pointerColor >= 430 && pointerColor < 440){

        red-=(pointerColor-430)/(440-430)*255;
        setRed(red);
        setGreen(0);
        setBlue(255);
    }else if(pointerColor < 490){

        setRed(0);
        setGreen(green);
        setBlue(255);
    }else if(pointerColor > 580 && pointerColor < 646){

        green=0;
        setRed(255);
        green=(645-pointerColor)/(645-580)*255;
        setGreen(green);
        setBlue(0);
    }else{

        setRed(255);
        setGreen(0);
        setBlue(0);
        setContinue(false);
    }
}

void Manager::restart(){

    pointerColor=581;
    score.setScore(0);
    setContinue(true);
}

bool Manager::getContinue(){

    return this->yes;
}

void Manager::setContinue(bool yes){

    this->yes = yes;
}

void Manager::setBlue(int blue){

    this->blue = blue;
}

void Manager::setGreen(int green){

    this->green = green;
}

int Manager::getBlue() const{

    return this->blue;
}

int Manager::getGreen() const{

    return this->green;
}

void Manager::setRed(int red){

    this->red = red;
}

int Manager::getRed() const{

    return this->red;
}
