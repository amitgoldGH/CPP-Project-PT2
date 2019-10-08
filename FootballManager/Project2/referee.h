#ifndef __REFEREE_H
#define __REFEREE_H

#include "person.h"

class Referee : public Person
{
private:

	int gamesPlayed;
	int rating;
public:
	Referee(const char * name, int age, const char* nationality,int rating = 0);
	void show() const;
	~Referee();

};

#endif //__REFEREE_H
