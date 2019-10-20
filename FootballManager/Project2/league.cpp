#pragma warning (disable:4996);
#include "league.h"
League::League(const char * lname, int numberOfTeams, Team * teams, int numberofreferees, Referee * referees, int numberOfFixtures, int playedFixtures, Fixture * fixtures)
{
	//name = new char[strlen(lname) + 1];
	strcpy(this->name, lname);
}

League::~League()
{
	//delete name;
	delete[] teams;
	delete[] referees;
	delete[] fixtures;
}

void League::addTeam(Team * team)
{

	//reallocation before adding
	{
		Team* temp = new Team[numberOfteams + 1];
		for (int i = 0; i < numberOfteams; i++)
		{
			temp[i] = teams[i];
		}
		temp[numberOfteams] = *(new Team(*team));
		teams = temp;
		numberOfteams++;
	}

}


void League::setNumberOfReferees(int numberOfreferees)
{
}

void League::addReferee(Referee * referee)
{
	//reallocation before adding
	{
		Referee* temp = new Referee[numberOfReferees + 1];
		for (int i = 0; i < numberOfReferees; i++)
		{
			temp[i] = referee[i];
		}
		temp[numberOfReferees] = *(new Referee(*referee));
		referees = temp;
		numberOfReferees++;
	}
}


/***
calculate number of fixtures according to number of registered teams
calculate number of matches for each fixture
assign teams in matches and put into fixtures, winning team move of to the next fixture
***/
void League::startSeason()
{
	onGoing = true;
	Team* t_list = teams;
	//calculate number of fixtures
	for (int i = numberOfteams; i > 1; i /= 2)
	{
		numberOfFixtures++;
	}
	
	//divide teams to fixtures and begin matches
	for (int j = 0; j < numberOfFixtures; j++)
	{
		Match *matches = new Match[0];								//set of matches for fixture
		Team* n_list = new Team[numberOfteams / (2 * (j+1))];		//set of teams for the next fixture
		int matchNum = 0, i = 0;
		for (; i < numberOfteams/(j+1); i += 2)
		{
				matches[matchNum] = Match(&t_list[i], &t_list[i + 1], &referees[0]);
				n_list[matchNum] = *(matches[matchNum].getWinningTeam());
				matchNum++;
		}

		Fixture f(j+1, i / 2, matches);		// <= BUG HERE ?
		f.Show();
		t_list = n_list;
		//delete matches;
	}

	onGoing = false;


}
/*
const Fixture & League::playFixture()
{
	// TODO: insert return statement here
	return ; //for compilation only
}
*/
void League::showLeadingTeam() const
{
}

void League::showLoosingTeam() const
{
}

void League::showLeadingScorer() const
{
}

void League::showMostActiveReferee() const
{
}

void League::show() const
{
	std::cout << std::endl << "Welcome to " << name << " League!" << std::endl;
	std::cout << "Currently registered " << numberOfteams << " teams" << std::endl;

	for (int i = 0; i < numberOfteams; i++)
	{
		teams[i].show();
	}
	std::cout << std::endl << "Referee list: " << std::endl;
	for (int i = 0; i < numberOfReferees; i++)
	{
		referees[i].show();
	}


}

bool League::isEnded()
{
	return !onGoing;
}
