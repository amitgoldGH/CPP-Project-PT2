#ifndef __PLAYER_H
#define __PLAYER_H
#include "person.h"
#include "team.h"

static const char* Roles[15] = { "Striker", "Defender", "Goal-Keeper", "Middle-Fielder" };

class Player : virtual public Person
{

public:
	enum Role { striker, defender, goalkeeper, midlefielder };
	void show() const; // Changed to virtual for inheritors to override.
	double getRate() const; // Changed to const function -Amit

	Player(const char* name, int age,
		const char* nationality,
		int attack, int defence,
		int goalkeeping = 0, int goalScored = 0, int value=0,
		Role role = (Role)0, Team* currentTeam = nullptr);
	void setTeam(Team* team);
	Player operator++(int); // This is a postfix operator. -Amit
	const Player& operator++(); // Added prefix operator -Amit
	bool operator >=(const Player& player) const; //Player is bigger if he scored more goles #Goals*
	const Team* getTeam(); // Added to check what team a player is in -Amit
	const char* getName();
	~Player();

	friend std::ostream& operator<<(std::ostream& os, const Player& player);


protected:
	int attack;
	int defence;
	int goalkeeping;
	int goalScored;
	int value;
	Role role;
	Team * currentTeam;

	Player(const Player& other);

};

#endif //__PLAYER_H