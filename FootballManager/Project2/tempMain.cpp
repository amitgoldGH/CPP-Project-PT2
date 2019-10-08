#include "player.h"
#include "match.h"
using namespace std;

int main()
{
	
	Player p1("garoshua", 15, "Canadian", 2, 1, 1, 0, 50000, Player::striker);
	Player p2("saoshua", 18, "American", 1, 1, 2, 0, 60000, Player::defender);
	Player p3("baloshua", 11, "Argentinian", 3, 2, 2, 0, 45000, Player::midlefielder);
	Player p4("karoshua", 21, "Israeli", 2, 3, 5, 0, 20000, Player::goalkeeper);
	Player p5("ponyoshua", 25, "Russian", 6, 1, 2, 0, 15000, Player::striker);
	
	Player g1("kalamari", 28, "Bolshvaki", 1, 6, 2, 0, 31000);
	Player g2("igor", 28, "Russian", 1, 6, 2, 0, 27000);
	Player g3("dov", 28, "Israeli", 1, 6, 2, 0, 66300);
	Player g4("Josh", 28, "American", 1, 6, 2, 0, 71000);
	Player g5("Thomas", 28, "American", 1, 6, 2, 0, 15600);
	
	Manager m1("Manager1", 54, "American", 5); // team nullptr
	Coach c1("Coach1", 31, "Spaniard"); // team nullptr
	Team t1("Argentinada", &m1, &c1); // no lineup and no bench, points = 0;

	Manager m2("Manager2", 33, "Canadian", 7); // team nullptr
	Coach c2("Coach2", 26, "Russian"); // team nullptr
	Team t2("Manchester", &m2, &c2); //no lineup and no bench, points = 0;
	
	Referee ref("Refer-man", 34, "Referistan");
	
// -------------------------------------------------------
	t1.addPlayer(&p1);
	t1.addPlayer(&p2);
	t1.addPlayer(&p3);
	t1.addPlayer(&p4);
	t1.addPlayer(&p5);
	
	t2.addPlayer(&g1);
	t2.addPlayer(&g2);
	t2.addPlayer(&g3);
	t2.addPlayer(&g4);
	t2.addPlayer(&g5);

	cout << "\nAfter adding player: " << endl;
	cout << "Team1: \n";
	t1.show();
	cout << "\n---------------------------------------------------------------------\n";
	cout << "Team2: \n";
	t2.show();
	cout << "\n---------------------------------------------------------------------\n";

// --------------------------------------------------------

	cout << "\nPlaying a match: " << endl;

	Match match(&t1, &t2, &ref);
	cout << endl;
	match.show();
	cout << "\n---------------------------------------------------------------------\n";
	cout << "Team1: \n";
	t1.show();
	cout << "\n---------------------------------------------------------------------\n";
	cout << "Team2: \n";
	t2.show();
	cout << "\n---------------------------------------------------------------------\n";
	return 0;
}