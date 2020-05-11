/*
 * Algorithms & Data Structures Spring 2020
 * Assignment 2
 * Harit Krishan
 * h.krishan@jacobs-university.de
 */

#include <iostream>
#include <set>
#include "Access.h"

using namespace std;

void Access::activate(unsigned int code) {
	set<unsigned int>::iterator iter = codes.begin();
	while(iter != codes.end()) {
		if(*iter == code) {
			cout << "Code already in use!" << endl;
			return;
		}
		iter++;
	}

	codes.insert(code);
}

void Access::deactivate(unsigned int code) {
	set<unsigned int>::iterator iter = codes.begin();
	while(iter != codes.end()) {
		if(*iter == code) {
			codes.erase(code);
			return;
		}
		iter++;
	}
	
	cout << "Access Code not in Directory!" << endl;
}

bool Access::isactive(unsigned int code) const {
	set<unsigned int>::iterator iter = codes.begin();
	while(iter != codes.end()) {
		if(*iter == code) {
			return true;
		} 
		iter++;
	}
	
	return false;
}
