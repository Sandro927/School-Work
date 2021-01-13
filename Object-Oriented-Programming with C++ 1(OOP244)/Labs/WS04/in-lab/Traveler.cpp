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
	}
	// TODO: implement the constructor with 3 parameters here
	Traveler::Traveler(const char *firstName, const char *lastName, const char *address) {
		
		if (firstName != nullptr && firstName != '\0' && lastName != nullptr && lastName != '\0' && address != nullptr && address != '\0') {
			strncpy(fname, firstName, max_name_size);
			strncpy(lname, lastName, max_name_size);
			strncpy(destination, address, max_destination_size);
		}
		else {
			*fname = '\0';
			*lname = '\0';
			*destination = '\0';
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
			cout << fname << " " << lname << " goes to " << destination << endl;
		}
		else {
			cout << "--> Not a valid traveler! <--" << endl;
		}
	}
}