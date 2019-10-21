#ifndef __LEAGUE_H
#define __LEAGUE_H
#include "team.h"
#include "referee.h"
#include "fixture.h"

class Team;
class Referee;
class Fixture;
class League
{

private:
	char name[30];
	int numberOfteams;
	int numberOfReferees;
	Team* teams;
	Referee * referees;
	int numberOfFixtures;
	int playedFixtures;
	Fixture* fixtures;
	bool onGoing = false; //added for isEnded() - Asaf
public:
	League(const char*  name, int numberOfTeams = 0, //added default 0
		Team * teams = nullptr, int numberofreferees = 0,
		Referee * referees = nullptr, int numberOfFixtures = 0,
		int playedFixtures = 0, Fixture * fixtures = nullptr);

	~League();
	void addTeam(Team * team);
	void setNumberOfReferees(int numberOfreferees);
	void addReferee(Referee * referee);
	void startSeason();
	//const Fixture& playFixture(); - commented, not used right now - Asaf
	void showLeadingTeam() const;
	void showLoosingTeam() const;
	void showLeadingScorer() const;
	void showMostActiveReferee() const;
	void show() const;
	bool isEnded();
};
#endif // !__LEAGUE_H

