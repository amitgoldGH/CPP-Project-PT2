#include "coach.h"

Coach::Coach(const char* name, int age, const char* nationality, Team* currentTeam)
	: Person(name, age, nationality), currentTeam(currentTeam)
{

}

void Coach::show() const
{
	Person::show(); // Call show method of parent (Person)
	std::cout << "Team: " << ((currentTeam == nullptr) ? "None" : currentTeam->getName()) << std::endl;
}

void Coach::setTeam(Team* team) 
{
	if (currentTeam != team)
	{
		currentTeam = team;
		if (currentTeam != nullptr)
		{
			currentTeam->addCoach(this);
		}
	}
}

Coach::Coach(const Coach& other) : Person(other)
{
	currentTeam = other.currentTeam;
}

Coach::~Coach()
{

}