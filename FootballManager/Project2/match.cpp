#include "match.h"

Match::Match()
{
	//srand(time(0));	//moved for testing
	resultHome = 0;
	resultAway = 0;

}

Match::Match(Team* homeTeam, Team* awayTeam, Referee* referee)
	: homeTeam(homeTeam), awayTeam(awayTeam), referee(referee)
{
	//srand(time(0));	//moved for testing
	resultHome = 0;
	resultAway = 0;
	++(*referee);

	this->playMatch();
	if (resultHome > resultAway) // Home wins
		(*homeTeam) += 3;
	else if (resultHome < resultAway) // Away wins
		(*awayTeam) += 3;
	else // Draw
	{
		(*awayTeam) += 1;
		(*homeTeam) += 1;
	}

}

void Match::playMatch()
{

	if (homeTeam != nullptr && awayTeam != nullptr)
		if (homeTeam->isReady() && awayTeam->isReady())
		{
			int r=0, scoreIndex=0;
			std::vector<Player*> currLineup;
			int totalScore = (rand() % MAX_GOALS_IN_MATCH); // total goals in this match
			while (totalScore > 0)
			{
				scoreIndex = (rand() % (LINEUP_MAX_SIZE - 1)); // Generates a number [0 , LINEUP_MAX_SIZE - 1]
				r = (rand() % 10) + 1;
				if (r < 6)
				{
					currLineup = homeTeam->getLineup();
					++(resultHome);
				}
				else
				{
					currLineup = awayTeam->getLineup();
					++(resultAway);
				}

				//std::cout << currLineup[scoreIndex]->getName() << " of " << currLineup[scoreIndex]->getTeam()->getName() << " Has scored a goal." << std::endl;
				++(*(currLineup[scoreIndex]));
				--totalScore;
			}
		}
}

Team * Match::getWinningTeam()
{
	if (resultHome > resultAway) // Home wins
		return homeTeam;
	else if (resultHome < resultAway) // Away wins
		return awayTeam;
	else // Draw
	{
		return homeTeam; //TODO: fix to return team with most points later
	}
}

Match::~Match()
{

}

void Match::show() const
{
	std::cout << homeTeam->getName() << " vs " << awayTeam->getName();
	std::cout << " Endded with score " << resultHome << " - " << resultAway; 
	std::cout << "   Referee: " << referee->getName() << std::endl;
}
