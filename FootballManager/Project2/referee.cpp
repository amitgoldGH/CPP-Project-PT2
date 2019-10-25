
#include "referee.h"

//Referee::Referee(){}

Referee::Referee(std::string name, int age, std::string  nationality, int rating)
	: Person(name,age,nationality), rating(rating), gamesPlayed(0)
{

}

void Referee::show() const
{
	
	Person::show();
	std::cout.width(8);
	std::cout << gamesPlayed;
	std::cout.width(8);
	std::cout.precision(4);
	std::cout << rating << std::endl;
}

//Referee::~Referee(){}

const Referee& Referee::operator++()
{
	++gamesPlayed;
	return *this;
}

int Referee::getGamesPlayed()
{
	return gamesPlayed;
}

std::string Referee::getName()
{
	return name;
}
