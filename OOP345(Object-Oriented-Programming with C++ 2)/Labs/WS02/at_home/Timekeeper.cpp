/*Alejandro Mandala 036870111
amandala@myseneca.ca
Workshop 2 in lab
*/

#include <iostream>
#include <iomanip>
#include <chrono>
#include "Timekeeper.h"

namespace sict {
	
	Timekeeper::Timekeeper() : tstart{}, tend{}, counter{ 0 } { }
	
	void Timekeeper::start() { tstart = std::chrono::steady_clock::now(); }
	
	void Timekeeper::stop() { tend = std::chrono::steady_clock::now(); }

	void Timekeeper::recordEvent(const char *description) {
		auto start = tstart;
		auto end = tend;

		if (counter < max) {
			record[counter].message = description;
			record[counter].duration = end - start;
			counter++;
		}
	}

	void Timekeeper::report(std::ostream &os) {
		os << "\nExecution Times:" << std::endl;
		for (size_t i = 0; i < counter; ++i)
			os << record[i].message << std::setw(6) << std::chrono::duration_cast<std::chrono::milliseconds>(record[i].duration).count() << " " << record[i].units << std::endl;
	}
}