#ifndef SCORE_H
#define SCORE_H

class Score
{
    public:
        Score();
        virtual ~Score();
        void afficher(sf::RenderWindow &window);
        int getScore();
        void setScore(int score);
    protected:
    private:
        int score;
};

#endif // SCORE_H
