#include "coach.h"

Coach::Coach(const char* name, int age, const char* nationality, Team::Role type = (Team::Role) 0, Team* currentTeam = nullptr)
	: Person(name, age, nationality), type(type), currentTeam(currentTeam)
{

}

void Coach::show() const
{
	Person::show(); // Call show method of parent (Person)
	std::cout << "Role: " << type << "\nTeam: " << ((currentTeam == nullptr) ? "None" : currentTeam->getName()) << std::endl;
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
	type = other.type;
	currentTeam = other.currentTeam;
}

Coach::~Coach()
{

}