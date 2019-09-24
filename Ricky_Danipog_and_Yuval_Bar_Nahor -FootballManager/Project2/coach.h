#ifndef __COACH_H
#define __COACH_H
#include "person.h"
#include "team.h"

class Team;
class Coach : virtual public Person
{
public:
	
	Coach(const char * name,
		int age,
		const char* nationality,
		Team::Role type = (Team::Role) 0 ,
		Team* currentTeam = nullptr);
	~Coach();
	void show() const;
	void setTeam(Team * team);
	

protected:
	Team::Role type;
	Team* currentTeam;
	Coach(const Coach& other);

};

#endif //__COACH_H