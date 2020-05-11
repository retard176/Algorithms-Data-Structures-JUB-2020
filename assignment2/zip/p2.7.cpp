/*
 * Algorithms & Data Structures Spring 2020
 * Assignment 2
 * Harit Krishan
 * h.krishan@jacobs-university.de
 */

#include <iostream>
#include <map>
#include <fstream>

using namespace std;

int main() {
	string input, fname, sname;
	unsigned int bdate;
	map<string, unsigned int> dates;
	ifstream infile("data.txt");

	while(infile >> fname >> sname >> bdate) {
		dates[fname] = bdate;
	}

	cout << "Enter name: ";
	cin >> input;

	map<string, unsigned int>::iterator iter;

	iter = dates.find(input);

	if(iter == dates.end()) {
		cout << "Name not found!\n";
	} else {
		cout << dates.find(input)->second << "\t[ddmmyyyy]\n" << endl;
	}

	return 0;
}
