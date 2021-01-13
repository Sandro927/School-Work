// TODO: include the necessary headers
#include "CellPhone.h"
// TODO: the sict namespace
using namespace std;
namespace sict {
	// TODO: definition for display(...) 
	void display(const CellPhone& phone) {
		cout << "Phone " << phone.m_model << " costs $" << phone.m_price << "!" << endl;
	}
}