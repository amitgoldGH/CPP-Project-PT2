#ifndef __COACH_H
#define __COACH_H

#include "person.h"
#include "team.h"

class Team;
class Coach : virtual public Person
{
public:
	
	Coach(const std::string name, int age, const std::string nationality, Team* currentTeam = nullptr);
	// Team::Role type = Team::striker , Irrelevant for coach -Amit.
	~Coach();
	void show() const;
	void setTeam(Team* team);
	

protected:
	// Team::Role type; irrelevant for coach -Amit
	Team* currentTeam;
	Coach(const Coach& other);

};

#endif //__COACH_H