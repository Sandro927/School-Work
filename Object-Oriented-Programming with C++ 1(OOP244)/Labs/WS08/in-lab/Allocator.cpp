#include <iostream>
#include "iAccount.h"
#include "Account.h"
#include "SavingsAccount.h"
#define interest_defined .05
using namespace std;
namespace sict {
	iAccount* CreateAccount(const char* type, double balance) {
		iAccount *temp = nullptr;
		if (*type == 'S')
			temp = new SavingsAccount(balance, interest_defined);
		return temp;
	}
}