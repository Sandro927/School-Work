#ifndef SICT_HERO_H
#define SICT_HERO_H
#include <iostream>
#define MAX_ROUNDS 100

namespace sict {
	class Hero {
		char heroName[40];
		int heroHealth;
		int heroStr;
	public:
		Hero();
		Hero(const char* name, int health, int str);
		void operator-=(int attack);
		bool isAlive() const;
		int attackStrength() const;
		bool isEmpty() const;
		friend std::ostream& operator <<(std::ostream& os, const Hero& hero);
	};

	const Hero& operator*(const Hero& first, const Hero& second);
}

#endif 