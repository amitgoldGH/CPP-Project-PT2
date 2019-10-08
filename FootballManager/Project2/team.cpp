#include "team.h"
const char* Team::getName() const
{
	return name;
}

void Team::show() const
{
	std::cout << "Team Name: " << name 
		<< "\nTeam Manager: \n"; manager->show();
	std::cout << "\nTeam Coach: \n"; coaches->show();
	
	std::cout << "\nLineup: \n" << std::endl;
	for (int i = 0; i < LINEUP_MAX_SIZE; ++i)
		if (this->lineup[i] != nullptr)
		{
			this->lineup[i]->show();
			std::cout << std::endl;
		}
	
	std::cout << "\nBench bois: " << std::endl;
	for (int i = 0; i < LINEUP_MAX_SIZE * BENCH_SIZE_MULTI; ++i)
		if (benchPlayers[i] != nullptr)
		{
			benchPlayers[i]->show();
			std::cout << std::endl;
		}
}

Team::Team(const char name[NAME_SIZE], Manager* manager, Coach* coaches,
	Player** lineup, Player** benchPlayers, int lineup_Size, int bench_Size, int points) 
	: manager(manager), coaches(coaches), lineup(lineup), benchPlayers(benchPlayers),
	players_In_Lineup(lineup_Size), players_On_Bench(bench_Size), points(points)
{
	strncpy_s(Team::name, name, NAME_SIZE); // Copy NAME_SIZE chars from input into name field.
	Team::name[NAME_SIZE - 1] = '\0'; // In case input was larger than NAME_SIZE adding a null terminator to prevent overflow.
	
	if (coaches != nullptr)
		coaches->setTeam(this);
	if (manager != nullptr)
		manager->setTeam(this);

	if (Team::lineup == nullptr) // If a lineup wasn't given, dynamically allocate one of size LINEUP_SIZE
	{
		Team::lineup = new Player*[LINEUP_MAX_SIZE];
		for (int i = 0; i < LINEUP_MAX_SIZE; ++i)
			Team::lineup[i] = nullptr;
	}
	if (Team::benchPlayers == nullptr)  // If a benchPlayer array wasn't given, allocate one LINEUP_SIZE times 3.
	{
		Team::benchPlayers = new Player*[LINEUP_MAX_SIZE * BENCH_SIZE_MULTI];
		for (int i = 0; i < LINEUP_MAX_SIZE * BENCH_SIZE_MULTI; ++i)
			Team::benchPlayers[i] = nullptr;
	}
}

Team::~Team() 
{
	// delete[] name; not dynamically assigned -Amit
	delete[] benchPlayers;
	delete[] lineup;

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
	if (player != nullptr) // Player actually exists
		if (player->getTeam() != this)
		{
			if (players_In_Lineup < LINEUP_MAX_SIZE) // Lineup isn't full.
			{
				for (int i = 0; i < LINEUP_MAX_SIZE; ++i)
					if (lineup[i] == nullptr)
					{
						lineup[i] = player;
						lineup[i]->setTeam(this);
						++players_In_Lineup;
						break;
					}
			}
			else if (players_On_Bench < LINEUP_MAX_SIZE * BENCH_SIZE_MULTI) // Bench isn't full
			{
				for (int i = 0; i < LINEUP_MAX_SIZE * BENCH_SIZE_MULTI; ++i)
					if (benchPlayers[i] == nullptr)
					{
						benchPlayers[i] = player;
						benchPlayers[i]->setTeam(this);
						++players_On_Bench;
						break;
					}
			}
		}

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
