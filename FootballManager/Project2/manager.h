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

public:
	Manager(const char *name, int age, const char* nationality,int yearsOfExperience, Team* currTeam = nullptr);
	void setTeam(Team * team);
	~Manager();
	void show() const;
};
#endif //__MANAGER_H
