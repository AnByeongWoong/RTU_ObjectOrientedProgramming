#include"BasketballPlayer.h"

class BasketballTeam
{
    public:
        bool checkWin();
        int get_totalGoalOfTeam(){ return _totalGoalOfTeam; }
    private:
        BasketballPlayer _MemberOfBasketball[5];
        int _totalGoalOfTeam;
};