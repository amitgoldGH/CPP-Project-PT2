
#include "referee.h"

Referee::Referee(const char * name, int age, const char* nationality, int rating = 0) 
	: Person(name,age,nationality), rating(rating), gamesPlayed(0)
{

}

void Referee::show() const
{
	Person::show();
	std::cout << "Played " << gamesPlayed << " Games\nRating: " << rating << std::endl;
}