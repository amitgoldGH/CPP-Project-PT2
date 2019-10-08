#include "team.h"
const char* Team::getName() const
{
	return name;
}

Team::Team(const char name[NAME_SIZE], Manager* manager, Coach* coaches,
	Player** lineup, Player** benchPlayers, int lineup_Size, int bench_Size, int points) 
	: manager(manager), coaches(coaches), lineup(lineup), benchPlayers(benchPlayers),
	players_In_Lineup(lineup_Size), players_On_Bench(bench_Size), points(points)
{
	strncpy_s(Team::name, name, NAME_SIZE); // Copy NAME_SIZE chars from input into name field.
	Team::name[NAME_SIZE - 1] = '\0'; // In case input was larger than NAME_SIZE adding a null terminator to prevent overflow.
	
	if (Team::lineup == nullptr) // If a lineup wasn't given, dynamically allocate one of size LINEUP_SIZE
		lineup[LINEUP_MAX_SIZE];
	if (Team::benchPlayers == nullptr)  // If a benchPlayer array wasn't given, allocate one LINEUP_SIZE times 3.
		benchPlayers[LINEUP_MAX_SIZE * BENCH_SIZE_MULTI];
}

Team::~Team() 
{
	delete[] name;
	/*
	delete[] benchPlayers;
	delete[] lineup;
	*/
}

void Team::setManager(Manager* manager)
{
	if (this->manager != manager)
	{
		if (this->manager != nullptr)
			this->manager->setTeam(nullptr);
		this->manager = manager;
	}
}

void Team::addCoach(Coach* coach)
{
	if (coaches != coach)
	{
		if (coaches != nullptr)
			coaches->setTeam(nullptr);
		coaches = coach;
	}
}

void Team::addPlayer(Player* player)
{

}

const Team& Team::operator+=(int points)
{
	Team::points += points;
	return *this;
}

bool Team::operator>=(const Team& otherTeam) const
{
	return this->points >= otherTeam.points;
}
