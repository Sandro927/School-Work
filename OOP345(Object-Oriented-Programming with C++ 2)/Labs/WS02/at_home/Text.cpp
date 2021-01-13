#include <fstream>
#include <utility>
#include "Text.h"

namespace sict {
	int Text::count = 0;

	Text::Text() : p_strings(nullptr) {	}

	Text::Text(const char * filename) {
		std::string buffer = {};
		std::ifstream file;
		file.open(filename);
				
		if (file.is_open()) {
			while (std::getline(file, buffer))
				++count;
		}

		p_strings = new std::string[count];
		int i = 0;
		std::string line = {};

		if (std::getline(file, line))
			p_strings[i] = line;
	}

	Text::Text(const Text& obj) {	*this = obj; }

	Text::Text(Text && src) {
		p_strings = src.p_strings;
		src.p_strings = nullptr;
	}

	Text & Text::operator=(const Text &obj) {
		if (this != &obj) {
		count = obj.count;
			p_strings = new std::string[count];
			for (size_t i = 0; i < (size_t)count; i++)
				p_strings[i] = obj.p_strings[i];
		}
		return *this;
	}

	Text & Text::operator=(Text &&src) {
		if (this != &src) {
			delete[] p_strings;
			p_strings = src.p_strings;
			src.p_strings = nullptr;
			
		}
		return *this;
	}

	Text::~Text() {
		delete[] p_strings;
		p_strings = nullptr;
	}
	
	size_t Text::size() const { return count; }
}
