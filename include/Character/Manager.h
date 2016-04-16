#ifndef MANAGER_H
#define MANAGER_H

#include "Player.h"
#include "Mob.h"
#include "../Item.h"
#include "../Score.h"


class Manager
{
    public:
        Manager();
        virtual ~Manager();
        void progress(float frame);
        void displays(sf::RenderWindow &window);
        void manageMobDirection(float frame);
        void manageMobMove(float frame);
        void get_RGB_Color(double longeur_Onde);
        void setBlue(int blue);
        void setGreen(int green);
        int getBlue() const;
        int getGreen() const;
        void setRed(int red);
        int getRed() const;
        bool getContinue();
        void setContinue(bool yes);
        void managePlayerCollisionScreen(float frame);
        bool playerCollisionItem(float frame);
        void restart();
    protected:
    private:
        Player player;
        Mob mob;
        Item item;
        Score score;
        int aleaDep, sup, inf, red, green, blue, pts;
        float speed;
        sf::FloatRect right, left, bottom, top;
        double pointerColor;
        bool yes;
};

#endif // MANAGER_H
