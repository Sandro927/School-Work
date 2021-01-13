// TODO: add file header comments here

// TODO: add your headers here
#include <iostream>
#include <cstring>
#include "Traveler.h"
#pragma warning(disable : 4996)

// TODO: continue your namespace here
using namespace std;
namespace sict {
	// TODO: implement the default constructor here
	Traveler::Traveler() {
		*fname = '\0';
		*lname = '\0';
		*destination = '\0';
		year = -1;
		month = -1;
		day = -1;
	}
	// TODO: implement the constructor with 3 parameters here
	Traveler::Traveler(const char *firstName, const char *lastName, const char *address) {
		
		if (firstName != nullptr && firstName != '\0' && lastName != nullptr && lastName != '\0' && address != nullptr && address != '\0') {
			strncpy(fname, firstName, max_name_size);
			strncpy(lname, lastName, max_name_size);
			strncpy(destination, address, max_destination_size);
			year = 2019;
			month = 7;
			day = 1;
		}

		else {
			*fname = '\0';
			*lname = '\0';
			*destination = '\0';
			year = -1;
			month = -1;
			day = -1;

		}
			
	



	}
	Traveler::Traveler(const char * firstName, const char * lastName, const char * address, int tYear, int tMonth, int tDay) {
		int flag = 1;
		if (firstName != nullptr && firstName != '\0' && lastName != nullptr && lastName != '\0' && address != nullptr && address != '\0') {
			if (tYear >= 2019 && tYear <= 2022) {
				if (tMonth >= 1 && tMonth <= 12) {
					if (tDay >= 1 && tDay <= 31) {
						strncpy(fname, firstName, max_name_size);
						strncpy(lname, lastName, max_name_size);
						strncpy(destination, address, max_destination_size);
						year = tYear;
						month = tMonth;
						day = tDay;
						flag = 0;
					}
				}
			}
		}

		if (flag) {
			*fname = '\0';
			*lname = '\0';
			*destination = '\0';
			year = -1;
			month = -1;
			day = -1;
		}
	}

	// TODO: implement isEmpty query here
	bool Traveler::isEmpty() const {
		bool flag = true;
		if (*fname != '\0' && fname != nullptr) {
			if (*lname != '\0' && lname != nullptr) {
				if (*destination != '\0' && destination != nullptr) {
					flag = false;
				}
			}
		}
		return flag;
	}
	// TODO: implement display query here
	void Traveler::display() const {
		if (!isEmpty()) {
			cout << fname << " " << lname << " goes to " << destination << " on " << year << "/" << month << "/" << day << endl;
		}
		else {
			cout << "--> Not a valid traveler! <--" << endl;
		}
	}
	const char * Traveler::name() const {
		return this->fname;
	}

	bool Traveler::canTravelWith(const Traveler &traveler) const {
		bool matchFlag = false;
		if ((strcmp(traveler.destination, destination)) == 0) {
			if(traveler.year == year && traveler.month == month && traveler.day == day)
				matchFlag = true;
		}
		return matchFlag;
	}
}