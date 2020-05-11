/*
 * Algorithms & Data Structures
 * Assignment 2
 * Harit Krishan
 * h.krishan@jacobs-university.de
 */

#include <iostream>
#include <deque>

using namespace std;

class WindGauge {
	public:
		WindGauge(int period = 12);
		void currentWindSpeed(int speed);
		int highest() const;
		int lowest() const;
		int average() const;
	private:
		deque<int> history;
		unsigned int period;

};

void dump(WindGauge o);
