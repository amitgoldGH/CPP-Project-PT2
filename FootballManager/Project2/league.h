#ifndef __LEAGUE_H
#define __LEAGUE_H
#include "team.h"
#include "referee.h"
#include "fixture.h"
#include <vector>
#include "LinkedList.h"
class Team;
class Referee;
class Fixture;
class League
{

private:
	Team leadingTeam;
	std::string name;
	int numberOfTeams;
	int numberOfReferees;
	std::vector<Team> teams;
	std::vector<Referee> referees;
	LinkedList<Referee> refereeList;
	int numberOfFixtures;
	int playedFixtures;
	std::vector<Fixture> fixtures;
	bool onGoing = false; //added for isEnded() - Asaf
public:
	League(std::string lname, int numberOfTeams = 0, //added default 0
		Team * teams = nullptr, int numberofreferees = 0,
		Referee * referees = nullptr, int numberOfFixtures = 0,
		int playedFixtures = 0, Fixture * fixtures = nullptr);

	void addTeam(Team* team);
	void setNumberOfReferees(int numberOfreferees);
	void addReferee(Referee& referee);
	void startSeason();
	void showLeadingTeam() const;
	void showLoosingTeam() const;
	void showLeadingScorer() const;
	void showMostActiveReferee() const;
	void show() const;
	bool isEnded();
};
#endif // !__LEAGUE_H

