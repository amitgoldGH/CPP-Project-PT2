#pragma warning (disable:4996)
#include "league.h"
League::League(std::string lname, int numberOfTeams, Team * teams, int numberofreferees, Referee * referees, int numberOfFixtures, int playedFixtures, Fixture * fixtures)
	: name(lname) /*numberOfTeams(numberOfTeams), teams(teams), numberOfReferees(numberofreferees), referees(referees),
	numberOfFixtures(numberOfFixtures), playedFixtures(0), fixtures(fixtures)
	*/
{
	//name = new char[strlen(lname) + 1];
	//strcpy(this->name, lname);
}

League::~League()
{
	//delete name;
	//delete[] teams;
	//delete[] referees;
	//delete[] fixtures;
}

void League::addTeam(Team * team)
{

	//reallocation before adding
	{
		Team* temp = new Team[numberOfTeams + 1];
		for (int i = 0; i < numberOfTeams; i++)
		{
			temp[i] = teams[i];
		}
		delete[] teams;	//clear old memory
		temp[numberOfTeams] = (Team(*team));
		teams = temp;
		numberOfTeams++;
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
			temp[i] = referees[i];
		}
		delete[] referees;	//clear old memory
		temp[numberOfReferees] = (Referee(*referee));
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
	//Reset every player's current league score to 0, used to see how many goals scored in this specific league.
	for (int x = 0; x < numberOfTeams; ++x) 
	{
		Player** curr_Lineup = teams[x].getLineup();
		for (int y = 0; y < LINEUP_MAX_SIZE; ++y)
		{
			curr_Lineup[y]->setLeagueGoal(0);
		}
	}


	onGoing = true;
	Team* t_list = teams;
	//calculate number of fixtures
	for (int i = numberOfTeams; i > 1; i /= 2)
	{
		numberOfFixtures++;
	}
	
	//divide teams to fixtures and begin matches
	for (int j = 0; j < numberOfFixtures; j++)
	{
		Match* matches;
		Team* n_list;
		matches = new Match[numberOfTeams / 2];				//set of matches for fixture
		n_list = new Team[numberOfTeams / (2 * (j+1))];		//set of teams for the next fixture, decreces by half for every fixture
		int matchNum = 0, i = 0;
		for (; i < numberOfTeams/(j+1); i += 2)
		{
			matches[matchNum] = Match(&t_list[i], &t_list[i + 1], &referees[(rand() % numberOfReferees)]); //create match
			n_list[matchNum] = *matches[matchNum].getWinningTeam();				 //move winning team to the next fixture
			matchNum++;
		}

		Fixture(j+1, i / 2, matches).Show();					//registed and show fixture
		if (j > 0)
		{
			Team* temp = t_list;
			t_list = n_list;
			delete[] temp;
		}
		else
			t_list = n_list;
	}
	leadingTeam = &t_list[0];
	onGoing = false;
}
/*		NOT IN USE
const Fixture & League::playFixture()
{
	// TODO: insert return statement here
	return ; 
}
*/
void League::showLeadingTeam() const
{
	/*
	Team temp = teams[0];
	for (int i = 0; i < numberOfTeams; i++)
	{
		if (teams[i] >= temp)
			temp = teams[i];
	}
	//temp.show();
	*/
	if (leadingTeam != nullptr)
		std::cout << leadingTeam->getName() << " With " << leadingTeam->getPoints() << " Points";
}

void League::showLoosingTeam() const
{
	Team temp = teams[0];
	for (int i = 0; i < numberOfTeams; i++)
	{
		if (!(teams[i] >= temp))
			temp = teams[i];
	}
	//temp.show();
	std::cout << temp.getName() << " With " << temp.getPoints() << " Points";
}

void League::showLeadingScorer() const
{
	//TODO::Implement this
	Player* leadingPlayer = teams[0].getLineup()[0]; //  Set default.
	int currGoal = leadingPlayer->getGoalCount();
	for (int i = 0; i < numberOfTeams; ++i)
	{
		Player** currTeam = teams[i].getLineup();
		for (int j = 0; j < LINEUP_MAX_SIZE; ++j)
			if (currGoal < currTeam[j]->getGoalCount())
			{
				leadingPlayer = currTeam[j];
				currGoal = leadingPlayer->getGoalCount();
			}
	}

	std::cout << leadingPlayer->getName() << " of Team " << leadingPlayer->getTeam()->getName() << " With " << leadingPlayer->getGoalCount() << " Goals this league.";
}

void League::showMostActiveReferee() const
{
	Referee temp = referees[0];
	for (int i = 0; i < numberOfReferees; i++)
	{
		if (referees[i].getGamesPlayed() > temp.getGamesPlayed())
			temp = referees[i];
	}
	std::cout << temp.getName() << " With " << temp.getGamesPlayed() << " Games";

}

void League::show() const
{
	std::cout << std::endl << "Welcome to " << name << " League!" << std::endl;
	std::cout << "Currently registered " << numberOfTeams << " teams" << std::endl;

	for (int i = 0; i < numberOfTeams; i++)
	{
		teams[i].show();
	}
	std::cout << std::endl << "Referee list: " << std::endl;
	std::cout.setf(std::ios::left);
	std::cout.width(10);
	std::cout << "Name";
	std::cout.width(5);
	std::cout << "Age";
	std::cout.width(13);
	std::cout << "Nationality";
	std::cout.width(8);
	std::cout << "Games";
	std::cout.width(8);
	std::cout << "Rating" << std::endl;
	for (int i = 0; i < numberOfReferees; i++)
	{
		referees[i].show();
	}


}

bool League::isEnded()
{
	return !onGoing;
}
