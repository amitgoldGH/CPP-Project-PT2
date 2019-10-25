#ifndef __COACH_H
#define __COACH_H

#include "person.h"
#include "team.h"

class Team;
class Coach : virtual public Person
{
public:
	
	Coach(const std::string name, int age, const std::string nationality, Team* currentTeam = nullptr);
	void show() const;
	void setTeam(Team* team);
	

protected:
	Team* currentTeam;
};

#endif //__COACH_H