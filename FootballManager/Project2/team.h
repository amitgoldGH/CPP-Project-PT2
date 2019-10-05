#ifndef __TEAM_H
#define __TEAM_H
#include "person.h" // For NAME_SIZE definition.
#include "coach.h"
#include "manager.h"
class Coach;
class Player;
class Manager;

const int LINEUP_SIZE = 5;// size of the team lineup 
static const char* Roles[15] = { "Striker", "Defender", "Goal-Keeper", "Middle-Fielder" };
// Added array for each role for toString purposes -Amit

class Team 
{

public:
	enum Role { striker, defender, goalkeeper, midlefielder };
	Team(const char name[NAME_SIZE],
		Manager * manager = nullptr,
		Coach * coaches = nullptr,
		Player * lineup = nullptr,
		Player * benchPlayers = nullptr,
		int points=0);
	~Team();

	void setManager(Manager* manger);
	void addCoach(Coach* coach);
	void addPlayer(Player* player);
	const Team& operator+=(int points); // Changed from operator+ confirmed with Riki it was a mistake.
	bool operator >=(const Team& otherTeam) const; //Team is bigger if team have more pointprivate:
	const char* getName() const; // Added method for Player to display team name, as team name is private -Amit

private:
	char name[NAME_SIZE];
	Manager * manager;
	Coach * coaches;
	Player** benchPlayers; // Changed to Pointer array from single pointer
	Player** lineup; // Changed to Pointer array from single pointer,
					 //to allow multiple player pointers in the array
	int points;
};

#endif // !__TEAM_H
