#include "manager.h"

Manager::Manager(const char* name, int age, const char* nationality, int yearsOfExperience, Team* currTeam) 
	: Person(name, age, nationality)
	, yearsOfExperience(yearsOfExperience), currentTeam(currTeam)
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

void Manager::show() const
{
	Person::show();
	std::cout << "Years of Experience: " << yearsOfExperience 
		<< "\nTeam: " << ((currentTeam == nullptr) ? "None" : currentTeam->getName()) << std::endl;
}
