#include "BasketballPlayer.h"

void BasketballPlayer::init(int numberOfPlayer, int totalGoalsOfPlayer)
{
    _numberOfPlayer = numberOfPlayer;
    _totalGoalsOfPlayer = totalGoalsOfPlayer;
}
void BasketballPlayer::add_goal(int goal)
{
    _totalGoalsOfPlayer += goal;
}