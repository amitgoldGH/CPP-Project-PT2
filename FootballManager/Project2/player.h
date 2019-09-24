#ifndef __PLAYER_H
#define __PLAYER_H
#include "person.h"
#include "team.h"

class Player : virtual public Person
{

public:
	
	virtual void show() const; // Changed to virtual for inheritors to override.
	double getRate() const; // Changed to const function -Amit

	Player(const char* name, int age,
		const char* nationality,
		int attack, int defence,
		int goalkeeping, int goalScored, int value=0,
		Team::Role role= (Team::Role)0, Team * currentTeam = nullptr);
	void setTeam(Team* team);
	Player operator++(int); // This is a postfix operator. -Amit
	const Player& operator++(); // Added prefix operator -Amit
	bool operator >=(const Player& player) const; //Player is bigger if he scored more goles #Goals*

	~Player();

protected:
	int attack;
	int defence;
	int goalkeeping;
	int goalScored;
	int value;
	Team::Role role;
	Team * currentTeam;

	Player(const Player& other);

};

#endif //__PLAYER_H