#ifndef LVPAIR_SICT_H
#define LVPAIR_SICT_H
#include <iostream>

namespace sict {
	template<typename L, typename V>
	class LVPair {
		L cLabel;
		V cValue;

	public:
		LVPair() : cLabel(), cValue() {}
		LVPair(const L& label, const V& value) {
			cLabel = label;
			cValue = value;
		}
		void display(std::ostream& os) const { os << cLabel << " : " << cValue << std::endl; }
	};
	template<typename L, typename V>
	std::ostream& operator<< (std::ostream& os, const LVPair<L, V>& pair) {
		pair.display(os);
		return os;
	}
}
#endif


