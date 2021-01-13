#include "book.h"
using namespace std;

namespace sict {
	void Book::set(const char* lname, const char* fname, const char* title, long long isbn) {
		if (isbn >= min_isbn_value && isbn <= max_isbn_value && isValidIsbn(isbn) && checkDigits(isbn) == 13) {
			strncpy(authlname, lname, max_name_size);
			strncpy(authfname, fname, max_name_size);
			strncpy(bookTitle, title, max_title_size);
			bookIsbn = isbn;
		}
		else {
			strncpy(authlname, "", max_name_size);
			strncpy(authfname, "", max_name_size);
			strncpy(bookTitle, "", max_title_size);
			bookIsbn = -1;
		}
	}
	void Book::set(int year, double cost) {
		if (!isEmpty()) {
			bookYear = year;
			bookPrice = cost;
		}
	}

	bool Book::isEmpty() const{
		if (bookIsbn == -1) {
			return true;
		}
		return false;
	}
	void Book::display(bool multiLine) const{
		
		if (multiLine == false) {
			if (!isEmpty()) {
				cout << "Author: " << authfname << ", " << authlname << endl;
				cout << "Title: " << bookTitle << endl;
				cout << "ISBN-13: " << bookIsbn << endl;
				cout << "Publication Year: " << bookYear << endl;
				cout << "Price: " << bookPrice << endl;
			}
			else {
				cout << "The book object is empty!" << endl;
			}
		}
		else {
			if (isEmpty()) {
				cout << "|";
				cout.width(92);
				cout.setf(ios::left);
				cout << "The book object is empty!";
				cout << "|" << endl;
			}
			else {
				cout << "|";
				cout.width(max_name_size);
				cout.setf(ios::right);
				cout << authfname << "|";
				cout.width(max_name_size);
				cout << authlname << "|";
				cout.width(max_title_size);
				cout.setf(ios::left);
				cout << bookTitle << "|";
				cout.width(13);
				cout.setf(ios::right);
				cout << bookIsbn << "|";
				cout.width(4);
				cout << bookYear << "|";
				cout.width(6);
				cout.precision(4);
				cout << bookPrice << "|" << endl;
			}
		}		
	}

	bool Book::isValidIsbn(long long isbn) {
		int isbnArray[13];
		long long number = isbn;
		int sumOdd = 0, sumEven = 0, total = 0, count = 0;


		for (int i = 12; i >= 0; i--) {
			isbnArray[i] = number % 10;
			number /= 10;
		}
		for (int i = 0; i < 12; i++) {
			if (i == 0 || i % 2 == 0) {
				sumOdd += isbnArray[i];
			}
			else {
				sumEven += isbnArray[i];
			}
		}
		int checkDigit = isbnArray[12];
		sumEven *= 3;
		total = sumOdd + sumEven;
		if (10 - (total % 10) == checkDigit) {
			return true;
		}
		else
			return false;
	}

	int Book::checkDigits(long long isbn) {
		int count = 0;
		while (isbn != 0)
		{
			isbn /= 10;
			++count;
		}
		return count;
	}
}