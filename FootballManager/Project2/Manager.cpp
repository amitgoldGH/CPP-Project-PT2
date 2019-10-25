#include "manager.h"

Manager::Manager(std::string  name, int age, std::string  nationality, int yearsOfExperience, Team* currTeam) 
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
	std::cout.setf(std::ios::left);
	std::cout.width(10);
	std::cout << "Name";
	std::cout.width(5);
	std::cout << "Age";
	std::cout.width(13);
	std::cout << "Nationality";
	std::cout.width(8);
	std::cout << "YOE";
	std::cout.width(8);
	std::cout << "Team" << std::endl;
	Person::show();
	std::cout.width(8);
	std::cout << yearsOfExperience;
	std::cout.width(8);
	std::cout << ((currentTeam == nullptr) ? "None" : currentTeam->getName()) << std::endl;
}
