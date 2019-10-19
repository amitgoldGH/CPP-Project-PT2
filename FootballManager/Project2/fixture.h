#ifndef __FIXTURE_H
#define __FIXTURE_H
#include "match.h"

class Fixture
{

private:
	int number;
	Match * matches;
	int numberOfMatches = 0; //added for show method
	

public:
	Fixture(int number, int numberOfMatches, Match * matches = nullptr); //added , int numberOfMatches - Asaf

	~Fixture();
	Fixture(const Fixture& other);

	void addMatch(Match* m); //added to make the class more dynamic
	void Show();	//added to display more info
	friend std::ostream& operator<<(std::ostream& os,const Fixture& fixture);

};
#endif // !__FIXTURE_H

