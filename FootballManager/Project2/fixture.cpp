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
	Match* increased_Matches = new Match[numberOfMatches + 1];
	Match* temp;
	for (int i = 0; i < numberOfMatches; i++)
	{
		increased_Matches[i] = matches[i];
	}
	increased_Matches[numberOfMatches] = (Match(*m));
	
	temp = matches;
	matches = increased_Matches;

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
