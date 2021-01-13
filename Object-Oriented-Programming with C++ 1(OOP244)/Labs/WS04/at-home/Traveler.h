// TODO: add file header comments here

// TODO: add header file guard here
#ifndef SICT_TRAVELER_H
#define SICT_TRAVELER_H
// TODO: define the constants here
#define max_destination_size 32
#define max_name_size 16
// TODO: declare your namespace here
using namespace std;
namespace sict {	

    // TODO: define the Traveler class here
	class Traveler {
	private:
		char fname[max_name_size];
		char lname[max_name_size];
		char destination[max_destination_size];
		int year, month, day;
	public:
		Traveler();
		Traveler(const char *firstName, const char *lastName, const char *address);
		Traveler(const char *firstName, const char *lastName, const char *address, int year, int month, int day);
		bool isEmpty() const;
		void display() const;
		const char* name() const;
		bool canTravelWith(const Traveler& traveler) const;
	};
}
#endif