#pragma once
#include <iostream>
#include "Hero.h"

using namespace std;
namespace sict {
	class SuperHero : public Hero {
	private:
		int superAtk;
		int superDef;
	public:
		SuperHero();
		SuperHero(const char* name, int health, int str, int bonus, int def);
		int attackStrength() const;
		int defend() const;
	};
	const SuperHero& operator*(const SuperHero& first, const SuperHero& second);
}


