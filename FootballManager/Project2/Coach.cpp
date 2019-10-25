#include "coach.h"

Coach::Coach(const std::string  name, int age, const std::string  nationality, Team* currentTeam)
	: Person(name, age, nationality), currentTeam(currentTeam)
{

}

void Coach::show() const
{
	std::cout.setf(std::ios::left);
	std::cout.width(10);
	std::cout << "Name";
	std::cout.width(5);
	std::cout << "Age";
	std::cout.width(13);
	std::cout << "Nationality";
	std::cout.width(8);
	std::cout << "Team" << std::endl;
	Person::show(); // Call show method of parent (Person)
	std::cout << ((currentTeam == nullptr) ? "None" : currentTeam->getName()) << std::endl;
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
/*
Coach::Coach(const Coach& other) : Person(other)
{
	currentTeam = other.currentTeam;
}

Coach::~Coach()
{

}
*/
