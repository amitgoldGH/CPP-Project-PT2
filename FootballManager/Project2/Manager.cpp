#include "manager.h"

Manager::Manager(const char* name, int age, const char* nationality, int yearsOfExperience) 
	: Person(name, age, nationality), yearsOfExperience(yearsOfExperience)
{

}


void Manager::setTeam(Team * team)
{
	if (currentTeam != team)
	{
		currentTeam = team;
		if (team != nullptr)
		{
			team->setManager(this);
		}
	}
}

Manager::~Manager()
{

}
