/*
 * Algorithms & Data Structures Spring 2020
 * Assignment 2
 * Harit Krishan
 * h.krishan@jacobs-university.de
 */

#include <iostream>
#include <deque>
#include "WindGauge.h"

using namespace std;

WindGauge::WindGauge(int period) {
	this->period = period;
}

void WindGauge::currentWindSpeed(int speed) {
	this->history.push_front(speed);

	if(history.size() > period) {
		history.pop_back();
	}
}

int WindGauge::highest() const {
	int h = 0;
	deque<int>::const_iterator iter;
	iter = this->history.begin();
	for(unsigned int i = 0; i < period; i++) {
		if(*iter > h) {
			h = *iter;
		}
		iter++;
	}

	return h;
}

int WindGauge::lowest() const {
	int l;
	deque<int>::const_iterator iter;
	iter = this->history.begin();
	l = *iter;
	while(iter != history.end()) {
		if(*iter <= l) {
			l = *iter;
		}
		iter++;
	}
	
	return l;
}

int WindGauge::average() const {
	int sum,avg;
	sum = 0;
	deque<int>::const_iterator iter;
	iter = this->history.begin();
	for(unsigned int i = 0; i < period; i++) {
		sum += *iter;
		iter++;
	}
	avg = sum / history.size();

	return avg;
}

void dump(WindGauge o) {
	cout << "Lowest Speed:\t" << o.lowest() << endl;
	cout << "Highest Speed:\t" << o.highest() << endl;
	cout << "Average Speed: \t" << o.average() << endl;
}
