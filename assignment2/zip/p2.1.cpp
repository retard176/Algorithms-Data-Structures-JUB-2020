/*
 * Algorithms & Data Structures Spring 2020
 * Assignment 2
 * Harit Krishan
 * h.krishan@jacobs-university.de
 */


#include <iostream>
#include <list>
#include <fstream>

using namespace std;

int main() {

	// 1. Create lists A, B

	list<int> A;
	list<int> B;

	// 2. Read ints until 0 or negative

	int int_buffer;
	cin >> int_buffer;

	// 3. Insert +ive ints into list A at end

	while(int_buffer > 0) {
		A.push_back(int_buffer);
		B.push_front(int_buffer);
		cin >> int_buffer;
	}

	// 5. Print list A with spaces to cout

	list<int>::iterator a_iter;
	a_iter = A.begin();
	cout << *a_iter;
	a_iter++;
	while(a_iter != A.end()) {
		cout << " " << *a_iter;
		a_iter++;
	}

	// Print list B with spaces in listB.txt

	ofstream output("listB.txt");
	list<int>::iterator b_iter;
	b_iter = B.begin();
	
	output << *b_iter;
	b_iter++;
	while(b_iter != B.end()) {
		output << " " << *b_iter;
		b_iter++;
	}

	// 6. Print empty line

	cout << endl;
	cout << endl;

	// 7. Move first element to end for both lists

	a_iter = A.begin();
	b_iter = B.begin();
	int popped_a, popped_b;
	popped_a = *a_iter;
	A.pop_front();
	A.push_back(popped_a);
	popped_b = *b_iter;
	B.pop_front();
	B.push_back(popped_b);

	// 8. Print lists A, B to cout separated by commas

	a_iter = A.begin();
	cout << *a_iter;
	a_iter++;
	while(a_iter != A.end()) {
		cout << ", " << *a_iter;
		a_iter++;
	}
	cout << endl;

	b_iter = B.begin();
	cout << *b_iter;
	b_iter++;
	while(b_iter != B.end()) {
		cout << ", " << *b_iter;
		b_iter++;
	}

	// 9. Print empty line

	cout << endl;
	cout << endl;

	// 10. Merge list B into A

	B.merge(A);

	// 11. Print merged list after sorting

	B.sort();
	b_iter = B.begin();
	while(b_iter != B.end()) {
		cout << *b_iter << " ";
		b_iter++;
	}

	cout << endl;

	return 0;
}
