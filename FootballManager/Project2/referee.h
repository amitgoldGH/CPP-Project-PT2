#ifndef __REFEREE_H
#define __REFEREE_H

#include "person.h"

class Referee : public Person
{
private:

	int gamesPlayed;
	int rating;
public:
	Referee(); //added for dynamic allocation - Asaf
	Referee(const char*  name, int age, const char*  nationality,int rating = 0);
	void show() const;
	~Referee();
	const Referee& operator++(); // Prefix "++X" to increase num of games played.
	int getGamesPlayed();	//for compare - Asaf
	char* getName();		//for printing - Asaf
};

#endif //__REFEREE_H
