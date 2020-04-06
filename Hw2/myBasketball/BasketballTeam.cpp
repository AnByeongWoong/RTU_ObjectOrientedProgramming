#include "BasketballTeam.h"

bool BasketballTeam::checkWin(){
    int total = 0;
    for(int i=0; i<5; i++){
        total += _MemberOfBasketball[i].totalGoalsOfPlayer();
    }
    if(total > 20)
        return true;
    return false;
}