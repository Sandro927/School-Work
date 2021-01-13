// TODO: include the necessary headers
#include "CellPhone.h"
// TODO: the sict namespace
using namespace std;
namespace sict {
	// TODO: definition for display(...) 
	void display(const CellPhone& phone) {
		cout << "Phone " << phone.m_model << " costs $" << phone.m_price << "!" << endl;
	}
	void display(const CellPhone *phones, int counter) {
		float min = phones[0].m_price;
		for (int i = 0; i < counter; i++) {
			cout << i+1 << ". ";
			display(phones[i]);
			if (phones[i].m_price < min) {
				min = phones[i].m_price;
			}
		}
		cout << "------------------------------" << endl;
		cout << "The cheapest phone costs $" << min << "." <<endl;
		cout << "------------------------------" << endl;
	}
}