#ifndef __FIXTURE_H
#define __FIXTURE_H
#include "match.h"

class Fixture
{

private:
	int number;
	Match * matches;

public:
	Fixture(int number, Match * matches = nullptr);
	~Fixture();
	Fixture(const Fixture& other);
	

	friend ostream& operator<<(ostream& os,const Fixture& fixture);

};
#endif // !__FIXTURE_H

