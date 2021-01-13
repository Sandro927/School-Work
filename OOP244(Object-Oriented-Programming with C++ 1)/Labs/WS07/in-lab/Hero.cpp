#define _CRT_SECURE_NO_WARNINGS
#include "Hero.h"
#include <cstring>
using namespace std;
namespace sict {
	Hero::Hero() {
		heroName[0] = '\0';
		heroHealth = 0;
		heroStr = 0;
	}
	Hero::Hero(const char* name, int health, int str) {
		if (name != nullptr && name[0] != '\0' && health >= 0 && str >= 0) {
			strncpy(heroName, name, strlen(name));
			heroName[strlen(name)] = '\0';
			heroHealth = health;
			heroStr = str;
		}
		else {
			*this = Hero();
		}
	}
	void Hero::operator-=(int attack) {
		if (attack > 0) {
			heroHealth -= attack;
		}

		if (heroHealth < 0) {
			heroHealth = 0;
		}
	}
	bool Hero::isAlive() const {
		return (heroHealth > 0);

	}
	int Hero::attackStrength() const {
		if (isEmpty())
			return 0;
		else
			return heroStr;
	}
	bool Hero::isEmpty() const {
		return (heroName[0] == '\0' && heroHealth == 0 && heroStr == 0);

	}
	std::ostream& operator <<(std::ostream& os, const Hero& hero) {
		if (hero.isEmpty())
			os << "No hero";
		else
			os << hero.heroName;
		return os;
	}
	const Hero& operator*(const Hero& first, const Hero& second) {
		Hero firstHero = first;
		Hero secondHero = second;
		Hero result;
		int rounds = 0;
		for (int i = 0; i < MAX_ROUNDS && firstHero.isAlive() && secondHero.isAlive(); i++) {
			firstHero -= secondHero.attackStrength();
			secondHero -= firstHero.attackStrength();
			rounds++;
		}
		if (!firstHero.isAlive()) {
			result = secondHero;
			cout << "Ancient Battle! " << first << " vs " << second << " : Winner is " << result << " in " << rounds << " rounds." << endl;
			return second;
		}
		else if (!secondHero.isAlive()) {
			result = firstHero;
			cout << "Ancient Battle! " << first << " vs " << second << " : Winner is " << result << " in " << rounds << " rounds." << endl;
			return first;
		}
		else if (!secondHero.isAlive() && !firstHero.isAlive()) {
			result = firstHero;
			cout << "Ancient Battle! " << first << " vs " << second << " : Winner is " << result << " in " << rounds << " rounds." << endl;
			return first;
		}
		else {
			return first;
		}

	}
}