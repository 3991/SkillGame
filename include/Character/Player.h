#ifndef SHAPE_H
#define SHAPE_H



class Player
{
    public:
        Player();
        virtual ~Player();
        void setX(int x);
        void setY(int y);
        int getX() const;
        int getY() const;
        void init();
        void up(float frame);
        void down(float frame);
        void left(float frame);
        void right(float frame);
        void display(sf::RenderWindow &window);
        void changeColor(sf::Color color);
        sf::RectangleShape rect_player;
        void rotatation(float frame);
    protected:
    private:

        int x, y;int nb_alea;
};

#endif // SHAPE_H
