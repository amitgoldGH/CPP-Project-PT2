#include "fixture.h"

Fixture::Fixture(int number, std::vector<Match> matches) : number(number), matches(matches)
{

}


Fixture::~Fixture(){}

Fixture::Fixture(const Fixture& other) : number(other.number), matches(other.matches) {}

void Fixture::addMatch(Match * m)
{
	matches.push_back(*m);
}

void Fixture::Show()
{

	std::cout << "Fixture " << number << ":" << std::endl;
	for (Match match : matches)
		match.show();
}



std::ostream& operator<<(std::ostream& os, const Fixture& fixture) // NOT WORKING, MATCH DOESNT HAVE << operator
{
	os << fixture.number << " ";
	for (Match m : fixture.matches)
		os << &m;
	return os;
}
