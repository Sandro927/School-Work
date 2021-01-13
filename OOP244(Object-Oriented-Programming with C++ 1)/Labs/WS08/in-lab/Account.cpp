#include "Account.h"

sict::Account::Account(double balance) {
	if (balance > 0)
		accBalance = balance;
	else
		accBalance = 0.0;
}

bool sict::Account::credit(double amount) {
	if (amount > 0) {
		accBalance += amount;
		return true;
	}
	return false;
}

bool sict::Account::debit(double amount) {
	if (amount > 0 && (accBalance - amount) > 0) {
		accBalance -= amount;
		return true;
	}
	return false;
}

double sict::Account::balance() const {
	return accBalance;
}
