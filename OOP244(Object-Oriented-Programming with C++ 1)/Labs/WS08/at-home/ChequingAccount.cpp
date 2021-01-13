#include "ChequingAccount.h"
using namespace std;
namespace sict {



	sict::ChequingAccount::ChequingAccount(double balance, double transFee, double monthlyFee) : Account(balance){
		if (transFee > 0)
			transCharge = transFee;
		else
			transCharge = 0.0;
		if (monthlyFee > 0)
			monthlyCharge = monthlyFee;
	}

	bool sict::ChequingAccount::credit(double amount) {
		Account::debit(transCharge);
		return Account::credit(amount);
	}

	bool sict::ChequingAccount::debit(double amount) {
		return Account::debit(amount);
	}

	void sict::ChequingAccount::monthEnd() {
		debit(monthlyCharge);
	}

	void sict::ChequingAccount::display(ostream & out) const {
		out << "Account type: Chequing" << endl;
		out << "Balance: $" << balance() << endl;
		out << "Per transaction fee: " << transCharge << endl;
		out << "Monthly fee: " << monthlyCharge << endl;
	}
}