#pragma once
#ifndef SICT_CONTACT_H
#define SICT_CONTACT_H
#include <iostream>
#define max_name_size 16

using namespace std;
namespace sict {
	
	class Contact {
	private:
		char name[max_name_size];
		long long *phoneNum = nullptr;
		int counter;

	public:
		Contact();
		Contact(const char *name, const long long *num, int count);
		~Contact();
		bool isEmpty() const;
		void display() const;
		bool isValid(const long long number) const;
	};
}

#endif 
