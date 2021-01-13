#include "SavingsAccount.h"
using namespace std;
namespace sict {

	SavingsAccount::SavingsAccount(double balance, double interestRate) : Account(balance) {
		if (balance > 0 && interestRate > 0) 
			accInterest = interestRate;
		else 
			accInterest = 0.0;
	}

	void sict::SavingsAccount::monthEnd() {
		credit(balance() * accInterest);
	}

	void sict::SavingsAccount::display(ostream & out) const {
		out << "Account type: Savings" << endl;
		out << "Balance: $" << balance() << endl;
		out << "Interest Rate (%): " << accInterest << endl;
	}
}