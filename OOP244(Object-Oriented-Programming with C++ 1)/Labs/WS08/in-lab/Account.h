#pragma once
#include <iostream>
#include "iAccount.h"
using namespace std;
namespace sict {
	class Account : public iAccount {
	private:
		double accBalance = 0.0;
	public:
		Account() = default;
		Account(double balance);
		bool credit(double amount);
		bool debit(double amount);
	protected:
		double balance() const;
	};

}