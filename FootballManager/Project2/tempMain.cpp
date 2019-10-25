#include "player.h"
#include "match.h"
#include "league.h"
using namespace std;

void main()
{
	srand(time(0)); // Solved the issue with the same point results

	Player a1("garoshua", 15, "Canadian", 2, 1, 1, 0, 50000, Player::striker);
	Player a2("saoshua", 18, "American", 1, 1, 2, 0, 60000, Player::defender);
	Player a3("baloshua", 11, "Argentinian", 3, 2, 2, 0, 45000, Player::midlefielder);
	Player a4("karoshua", 21, "Israeli", 2, 3, 5, 0, 20000, Player::goalkeeper);
	Player a5("ponyoshua", 25, "Russian", 6, 1, 2, 0, 15000, Player::striker);
	
	Player b1("kalamari", 28, "Bolshvaki", 1, 6, 2, 0, 31000, Player::striker);
	Player b2("igor", 28, "Russian", 1, 6, 2, 0, 27000, Player::striker);
	Player b3("dov", 28, "Israeli", 1, 6, 2, 0, 66300, Player::midlefielder);
	Player b4("Josh", 28, "American", 1, 6, 2, 0, 71000, Player::midlefielder);
	Player b5("Thomas", 28, "American", 1, 6, 2, 0, 15600, Player::goalkeeper);

	Player d1("d1", 15, "Canadian", 2, 1, 1, 0, 50000, Player::striker);
	Player d2("d2", 18, "American", 1, 1, 2, 0, 60000, Player::defender);
	Player d3("d3", 11, "Argentinian", 3, 2, 2, 0, 45000, Player::midlefielder);
	Player d4("d4", 21, "Israeli", 2, 3, 5, 0, 20000, Player::goalkeeper);
	Player d5("d5", 25, "Russian", 6, 1, 2, 0, 15000, Player::striker);
	
	Player e1("e1", 15, "Canadian", 2, 1, 1, 0, 50000, Player::striker);
	Player e2("e2", 18, "Ameriean", 1, 1, 2, 0, 60000, Player::defender);
	Player e3("e3", 11, "Argentinian", 3, 2, 2, 0, 45000, Player::midlefielder);
	Player e4("e4", 21, "Israeli", 2, 3, 5, 0, 20000, Player::goalkeeper);
	Player e5("e5", 25, "Russian", 6, 1, 2, 0, 15000, Player::striker);


	Manager m1("Manager1", 54, "American", 5); // team nullptr
	Coach c1("Coach1", 31, "Spaniard"); // team nullptr
	Team t1("Argentina", &m1, &c1); // no lineup and no bench, points = 0;

	Manager m2("Manager2", 33, "Canadian", 7); // team nullptr
	Coach c2("Coach2", 26, "Russian"); // team nullptr
	Team t2("Manchester", &m2, &c2); //no lineup and no bench, points = 0;
	
	Manager m3("Manager3", 33, "Canadian", 7); // team nullptr
	Coach c3("Coach3", 26, "Russian"); // team nullptr
	Team t3("Avengers", &m3, &c3); //no lineup and no bench, points = 0;

	Manager m4("Manager4", 33, "Canadian", 7); // team nullptr
	Coach c4("Coach4", 26, "Russian"); // team nullptr
	Team t4("Justice League", &m4, &c4); //no lineup and no bench, points = 0;


	Referee ref1("Refer-man", 34, "Referistan");
	Referee ref2("Thanos", 750, "ALarsian");
	Referee ref3("Talos", 9999, "Imperial");

	
// -------------------------------------------------------
	t1.addPlayer(&a1);
	t1.addPlayer(&a2);
	t1.addPlayer(&a3);
	t1.addPlayer(&a4);
	t1.addPlayer(&a5);
	
	t2.addPlayer(&b1);
	t2.addPlayer(&b2);
	t2.addPlayer(&b3);
	t2.addPlayer(&b4);
	t2.addPlayer(&b5);


	t3.addPlayer(&e1);
	t3.addPlayer(&e2);
	t3.addPlayer(&e3);
	t3.addPlayer(&e4);
	t3.addPlayer(&e5);

	t4.addPlayer(&d1);
	t4.addPlayer(&d2);
	t4.addPlayer(&d3);
	t4.addPlayer(&d4);
	t4.addPlayer(&d5);
	/*
	cout << "\nAfter adding player: " << endl;
	cout << "Team1: \n";
	t1.show();
	cout << "\n---------------------------------------------------------------------\n";
	cout << "Team2: \n";
	t2.show();
	cout << "\n---------------------------------------------------------------------\n";
	*/
// --------------------------------------------------------


	League l("Test");
	l.addTeam(&t1);
	l.addTeam(&t2);
	l.addTeam(&t3);
	l.addTeam(&t4);
	/*
	l.addTeam(&t1);	//dup for testing
	l.addTeam(&t2);	//dup for testing
	l.addTeam(&t3);	//dup for testing
	l.addTeam(&t4);	//dup for testing
	*/
	l.addReferee(&ref1);
	l.addReferee(&ref2);
	l.addReferee(&ref3);
	l.show();

	std::cout << "***********************************\n\tStarting\n***********************************" << std::endl;
 	l.startSeason();
	std::cout << "***********************************\n\tEnding\n***********************************" << std::endl;
	
	std::cout << "\nWinning team is: "; l.showLeadingTeam();
	std::cout << "\nLeading player is: "; l.showLeadingScorer();
	std::cout << "\nMost active referee is: "; l.showMostActiveReferee();
	std::cout << "\nLosing team is: "; l.showLoosingTeam();
	
	
	l.show();	//print to show league results
	cout << endl;
}