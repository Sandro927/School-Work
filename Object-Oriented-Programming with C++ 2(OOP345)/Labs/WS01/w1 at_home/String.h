#pragma once
#ifndef _SICT_STRING_H
#define _SICT_STRING_H
#include <iostream>

namespace sict
{
	class String
	{
		char *m_string;	
	public:
		String(const char*);
		void display(std::ostream&) const;
	};

	std::ostream& operator<<(std::ostream&, String&);

}

#endif 