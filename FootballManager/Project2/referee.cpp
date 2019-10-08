
#include "referee.h"

Referee::Referee(const char * name, int age, const char* nationality, int rating) 
	: Person(name,age,nationality), rating(rating), gamesPlayed(0)
{

}

void Referee::show() const
{
	Person::show();
	std::cout << "Played " << gamesPlayed << " Games\nRating: " << rating << std::endl;
}