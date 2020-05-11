/*
 * Algorithms & Data Structures Spring 2020
 * Assignment 2
 * Harit Krishan
 * h.krishan@jacobs-university.de
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	vector<int> a;
	for(unsigned int i = 1; i <= 30; i++) {
	       a.push_back(i);
	}

	a.push_back(5);
	reverse(a.begin(), a.end());

	vector<int>::iterator iter = a.begin();

	while(iter != a.end()) {
		cout << *iter << " ";
		iter++;
	}

	cout << endl;
	cout << endl;

	replace(a.begin(), a.end(), 5, 129);

	iter = a.begin();

	while(iter != a.end()) {
		cout << *iter << " ";
		iter++;
	}

	cout << endl;

	return 0;
}	
