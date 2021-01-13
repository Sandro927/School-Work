#include <iostream>
#include "iAccount.h"
#include "Account.h"
#include "SavingsAccount.h"
#include "ChequingAccount.h"
#define interest_defined .05
#define transaction_fee 0.50
#define monthly_fee 2.00

using namespace std;
namespace sict {
	iAccount* CreateAccount(const char* type, double balance) {
		iAccount *temp = nullptr;
		if (*type == 'S')
			temp = new SavingsAccount(balance, interest_defined);
		else if (*type == 'C')
			temp = new ChequingAccount(balance, transaction_fee, monthly_fee);
		else
			temp = NULL;
		return temp;
	}
}