#pragma once
#ifndef SICT_IACCOUNT_H
#define SICT_IACCOUNT_H
#include <iostream>
using namespace std;
namespace sict {
	class iAccount {
	public:
		virtual bool credit(double) = 0;
		virtual bool debit(double) = 0;
		virtual void monthEnd() = 0;
		virtual void display(std::ostream&) const = 0;
	};
	iAccount* CreateAccount(const char* type, double initBalance);
}
#endif