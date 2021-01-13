#include <iostream>
#include <cstring>
#include <string>
#include "Contact.h"
#pragma warning(disable : 4996)

using namespace std;
namespace sict {

	Contact::Contact() {
		name[0] = '\0';
	}

	Contact::Contact(const char* cname, const long long* cnum, const int count) {
		if (cname != nullptr && cname[0] != '\0') {
			int name_length = (strlen(cname) < 20) ? strlen(cname) : 19;
			strncpy(name, cname, 19);
			name[name_length] = '\0';
		}
		else {
			name[0] = '\0';
		}
		if (cnum != nullptr && count > 0) {
			phoneNum = new long long[count];
			counter = 0;

			for (int i = 0; i < count; i++) {
				if (isValid(cnum[i]) && count > 0) {
					phoneNum[counter] = cnum[i];
					counter += 1;
				}
			}
		}
		else {
			phoneNum = nullptr;
			counter = 0;
		}
	}

	bool Contact::isValid(const long long number) const {
		string numString = to_string(number);
		if (number <= 0 || numString.length() < 11 || numString.length() > 12 || numString[numString.length() - 7] == '0' || numString[numString.length() - 10] == '0')
			return false;
		else
			return true;
	}

	Contact::~Contact() {
		delete[] phoneNum;
		phoneNum = nullptr;
	}

	bool Contact::isEmpty() const {
		bool empty = false;
		if (*name == '\0')
			empty = true;
		return empty;
	}

	void Contact::display() const {
		if (isEmpty())
			cout << "Empty Contact!" << endl;
		else {
			cout << name << endl;
			for (int i = 0; i < counter; i++) {
				string phoneString, countryString,areaString, num1, num2;

				phoneString = to_string(phoneNum[i]);
				if (phoneString.length() == 11) {
					countryString = phoneString.substr(0, 1);
					areaString = phoneString.substr(1, 3);
					num1 = phoneString.substr(4, 3);
					num2 = phoneString.substr(7, 4);
				}
				else if (phoneString.length() == 12) {
					countryString = phoneString.substr(0, 2);
					areaString = phoneString.substr(2, 3);
					num1 = phoneString.substr(5, 3);
					num2 = phoneString.substr(8, 4);
				}
				cout << "(+" << countryString << ") " << areaString << " " << num1 << "-" << num2 << endl;
			}
		}
	}
}