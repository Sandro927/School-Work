#include "book.h"
using namespace std;

namespace sict {
	void Book::set(const char* lname, const char* fname, const char* title, long long isbn) {
		if (isbn >= min_isbn_value && isbn <= max_isbn_value) {
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
	bool Book::isEmpty() const{
		if (bookIsbn == -1) {
			return true;
		}
		return false;
	}
	void Book::display() const{
		if (!isEmpty()) {
			cout << "Author: " << authfname << ", " << authlname << endl;
			cout << "Title: " << bookTitle << endl;
			cout << "ISBN-13: " << bookIsbn << endl;
		}
		else {
			cout << "The book object is empty!" << endl;
		}
	}

	

}