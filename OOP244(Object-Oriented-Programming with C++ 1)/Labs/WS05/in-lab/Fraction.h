// TODO: header file guard
#ifndef SICT_FRACTION_H
#define SICT_FRACTION_H
// TODO: create namespace
using namespace std;
namespace sict {
	// TODO: define the Fraction class
	class Fraction {
		// TODO: declare instance variables 
		private:
			int numerator, denominator;
		// TODO: declare private member functions
			int max() const;
			int min() const;
			void reduce();
			int gcd() const;

	public:
		// TODO: declare public member functions
		Fraction();
		Fraction(int numer, int denom);
		bool isEmpty() const;
		void display() const;
		// TODO: declare the + operator overload
		Fraction operator+(const Fraction& rhs) const;
	};
}
#endif