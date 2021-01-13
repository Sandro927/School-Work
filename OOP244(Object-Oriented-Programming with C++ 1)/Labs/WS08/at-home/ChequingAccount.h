#pragma once
#include <iostream>
#include "iAccount.h"
#include "Account.h"
using namespace std;
namespace sict {
	class ChequingAccount : public Account {
	private:
		double monthlyCharge;
		double transCharge;
	public:
		ChequingAccount(double balance, double transFee, double monthlyFee);
		bool credit (double amount);
		bool debit(double amount);
		void monthEnd();
		void display(ostream& out) const;
	};


}