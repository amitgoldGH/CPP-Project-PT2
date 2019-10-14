#include "fixture.h"

Fixture::Fixture(int number, Match* matches) : number(number) , matches(matches) {}

Fixture::~Fixture()
{
	delete[] matches;
}

Fixture::Fixture(const Fixture& other) : number(other.number), matches(other.matches) {}

std::ostream& operator<<(std::ostream& os, const Fixture& fixture)
{
	os << fixture.number << " " << fixture.matches;
	return os;
}
