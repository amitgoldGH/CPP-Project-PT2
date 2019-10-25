#include "team.h"
const std::string  Team::getName() const
{
	return name;
}

void Team::show() const
{
	std::cout.fill('*');
	std::cout.width(50);
	std::cout << std::endl << "" << std::endl;
	std::cout.fill(' ');
	std::cout << "\t\t" << name << std::endl;
	std::cout.fill('*');
	std::cout.width(50);
	std::cout << "" << std::endl;
	std::cout.fill(' ');

	std::cout << "Points: " << points
		<< "\n\n" << name << "'s Manager: \n"; manager->show();
	std::cout << "\n" << name << "'s Coach: \n"; coaches->show();

	std::cout << "\nLineup:" << std::endl;
	std::cout.setf(std::ios::left);
	std::cout.width(10);
	std::cout << "Name";
	std::cout.width(5);
	std::cout << "Age";
	std::cout.width(13);
	std::cout << "Nationality";
	std::cout.width(8);
	std::cout << "Attack";
	std::cout.width(8);
	std::cout << "Defense";
	std::cout.width(8);
	std::cout << "G-Keep";
	std::cout.width(8);
	std::cout << "G-Score";
	std::cout.width(8);
	std::cout << "Rate";
	std::cout.width(8);
	std::cout << "Value";
	std::cout.width(15);
	std::cout << "Role";
	std::cout.width(10);
	std::cout << "Team\n" << std::endl;

	for (int i = 0; i < LINEUP_MAX_SIZE; ++i)
		if (this->lineup[i] != nullptr)
		{
			this->lineup[i]->show();
			std::cout << std::endl;
		}

	std::cout << "\nBench players: " << std::endl;
	for (int i = 0; i < LINEUP_MAX_SIZE * BENCH_SIZE_MULTI; ++i)
		if (benchPlayers[i] != nullptr)
		{
			benchPlayers[i]->show();
			std::cout << std::endl;
		}
}

Player** Team::getLineup() const
{
	return (Player**)lineup;
}

int Team::getLineupSize()
{
	return LINEUP_MAX_SIZE;
}

int Team::getPoints()
{
	return points;
}

Team::Team(const std::string name, Manager* manager, Coach* coaches,
	Player** lineup, Player** benchPlayers, int lineup_Size, int bench_Size, int points)
	: name(name), manager(manager), coaches(coaches),
	players_In_Lineup(lineup_Size), players_On_Bench(bench_Size), points(points)
{
	//strncpy_s(Team::name, name, NAME_SIZE); // Copy NAME_SIZE chars from input into name field.
	//Team::name[NAME_SIZE - 1] = '\0'; // In case input was larger than NAME_SIZE adding a null terminator to prevent overflow.

	if (coaches != nullptr)
		coaches->setTeam(this);
	if (manager != nullptr)
		manager->setTeam(this);

	if (lineup == nullptr) // If a lineup wasn't given, make all slots nullptr.
		for (int i = 0; i < LINEUP_MAX_SIZE; ++i)
			Team::lineup[i] = nullptr;
	else // if lineup given, copy all the slots.
		for (int i = 0; i < LINEUP_MAX_SIZE; ++i)
			Team::lineup[i] = lineup[i];

	if (benchPlayers == nullptr)  // If a benchPlayer array wasn't given, allocate one LINEUP_SIZE times 3.
		for (int i = 0; i < LINEUP_MAX_SIZE * BENCH_SIZE_MULTI; ++i)
			Team::benchPlayers[i] = nullptr;
	else // if bench given, copy all the slots.
		for (int i = 0; i < LINEUP_MAX_SIZE * BENCH_SIZE_MULTI; ++i)
			Team::benchPlayers[i] = benchPlayers[i];
}

Team::Team()
{
}

Team::~Team()
{
	// delete[] name; not dynamically assigned -Amit
	// delete[] benchPlayers; not dynamically assigned -Amit
	// delete[] lineup; not dynamically assigned -Amit



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
	if (points != 0)
	{
		this->points += points;
		/*
		if (this->isReady())
		{
			int r;
			for (int i = 0; i < points; ++i)
			{
				r = (rand() % (LINEUP_MAX_SIZE - 1)); // Generates a number [0 , LINEUP_MAX_SIZE - 1]
				std::cout << this->lineup[r]->getName() << " Has scored a goal." << std::endl;
				++(*this->lineup[r]); // Increase the number of goals of a random player from the lineup.
			}
		}
		*/
	}
	return *this;
}

bool Team::operator>=(const Team& otherTeam) const
{
	return this->points >= otherTeam.points;
}

bool Team::isReady() const // Check if lineup is full.
{
	if (players_In_Lineup == LINEUP_MAX_SIZE)
		return true;
	return false;
}