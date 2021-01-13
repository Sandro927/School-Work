
#ifndef SICT_TEXT_H
#define SICT_TEXT_H

#include <string>
#include <iostream>
#include <utility>

namespace sict {
	
	class Text {
		static int count;
		std::string* p_strings;
	public:
		Text();
		Text(const char*);
		Text(const Text&);
		Text(Text&& src);
		Text& operator=(const Text& obj);
		Text& operator=(Text&& src);
		~Text();
		size_t size() const;
	};
}

#endif 