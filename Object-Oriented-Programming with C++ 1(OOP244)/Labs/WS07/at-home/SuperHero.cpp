#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "SuperHero.h"
using namespace std;
namespace sict {
	
	SuperHero::SuperHero() : Hero() {
		superAtk = 0;
		superDef = 0;
	}

	SuperHero::SuperHero(const char* name, int health, int str, int bonus, int def) : Hero(name, health, str) {
		superAtk = bonus;
		superDef = def;
	}
	
	int SuperHero::attackStrength() const {
		if (superAtk > 0) {
			return Hero::attackStrength() + superAtk;
		}
		else
			return 0;
	 }

	int SuperHero::defend() const {
		if (superAtk > 0) {
			return superDef;
		}
		else
			return 0;
	}
	
	const SuperHero& operator*(const SuperHero& first, const SuperHero& second) {
		
		SuperHero firstHero = first;
		SuperHero secondHero = second;
		SuperHero winner;

		int counter = 0;

		for (int i = 0; i < MAX_ROUNDS && firstHero.isAlive() && secondHero.isAlive(); i++) {
			firstHero -= (secondHero.attackStrength() - firstHero.defend());
			secondHero -= (firstHero.attackStrength() - secondHero.defend());
			counter++;
		}
		if (!firstHero.isAlive()) {
			winner = secondHero;
			cout << "Super Fight! " << first << " vs " << second << " : Winner is " << winner << " in " << counter << " rounds." << endl;
			return second;
		}
		else if (!secondHero.isAlive()) {
			winner = firstHero;
			cout << "Super Fight! " << first << " vs " << second << " : Winner is " << winner << " in " << counter << " rounds." << endl;
			return first;
		}
		else if (!secondHero.isAlive() && !firstHero.isAlive()) {
			winner = firstHero;
			cout << "Super Fight! " << first << " vs " << second << " : Winner is " << winner << " in " << counter << " rounds." << endl;
			return first;
		}
		else {
			return first;
		}
	}

}