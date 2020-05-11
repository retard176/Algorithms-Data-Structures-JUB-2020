/*
 * Algorithms & Data Structures Spring 2020
 * Assignment 2
 * Harit Krishan
 * h.krishan@jacobs-university.de
 */

#include <iostream>
#include <set>
#include <ctime>
#include <cstdlib>

using namespace std;

int main() {
	set<int> draw;
	srand(time(nullptr));
	int random[6];

	for(int i = 0; i < 6; i++) {
		random[i] = rand() % 49 + 1;
		draw.insert(random[i]);
	}

	set<int>::iterator iter = draw.begin();
	
	while(iter != draw.end()) {
		cout << *iter << " ";
		iter++;
	}

	cout << endl;

	return 0;
}


