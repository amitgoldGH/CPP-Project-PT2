#ifndef __REFEREE_H
#define __REFEREE_H

#include "person.h"

class Referee : public Person
{
private:

	int gamesPlayed;
	int rating;
public:
	Referee(std::string  name, int age, std::string  nationality,int rating = 0);
	void show() const;
	const Referee& operator++(); // Prefix "++X" to increase num of games played.
	int getGamesPlayed();	//for compare - Asaf
	std::string getName();		//for printing - Asaf
};

#endif //__REFEREE_H
