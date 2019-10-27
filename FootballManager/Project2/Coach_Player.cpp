
#include "coach_player.h"

CoachPlayer::CoachPlayer(const Coach& c, const Player& p) : Person(c), Player(p), Coach(c)
{
	//nothing to add - asaf
}

void CoachPlayer::show() const
{
	Player::show();
}