#ifndef __MANAGER_H
#define __MANAGER_H
#include "Person.h"
#include "team.h"

class Team;

class Manager : public Person
{

private:
	int yearsOfExperience;
	Team * currentTeam;
	Manager(const Manager& other) = default;

public:
	Manager(const char *name, int age, const char* nationality,int yearsOfExperience);
	void setTeam(Team * team);
	~Manager();
};
#endif //__MANAGER_H
