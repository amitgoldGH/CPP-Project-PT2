#ifndef __MATCH_H
#define __MATCH_H
#include "team.h"
#include "referee.h"

#define MAX_GOALS_IN_MATCH 7

class Match
{

private:
	Team * homeTeam;
	Team * awayTeam;
	int result[2] = { 0,0 }; //added default
	Referee * referee;

public:
	Match(const Match& other) = default; //moved to public

	Match(); //added for dynamic allocation - Asaf
	Match(Team* homeTeam, Team* awayTeam, Referee* referee);//Inside the constructor need to play Match random score and assign also randommly assign goal to player and score to winning team. 
	void playMatch();
	~Match();
	void show() const;



};
#endif // !__MATCH_H

