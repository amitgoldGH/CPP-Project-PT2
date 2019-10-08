#include "player.h"

Player::Player(const char * name, int age, const char* nationality,
	int attack, int defence, int goalkeeping, int goalScored, int value,
	Role role, Team* currentTeam)
	: Person(name, age, nationality), attack(attack), defence(defence),
	goalkeeping(goalkeeping), goalScored(goalScored), value(value),
	role(role), currentTeam(currentTeam) {}

Player::Player(const Player& other) 
	: Person(other.name, other.age, other.nationality),
	attack(other.attack), defence(other.defence),
	goalkeeping(other.goalkeeping), goalScored(other.goalScored), value(other.value),
	role(other.role), currentTeam(other.currentTeam) {}

Player::~Player() {}

void Player::show() const
{
	Person::show(); // Call show method of parent (Person)
	std::cout << "Attack: " << attack << "\nDefence: " << defence << "\nGoal-Keeping: " << goalkeeping
		<< "\nGoal-Scored: " << goalScored << "\nRate: " << getRate() << "\nValue: " << value << "\nRole: " << Roles[role]
		<< "\nTeam: " << ((currentTeam == nullptr) ? "None" : currentTeam->getName()) << std::endl;

}

double Player::getRate() const
{
	double res = (0.0 + attack + defence + goalkeeping + goalScored) / 4;
	return res;
}

void Player::setTeam(Team* team)
{
	currentTeam = team;
}

Player Player::operator++(int) // PostFix "X++"
{
	Player temp(*this);
	++goalScored;
	return temp;
}
const Player& Player::operator++() // Prefix "++X"
{
	++goalScored;
	return *this;
}

bool Player::operator>=(const Player& player) const
{
	return goalScored >= player.goalScored;
}

const Team* Player::getTeam()
{
	return this->currentTeam;
}

const char* Player::getName()
{
	return this->name;
}
