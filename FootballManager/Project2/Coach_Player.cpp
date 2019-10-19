
#include "coach_player.h"

CoachPlayer::CoachPlayer(const Coach& c, const Player& p) : Person(c), Player(p), Coach(c)
{
	//nothing to add - asaf
}

void CoachPlayer::show() const
{
	// Person::show(); /Player already calls this method -Amit
	// Coach::show(); /Player already displays all the information that coach shows -Amit
	Player::show();
}