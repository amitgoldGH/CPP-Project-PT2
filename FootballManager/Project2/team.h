#ifndef __TEAM_H
#define __TEAM_H
#include "person.h" // For NAME_SIZE definition.
#include "coach.h"
#include "manager.h"
class Coach;
class Player;
class Manager;

const int LINEUP_MAX_SIZE = 5;// size of the team lineup 
const int BENCH_SIZE_MULTI = 3; // Multiplier for bench size.
// Added array for each role for toString purposes -Amit

class Team 
{

public:
	Team(const char name[NAME_SIZE],
		Manager* manager = nullptr,
		Coach* coaches = nullptr,
		Player** lineup = nullptr,
		Player** benchPlayers = nullptr, int lineup_Size = 0, int bench_Size = 0,
		int points=0);
	~Team();

	void setManager(Manager* manger);
	void addCoach(Coach* coach);
	void addPlayer(Player* player);
	const Team& operator+=(int points); // Changed from operator+ confirmed with Riki it was a mistake.
	bool operator >=(const Team& otherTeam) const; //Team is bigger if team have more pointprivate:
	const char* getName() const; // Added method for Player to display team name, as team name is private -Amit

	void show() const;
private:
	char name[NAME_SIZE];
	Manager * manager;
	Coach * coaches;
	Player** benchPlayers; // Changed to Pointer array from single pointer, needs dynamic allocation
	Player** lineup; // Changed to Pointer array from single pointer,  needs dynamic allocation
					 //to allow multiple player pointers in the array
	int players_In_Lineup; // Added to have phys size of array -Amit
	int players_On_Bench; // Added to have phys size of array -Amit
	int points;
};

#include "player.h" // for forward declaration of player class.

#endif // !__TEAM_H
