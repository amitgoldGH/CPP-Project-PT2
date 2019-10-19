
#include "referee.h"

Referee::Referee()
{
}

Referee::Referee(const char * name, int age, const char* nationality, int rating)
	: Person(name,age,nationality), rating(rating), gamesPlayed(0)
{

}

void Referee::show() const
{
	std::cout.setf(std::ios::left);
	std::cout.width(10);
	std::cout << "Name";
	std::cout.width(5);
	std::cout << "Age";
	std::cout.width(13);
	std::cout << "Nationality";
	std::cout.width(8);
	std::cout << "Games";
	std::cout.width(8);
	std::cout << "Rating" << std::endl;
	Person::show();
	std::cout.width(8);
	std::cout << gamesPlayed;
	std::cout.width(8);
	std::cout.precision(4);
	std::cout << rating << std::endl;
}

Referee::~Referee()
{
}

const Referee& Referee::operator++()
{
	++gamesPlayed;
	return *this;
}
