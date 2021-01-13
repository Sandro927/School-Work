/*Alejandro Mandala 036870111
amandala@myseneca.ca
Workshop 2 in lab
*/
#ifndef SICT_TEXT_H
#define SICT_TEXT_H

#include <string>
#include <iostream>

namespace sict {
	
	class Text {
		static int count;
		std::string* p_strings;
	public:
		Text();
		Text(const char*);
		Text(const Text&);
		Text& operator=(const Text&);
		~Text();
		size_t size() const;
	};
}

#endif 