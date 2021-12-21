// characterGen.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <cmath>
#include <string>
#include <time.h>
#pragma warning(disable: 4996)
using namespace std;

// Class for character generator
class chGenerator {
	private: 

		string cName, password, inv1, inv2, inv3, inv4;

		int experience, position1, position2;		

// constructors for each aspect of each character
	public:

		chGenerator () {
			cName = genName();

			password = genPw();

			experience = genExp();

			position1 = genCoord1();

			position2 = genCoord2();

			inv1 = genInventory();

			inv2 = genInventory();

			inv3 = genInventory();

			inv4 = genInventory();

			setName(cName);
			setPass(password);
			setInventory(inv1, inv2, inv3, inv4);
			setExp(experience);
			setPosition(position1, position2);
		}
	
		void setName(string nm) {	cName = nm; }

		string getName() {	return cName; }

		void setPass(string pw) { password = pw; }
		
		string getPass() { return password; }

		void setExp(int exp) { experience = exp; }

		int getExp() { return experience; }

		void setPosition(int p1, int p2) { position1 = p1;
		position2 = p2; }

		int getPosition1() { return position1; }

		int getPosition2() { return position2; }

		void setInventory(string item1, string item2, string item3, string item4) { 
		inv1 = item1;
		inv2 = item2;
		inv3 = item3;
		inv4 = item4;		};

		string getInventory() { return (inv1 + "\n" + inv2 + "\n" + inv3 + "\n" + inv4);	}

		// randomly selects name from list. Could be randomly pulled from a database later for more options
		string genName() {
			string name[6] = { "Nematocyst", "Caemeath", "Noraerel", "Altalor", "Ithithas", "Amortalor" };

			string cName;

			cName = name[rand() % 5 + 0];

			return cName;
		}
		// generates passwords for accounts. Also could be randomly generated using and rng with set parameters
		string genPw() {
			string pw[6] = { "lightwing", "brasseeker", "warmsworn", "phoenixflight", "solarshadow", "emberflight" };

			string password;

			password = pw[rand() % 5 + 0];

			return password;
		}
		// will end up sending four random items for inventory
		string genInventory() {

			string inventory[24] = { "potion", "ether", "food", "debuff potion", "smoke screen", "sword", "staff", "shield",
										"mace", "shortbow", "longbow", "firebomb", "dagger", "mithril armor", "leather armor",
										"sneaking boots", "thief's gloves", "decoy doll", "magic lens", "panacea", "cloak",
										"gauntlets", "bag of holding", "egress potion" };
			string inv;

			inv = inventory[rand() % 23 + 0];

			return inv;
		}
	// randomly generates EXP up to 10k
		int genExp() {
			int experience;

			experience = rand() % 9999 + 1;

			return experience;
		}
		// X coordinate on map
		int genCoord1() {
			int pos1;

			pos1 = rand() % 2000 + 1;

			return pos1;
		}
		// Y coordinate on map
		int genCoord2() {
			int pos2;

			pos2 = rand() % 2000 + 1;

			return pos2;
		}

		void printCharacter();  // prints character out ot user
};



int main()
{	
	int repeat;
	srand(time(NULL)); 

	cout << "This program generates three player objects and displays them.\n";
	do {
		for (int i = 1; i <= 3; i++) {  // loops to create new charactereach time with gen pointer
			chGenerator *gen = new chGenerator;

			gen->printCharacter();
		}

		cout << "Try again? (yes=1 no=0)"; // allows option to loop or exit
		cin >> repeat;
	} while (repeat == 1);

	system("PAUSE");

	return(0);
}

void chGenerator::printCharacter() {  // layout for output print
	cout << "Player Info - \n" <<
		"Name: " << getName() << "\n" <<
		"Password : " << getPass() << "\n" <<
		"Experience : " << getExp() << "\n" <<
		"Inventory : \n" << getInventory() << "\n" <<
		"Position : " << getPosition1() << ", " << getPosition2() << "\n" <<
		"\n";
}



