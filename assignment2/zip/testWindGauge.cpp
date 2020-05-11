/*
 * Algorithms & Data Structures Spring 2020
 * Assignment 2
 * Harit Krishan
 * h.krishan@jacobs-university.de
 */

#include <iostream>
#include <deque>
#include "WindGauge.h"

int main() {
	WindGauge obj;
	obj.currentWindSpeed(15);
	obj.currentWindSpeed(16);
	obj.currentWindSpeed(12);
	obj.currentWindSpeed(15);
	obj.currentWindSpeed(15);

	dump(obj);

	obj.currentWindSpeed(16);
	obj.currentWindSpeed(17);
	obj.currentWindSpeed(16);
	obj.currentWindSpeed(16);
	obj.currentWindSpeed(20);
	obj.currentWindSpeed(17);
	obj.currentWindSpeed(16);
	obj.currentWindSpeed(15);
	obj.currentWindSpeed(16);
	obj.currentWindSpeed(20);

	dump(obj);
	
	return 0;
}
