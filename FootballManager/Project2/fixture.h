#ifndef __FIXTURE_H
#define __FIXTURE_H
#include "match.h"
#include <vector>

class Fixture
{

private:
	int number;
	std::vector<Match> matches;
	

public:
	Fixture(int number, std::vector<Match>& matches); 
	void addMatch(Match* m); //added to make the class more dynamic
	void Show();	//added to display more info
	friend std::ostream& operator<<(std::ostream& os,const Fixture& fixture);

};
#endif // !__FIXTURE_H

