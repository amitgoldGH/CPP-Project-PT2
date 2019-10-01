#ifndef __MANAGER_H
#define __MANAGER_H
#include "person.h"
#include "team.h"

class Team;

class Manager : public Person
{

private:
	int yearsOfExperience;
	Team * currentTeam;
	Manager(const Manager& other) = default;
	~Manager();

public:
	Manager(const char *name, int age, const char* nationality,int yearsOfExperience);
	void setTeam(Team * team);
};
#endif //__MANAGER_H
