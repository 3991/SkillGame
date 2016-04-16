#ifndef ITEM_H
#define ITEM_H


class Item
{
    public:
        Item();
        virtual ~Item();
        void setX(int x);
        void setY(int y);
        int getX() const;
        int getY() const;
        void init();
        void display(sf::RenderWindow &window);
        sf::CircleShape circItem;
        int getDimension() const;
        void setDimension(int dimension);
        void coordinateGenerator();
    protected:
    private:
        int x,y, dimension, aleaWidth, aleaHeight;
};

#endif // ITEM_H
