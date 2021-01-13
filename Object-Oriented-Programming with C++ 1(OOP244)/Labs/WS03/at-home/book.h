#pragma once
#ifndef SICT_BOOK_H
#define SICT_BOOK_H
#include <iostream>
#define max_title_size 32
#define max_name_size 16

using namespace std;

namespace sict {
	const long long min_isbn_value = 1000000000000;
	const long long max_isbn_value = 9999999999999;

	class Book {
	private:
		char authlname[max_name_size];
		char authfname[max_name_size];
		long long bookIsbn;
		char bookTitle[max_title_size];
		int bookYear;
		double bookPrice;
	
	public:
		void set(const char* lname, const char* fname, const char* title, long long isbn);
		void set(int year, double cost);
		bool isEmpty() const;
		void display(bool multiLine = false) const;
		bool isValidIsbn(long long isbn);
		int checkDigits(long long isbn);
	};

}

#endif