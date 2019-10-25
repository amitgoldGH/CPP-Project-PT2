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

	std::vector<Player*>::const_iterator lineup_itr = lineup.begin();
	std::vector<Player*>::const_iterator lineup_itrEnd = lineup.end();

	for (; lineup_itr != lineup_itrEnd; ++lineup_itr)
	{
		(*lineup_itr)->show();
		std::cout << std::endl;
	}

	std::cout << "\nBench players: " << std::endl;
	std::vector<Player*>::const_iterator bench_itr = benchPlayers.begin();
	std::vector<Player*>::const_iterator bench_itrEnd = benchPlayers.end();

	for ( ; bench_itr != bench_itrEnd; ++bench_itr)
	{
			(*bench_itr)->show();
			std::cout << std::endl;
	}
}

std::vector<Player*> Team::getLineup() const
{
	return lineup;
}

int Team::getLineupSize()
{
	return lineup.size();
}

int Team::getPoints() const	
{
	return points;
}

Team::Team(std::string name,
	Manager* manager, Coach* coaches, 
	std::vector<Player*> lineup, std::vector<Player*> benchPlayers,
	int points)
	: name(name), manager(manager), coaches(coaches), lineup(lineup), benchPlayers(benchPlayers), points(points)
{
	//strncpy_s(Team::name, name, NAME_SIZE); // Copy NAME_SIZE chars from input into name field.
	//Team::name[NAME_SIZE - 1] = '\0'; // In case input was larger than NAME_SIZE adding a null terminator to prevent overflow.

	if (coaches != nullptr)
		coaches->setTeam(this);
	if (manager != nullptr)
		manager->setTeam(this);
}

Team::Team(){}

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
			if (lineup.size() < LINEUP_MAX_SIZE) // Lineup isn't full.
			{
				lineup.push_back(player);
				player->setTeam(this);
			}
			else if (benchPlayers.size() < LINEUP_MAX_SIZE * BENCH_SIZE_MULTI) // Bench isn't full
			{
				benchPlayers.push_back(player);
				player->setTeam(this);
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
	if (lineup.size() == LINEUP_MAX_SIZE)
		return true;
	return false;
}