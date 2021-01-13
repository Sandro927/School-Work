#pragma once
#include <iostream>
#include "iAccount.h"
#include "Account.h"
using namespace std;
namespace sict {
	class SavingsAccount : public Account {
	private:
		double accInterest;
	public:
		SavingsAccount(double balance, double interestRate);
		void monthEnd();
		void display(ostream& out) const;
	};
}