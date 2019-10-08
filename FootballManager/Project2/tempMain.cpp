#include "player.h"

using namespace std;

int main()
{
	
	Player p1("garoshua", 15, "Canadian", 2, 1, 1, 1, 50000, Player::striker);
	Player p2("saoshua", 18, "American", 1, 1, 2, 1, 60000, Player::defender);
	Player p3("baloshua", 11, "Argentinian", 3, 2, 2, 1, 45000, Player::midlefielder);
	Player p4("karoshua", 21, "Israeli", 2, 3, 5, 1, 20000, Player::goalkeeper);
	Player p5("ponyoshua", 25, "Russian", 6, 1, 2, 1, 15000, Player::striker);
	Player p6("kalamari", 28, "Bolshvaki", 1, 6, 2, 1, 31000);
	Manager m("Managerial Manager", 54, "American", 5); // team nullptr
	Coach c("Coachy Coacher", 31, "Spaniard"); // team nullptr
	Team t("Argentinada", &m, &c); // no lineup and no bench, points = 0;

	cout << "Before adding: " << endl;
	
	cout << "Team: \n";
	t.show();
	cout << endl;

// -------------------------------------------------------
	t.addPlayer(&p1);
	t.addPlayer(&p2);
	t.addPlayer(&p3);
	t.addPlayer(&p4);
	t.addPlayer(&p5);
	t.addPlayer(&p6);

	cout << "\nAfter adding player: " << endl;
	t.show();
	return 0;
}