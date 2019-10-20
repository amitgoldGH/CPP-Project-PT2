#include "fixture.h"

Fixture::Fixture(int number, int numberOfMatches, Match* matches) : number(number), matches(matches), numberOfMatches(numberOfMatches)
{
}


Fixture::~Fixture()
{
}

Fixture::Fixture(const Fixture& other) : number(other.number), matches(other.matches) {}

void Fixture::addMatch(Match * m)
{
	Match* temp = new Match[numberOfMatches + 1];
	for (int i = 0; i < numberOfMatches; i++)
	{
		temp[i] = matches[i];
	}
	temp[numberOfMatches] = *(new Match(*m));
	matches = temp;
	numberOfMatches++;
	delete[] temp;
}

void Fixture::Show()
{

	std::cout << "Fixture " << number << ":" << std::endl;
	for (int i = 0; i < numberOfMatches; i++)
	{
		matches[i].show();
	}



}



std::ostream& operator<<(std::ostream& os, const Fixture& fixture)
{
	os << fixture.number << " " << fixture.matches;
	return os;
}
