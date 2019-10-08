#ifndef __TEAM_H
#define __TEAM_H
#include "person.h" // For NAME_SIZE definition.
#include "coach.h"
#include "manager.h"
#include <ctime>    // For time()
#include <cstdlib>  // For srand() and rand()

#define LINEUP_MAX_SIZE 5 // size of the team lineup 
#define BENCH_SIZE_MULTI 3 // Multiplier for bench size.
// Added array for each role for toString purposes -Amit

class Coach;
class Player;
class Manager;
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
	bool isReady() const; //  Check if lineup is full and team is ready for a match
	void show() const; // Print team's information to console.
private:
	char name[NAME_SIZE];
	Manager * manager;
	Coach * coaches;
	Player* benchPlayers[LINEUP_MAX_SIZE * BENCH_SIZE_MULTI]; // Changed to pointer array
	Player* lineup[LINEUP_MAX_SIZE]; // Changed to pointer array
					 
	int players_In_Lineup; // Added to have phys size of array -Amit
	int players_On_Bench; // Added to have phys size of array -Amit
	int points;
};

#include "player.h" // for forward declaration of player class.

#endif // !__TEAM_H
