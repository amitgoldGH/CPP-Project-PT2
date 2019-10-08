#include "match.h"


Match::Match(Team* homeTeam, Team* awayTeam, Referee* referee)
	: homeTeam(homeTeam), awayTeam(awayTeam), referee(referee)
{
	result[0] = 0;
	result[1] = 0;
	++(*referee);
	this->playMatch();
}

void Match::playMatch()
{
	if (homeTeam != nullptr && awayTeam != nullptr)
		if (homeTeam->isReady() && awayTeam->isReady())
		{
			srand(time(0));

			int totalScore = (rand() % MAX_GOALS_IN_MATCH); // total goals in this match
			int split = (rand() % totalScore); // How many points out of total score hometeam gets

			(*homeTeam) += split;
			(*awayTeam) += totalScore - split;
			result[0] += split;
			result[1] += totalScore - split;
		}
}

Match::~Match()
{
}

void Match::show() const
{
	std::cout << homeTeam->getName() << " vs " << awayTeam->getName() << std::endl;
	std::cout << "Score: " << result[0] << " - " << result[1] << std::endl;
	std::cout << "Referee: " << std::endl;
	referee->show();
}
