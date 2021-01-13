// TODO: header safeguards
#ifndef SICT_CELLPHONE_H
#define SICT_CELLPHONE_H
#include <iostream>
using namespace std;
// TODO: sict namespace
namespace sict {
// TODO: define the structure CellPhone in the sict namespace
	struct CellPhone {
		char m_model[32];
		float m_price;
	};
// TODO: declare the function display(...),
//         also in the sict namespace
	void display(const CellPhone& phone);
	void display(const CellPhone* phone, int counter);
}
#endif