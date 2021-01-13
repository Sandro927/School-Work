#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include "String.h"


namespace sict {
	int INITIAL = 3;
	String::String(const char * string) {
		if (string == nullptr)
			m_string[0] = '\0';
		else {
			std::strncpy(m_string, string, 3);
			m_string[3] = '\0';
		}
	}

	void String::display(std::ostream & os) const {
		os << m_string;
	}

	std::ostream& operator<<(std::ostream & os, String& s) {
		os << INITIAL++ << ": ";
		s.display(os);
		return os;
	}
}