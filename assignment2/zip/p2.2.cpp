/*
 * Algorithms & Data Structures Spring 2020
 * Assignment 2
 * Harit Krishan
 * h.krishan@jacobs-university.de
 */

#include <iostream>
#include <deque>

using namespace std;

int main() {

	// 1. Create float deque A

	deque<float> A;

	float buffer;

	// 2. Read floats until input 0

	cin >> buffer;

	while(buffer != 0.0) {

	// 3. Insert +ive elements at end, -ve elements at beginning

		if(buffer > 0.0) {
			A.push_back(buffer);
		} else if(buffer < 0.0) {
			A.push_front(buffer);
		}
		cin >> buffer;
	}

	// 4. Print elements to cout

	deque<float>::iterator iter;
	iter = A.begin();
	while(iter != A.end()) {
		cout << *iter << " ";
		iter++;
	}

	// 5. Print empty line

	cout << endl;
	cout << endl;

	// 6. Add 0 between negative and positive values

	iter = A.begin();

	while(*iter < 0) {
		iter++;
	}
	
	A.insert(iter, 0);

	// 7. Print elements of A to cout separated by ;

	iter = A.begin();
	cout << *iter;
	iter++;
	while(iter != A.end()) {
		cout << "; " << *iter;
		iter++;
	}

	cout << endl;

	return 0;
}
