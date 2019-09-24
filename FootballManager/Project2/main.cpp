#include <iostream>
using namespace std;
#include <fstream>

#include "player.h"
#include "coach.h"
#include "manager.h"
#include "referee.h"
#include "league.h"
#include "fixture.h"

League * readLeague(ifstream& inputFile);
Team * readTeam(ifstream& inputFile);
Player * readPlayer(ifstream& inputFile);
Coach * readCoach(ifstream& inputFile);
Manager * readManager(ifstream& inputFile);
Referee * readReferee(ifstream& inputFile);

int main()
{
	
	ifstream inputFile("League.txt");
	League * league = readLeague(inputFile);
	/*
	 *start season (create season fixtures)
	 *create matches and assign referees for each match
	 */
	league->startSeason();
	/*
	 *Play matches until the end of the season
	 *	-assign the match number of goals (random)
	 *	-for each goal u assign u will need to assign (random) player that scored
	 *	-display the fixture's matches results
	 *	-every fixture played u should increment number of fixtures played
	 */
	do 
	{
		Fixture fixture = league->playFixture();
		cout << fixture;
	} while (league->isEnded());

	//end season
	/*show League Table*/
	league->show();
	//show leading team(team)
	league->showLeadingTeam();
	//show the loosing team(team)
	league->showLoosingTeam();
	//show the leading scorer(player)
	league->showLeadingScorer();
	//show the ref that played the most matches
	league->showMostActiveReferee();
	inputFile.close();
	system("pause");
	return 0;
}

League * readLeague(ifstream& inputFile)
{
	int numberOfTeams;
	int numberOfreferees;
	char name[NAME_SIZE];
	League * newLeague;

	/*Get League name*/
	inputFile >> name;
	/*Get number of teams*/
	inputFile >> numberOfTeams;
	newLeague = new League(name, numberOfTeams);

	for (int i = 0; i < numberOfTeams; i++)
	{
		Team * team = readTeam(inputFile);
		newLeague->addTeam(team);
	}

	/*Get number of referees*/
	inputFile >> numberOfreferees;
	newLeague->setNumberOfReferees(numberOfreferees);
	for (int i = 0; i < numberOfreferees; i++)
	{
		Referee * referee = readReferee(inputFile);
		newLeague->addReferee(referee);
	}


	return newLeague;
}

Team * readTeam(ifstream& inputFile)
{
	int numberOfPlayers, numberOfCoaches;
	char name[NAME_SIZE];
	
	/*Get team name*/
	inputFile >> name;
	/*Get number of players*/
	inputFile >> numberOfPlayers;

	Team * newTeam = new Team(name);
	for (int i = 0; i < numberOfPlayers; i++)
	{
		Player * player = readPlayer(inputFile);
		newTeam->addPlayer(player);
	}

	/*Get number of coaches*/
	inputFile >> numberOfCoaches;

	for (int i = 0; i < numberOfCoaches; i++)
	{
		Coach * coach = readCoach(inputFile);
		newTeam->addCoach(coach);
	}

	Manager * manager = readManager(inputFile);
	newTeam->setManager(manager);
	return newTeam;
}

Player * readPlayer(ifstream& inputFile)
{
	char name[NAME_SIZE], nationality[NAME_SIZE];
	int age, attack, defence, goalkeeping, goalScored, value, role;

	/*Get Player attributes*/
	inputFile >> name >> age >>
		nationality >> attack >>
		defence >> goalkeeping >>
		goalScored >> value >> role; 

	return new Player(name, age, nationality, attack, defence, goalkeeping, goalScored, value, (Team::Role) role);
}

Coach * readCoach(ifstream& inputFile)
{
	char name[30], nationality[30];
	int age, type;

	/*Get Coach attributes*/
	inputFile >> name >> age >> nationality >> type;

	return new Coach(name, age, nationality, (Team::Role) type);
}

Manager * readManager(ifstream& inputFile)
{
	char name[NAME_SIZE], nationality[NAME_SIZE];
	int age, yearsOfExperience;

	/*Get manager attributes*/
	inputFile >> name >> age >> nationality >> yearsOfExperience;

	return new Manager(name, age, nationality, yearsOfExperience);
}

Referee* readReferee(ifstream& inputFile) 
{
	char name[NAME_SIZE], nationality[NAME_SIZE];
	int age, rating;

	/*Get referee attributes*/
	inputFile >> name >> age >> nationality >> rating;

	return new Referee(name, age, nationality, rating);
}