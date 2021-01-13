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
}
#endif