#pragma warning (disable:4996);
#include "league.h"
League::League(const char * name, int numberOfTeams, Team * teams, int numberofreferees, Referee * referees, int numberOfFixtures, int playedFixtures, Fixture * fixtures) 
{
	name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}

League::~League()
{
	delete[] teams;
	delete[] referees;
	delete[] fixtures;
}

void League::addTeam(Team * team)
{

		//reallocation before adding
		{
			Team* temp = new Team[numberOfteams+1];
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



	
	int fixture_count = 1;
	onGoing = true;
	  //THIS PART NEEDS FIXING. HEAP CORRUPTION
	//while (numberOfteams / (2 * fixture_count) > 1)
	{
		Match *matches = new Match[0];
		int matchNum = 0;
		int i = 0, fix = 1;
		for (i = 0; i < numberOfteams; i += 2)
		{
			if (teams != nullptr && teams + 1 != nullptr)
			{
				matches[matchNum] = Match(&teams[i], &teams[i + 1], &referees[0]);
				matchNum++;
			}
		}
		
		Fixture f1(fix, i/2, matches);		// <= BUG HERE ?
		f1.Show();


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
	std::cout << std::endl << "Welcome to "<<name<<" League!" << std::endl;
	std::cout << "Currently registered "<<numberOfteams<< " teams" << std::endl;

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
