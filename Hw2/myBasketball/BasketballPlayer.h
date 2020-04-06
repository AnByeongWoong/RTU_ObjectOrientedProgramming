#include<iostream>
#include<string>

using namespace std;

class BasketballPlayer
{
    public:
        void init(int numberOfPlayer, int totalGoalsOfPlayer);
        void add_goal(int goal);
        int get_numberOfPlayer(){return _numberOfPlayer ;}
        int totalGoalsOfPlayer() {return _totalGoalsOfPlayer;}
    private:
        int _numberOfPlayer;
        int _totalGoalsOfPlayer;
};