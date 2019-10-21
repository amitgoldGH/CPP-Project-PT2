#pragma warning (disable:4996);
#include "league.h"
League::League(const char* lname, int numberOfTeams, Team * teams, int numberofreferees, Referee * referees, int numberOfFixtures, int playedFixtures, Fixture * fixtures)
{
	//name = new char[strlen(lname) + 1];
	strcpy(this->name, lname);
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
		Team* temp = new Team[numberOfteams + 1];
		for (int i = 0; i < numberOfteams; i++)
		{
			temp[i] = teams[i];
		}
		delete[] teams;	//clear old memory
		temp[numberOfteams] = (Team(*team));
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
	srand(time(0));
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
		Match* matches = new Match[numberOfteams / 2];				//set of matches for fixture
		Team* n_list = new Team[numberOfteams / (2 * (j+1))];		//set of teams for the next fixture, decreces by half for every fixture
		int matchNum = 0, i = 0;
		for (; i < numberOfteams/(j+1); i += 2)
		{
			
			matches[matchNum] = Match(&t_list[i], &t_list[i + 1], &referees[(rand() % numberOfReferees)]); //create match
			n_list[matchNum] = *matches[matchNum].getWinningTeam();				 //move winning team to the next fixture
			matchNum++;
		}

		Fixture(j+1, i / 2, matches).Show();					//registed and show fixture
		t_list = n_list;		
	}
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
	Team temp = teams[0];
	for (int i = 0; i < numberOfteams; i++)
	{
		if (teams[i] >= temp)
			temp = teams[i];
	}
	//temp.show();
	std::cout << temp.getName() << " With " << temp.getPoints() << " Points";
}

void League::showLoosingTeam() const
{
	Team temp = teams[0];
	for (int i = 0; i < numberOfteams; i++)
	{
		if (!(teams[i] >= temp))
			temp = teams[i];
	}
	//temp.show();
	std::cout << temp.getName() << " With " << temp.getPoints() << " Points";
}

void League::showLeadingScorer() const
{
	//TODO:: Implement this
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
	std::cout << "Currently registered " << numberOfteams << " teams" << std::endl;

	for (int i = 0; i < numberOfteams; i++)
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
