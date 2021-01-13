#ifndef LIST_SICT_H
#define LIST_SICT_H
#include <iostream>

namespace sict {

	template <typename T, int N>
	class List {

		T elem[N];
		size_t noE = 0;

	public:
		size_t size() const { return noE; }
		const T& operator[](size_t i) const { 
			const T& ref = elem[i];
			return ref;
		}
		void operator+=(const T& t) { if (noE < N) elem[noE++] = t; }
		};

	template <typename T, typename L, typename V, int N>
	class LVList : public List<T, N> {
	public:
		V accumulate(const L& label) const {
			SummableLVPair<L, V> csum;
			V eleSum = csum.getInitialValue();
			for (size_t i = 0; i < ((List<T, N>&)*this).size(); ++i) {
				if (label == ((List<T, N>&)*this)[i].getLabel())
					eleSum = ((List<T, N>&)*this)[i].sum(label, eleSum);
			}
			return eleSum;
		}
	};
}
#endif

