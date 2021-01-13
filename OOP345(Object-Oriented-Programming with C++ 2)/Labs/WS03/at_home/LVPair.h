#ifndef LVPAIR_SICT_H
#define LVPAIR_SICT_H
#include <iostream>
#include <string>

namespace sict {
	template<typename L, typename V>
	class LVPair {
		L cLabel;
		V cValue;

	public:
		LVPair() : cLabel{}, cValue{} {}
		LVPair(const L& label, const V& value) {
			cLabel = label;
			cValue = value;
		}
		virtual void display(std::ostream& os) const { os << cLabel << " : " << cValue << std::endl; }
		const L& getLabel() const { return cLabel; }
		const V& getValue() const { return cValue; }
	};
	template<typename L, typename V>
	std::ostream& operator<< (std::ostream& os, const LVPair<L, V>& pair) {
		pair.display(os);
		return os;
	}
	template <typename L, typename V>
	class SummableLVPair : public LVPair<L, V> {

		static V initial;
		static size_t width;

	public:
		SummableLVPair() {}
		SummableLVPair(const L& label, const V& v) : LVPair<L, V>(label, v) {
			if (width < label.size())
				width = label.size() + 1;
		}
		const V& getInitialValue() { return initial; }
		V sum(const L& label, const V& sum) const{ return LVPair<L, V>::getValue() + sum; }
		void display(std::ostream& os) const {
			os.setf(std::ios::left);
			os.width(width);
			os << LVPair<L, V>::getLabel() << ": " << LVPair<L, V>::getValue() << std::endl;
			os.unsetf(std::ios::left);
		}
	};
	template<>
	std::string SummableLVPair<std::string, std::string>::sum(const std::string& label, const std::string& value) const { return (value + " " + LVPair<std::string, std::string>::getValue()); }
}
#endif


