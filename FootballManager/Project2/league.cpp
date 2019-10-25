#pragma warning (disable:4996)
#include "league.h"
League::League(std::string lname, int numberOfTeams, Team * teams, int numberOfReferees, Referee * referees, int numberOfFixtures, int playedFixtures, Fixture * fixtures) : name(lname) {}

void League::addTeam(Team * team)
{
	teams.push_back(*team);
}


void League::setNumberOfReferees(int numberOfReferees)
{
}

void League::addReferee(Referee* referee)
{
	referees.push_back(*referee);
}


/***
calculate number of fixtures according to number of registered teams
calculate number of matches for each fixture
assign teams in matches and put into fixtures, winning team move of to the next fixture
***/
void League::startSeason()
{
	//Reset every player's current league score to 0, used to see how many goals scored in this specific league.
	for (Team t : teams)
	{

		//Player** curr_Lineup = t.getLineup();
		std::vector<Player*> cur_Lineup = t.getLineup();
		std::vector<Player*>::const_iterator cur_itr = cur_Lineup.begin();
		std::vector<Player*>::const_iterator cur_itrEnd = cur_Lineup.end();
		for (; cur_itr != cur_itrEnd ; ++cur_itr )
		{
			(*cur_itr)->setLeagueGoal(0);
		}
	}
	   
	onGoing = true;

	std::vector<Team> t_list = teams;
	//calculate number of fixtures
	for(int i = teams.size(); i > 1; i /= 2)
	{
		numberOfFixtures++;
	}
	
	//divide teams to fixtures and begin matches
	for (int j = 0; j < numberOfFixtures; j++)
	{
		std::vector<Match> matches;
		std::vector<Team> n_list;
		//n_list.capacity = teams.size() / (2 * (j+1));		//set of teams for the next fixture, decreces by half for every fixture
		int matchNum = 0, i = 0;
		for (; i < teams.size()/(j+1); i += 2)
		{
			matches.push_back(Match(&t_list[i], &t_list[i + 1], &referees[(rand() % referees.size())])); //create match
			n_list.push_back(*matches[matchNum].getWinningTeam());				 //move winning team to the next fixture
			matchNum++;
		}

		Fixture(j+1, matches).Show();					//registed and show fixture
		if (j > 0)
		{
			std::vector<Team> temp = t_list;
			t_list = n_list;
			//delete[] temp;
		}
		else
			t_list = n_list;
	}
	leadingTeam = t_list.front();
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
		std::cout << leadingTeam.getName() << " With " << leadingTeam.getPoints() << " Points";
}

void League::showLoosingTeam() const
{
	Team temp = teams.front();
	for (Team t : teams)
	{
		if (!(t >= temp))
			temp = t;
	}

	std::cout << temp.getName() << " With " << temp.getPoints() << " Points";
}

void League::showLeadingScorer() const
{
	//TODO::Implement this
	Player* leadingPlayer = teams[0].getLineup()[0]; //  Set default.
	for (Team t : teams)
	{
		std::vector<Player*> currTeam = t.getLineup();
		for (Player* p : currTeam)
			if ((*p) >= (*leadingPlayer))
				leadingPlayer = p;

	}

	std::cout << leadingPlayer->getName() << " of Team " << leadingPlayer->getTeam()->getName() << " With " << leadingPlayer->getLeagueGoal() << " Goals this league.";
}

void League::showMostActiveReferee() const
{
	Referee temp = referees.front();
	for (Referee r : referees)
	{
		if (r.getGamesPlayed() >= temp.getGamesPlayed())
			temp = r;
	}

	std::cout << temp.getName() << " With " << temp.getGamesPlayed() << " Games";

}

void League::show() const
{
	std::cout << std::endl << "Welcome to " << name << " League!" << std::endl;
	std::cout << "Currently registered " << teams.size() << " teams" << std::endl;

	for (Team t : teams)
		t.show();
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
	for (int i = 0; i < referees.size(); i++)
	{
		referees[i].show();
	}


}

bool League::isEnded()
{
	return !onGoing;
}
