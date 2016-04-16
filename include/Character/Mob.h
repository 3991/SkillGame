#ifndef MOB_H
#define MOB_H


class Mob
{
    public:
        Mob();
        virtual ~Mob();
        void init();
        void setX(int x);
        void setY(int y);
        int getX() const;
        int getY() const;
        void up(float frame);
        void down(float frame);
        void left(float frame);
        void right(float frame);
        void diagUpRight(float frame);
        void diagUpLeft(float frame);
        void diagDownRight(float frame);
        void diagDownLeft(float frame);
        void display(sf::RenderWindow &window);
        void rotatation(float frame);
        sf::Vector2f getTopLeft();
        sf::Vector2f getTopRight();
        sf::Vector2f getBottomLeft();
        sf::Vector2f getBottomRight();
        void setSpeed(float speed);
        float getSpeed();
        sf::RectangleShape rect_mob;
    protected:
    private:
        int aleaWidth, aleaHeight;
        float speed;
};

#endif // MOB_H
