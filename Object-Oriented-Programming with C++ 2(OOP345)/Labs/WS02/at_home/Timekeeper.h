/*Alejandro Mandala 036870111
amandala@myseneca.ca
Workshop 2 in lab
*/
#ifndef SICT_TIMEKEEPER_H
#define SICT_TIMEKEEPER_H
#include <chrono>
#include <iostream>
namespace sict {
	const int max = 10;

	class Timekeeper {
		int counter;
		std::chrono::steady_clock::time_point tstart;
		std::chrono::steady_clock::time_point tend;
		struct {
			const char* message;
			const char* units = "seconds";
			std::chrono::steady_clock::duration duration;
		} record[max];
	public:
		Timekeeper();
		void start();
		void stop();
		void recordEvent(const char*);
		void report(std::ostream&);
	};
}
#endif
