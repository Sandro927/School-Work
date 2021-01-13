// TODO: insert header files
#include "Fraction.h"
#include <iostream>
// TODO: continue the namespace
using namespace std;
namespace sict {
	// TODO: implement the default constructor
	Fraction::Fraction() {
		numerator = -1;
		denominator = 0;
	}
	// TODO: implement the two-argument constructor
	Fraction::Fraction(int numer, int denom) {
		if (numer >= 1 && denom >= 1) {
			numerator = numer;
			denominator = denom;
		}
		else {
			numerator = -1;
			denominator = 0;
		}
		reduce();
	}
	// TODO: implement the max query
	int Fraction::max() const {
		return numerator > denominator ? numerator : denominator;
	}
	// TODO: implement the min query
	int Fraction::min() const {
		return numerator < denominator ? numerator : denominator;
	}
	// gcd returns the greatest common divisor of num and denom
	//
	int Fraction::gcd() const {
		int mn = min();  // min of numerator and denominator
		int mx = max();  // max of numerator and denominator
		int g_c_d = 1;
		bool found = false;

		for (int x = mn; !found && x > 0; --x) { // from mn decrement until divisor found
			if (mx % x == 0 && mn % x == 0) {
				found = true;
				g_c_d = x;
			}
		}
		return g_c_d;
	}

	// TODO: implement the reduce modifier
	void Fraction::reduce() {
		int reduce = gcd();
		numerator /= reduce;
		denominator /= reduce;
	}

	// TODO: implement the display query
	void Fraction::display() const{
		if (numerator >= 1 && denominator >= 1) {
			if (denominator == 1)
				cout << numerator << endl;
			else
				cout << numerator << "/" << denominator;
		}
		else
			cout << "no fraction stored";
	}
	
	// TODO: implement the isEmpty query
	bool Fraction::isEmpty() const{
		bool flag = true;
		if (numerator >= 1 && denominator >= 1)
			flag = false;
		return flag;
	}
	// TODO: implement the + operator
	Fraction Fraction::operator+(const Fraction & rhs) const {
		Fraction temp;
		if (!rhs.isEmpty() && !this->isEmpty()) {
			temp.numerator = this->numerator * rhs.denominator + rhs.numerator * this->denominator;
			temp.denominator = this->denominator * rhs.denominator;
		}
		return temp;
	}
}