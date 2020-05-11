/*
	Code Written By Harit Krishan
	Algorithms & Data Structures Spring 2020
	Prof. Dr. Kinga Lipskoch
	Assistance from github.com. geeksforgeeks.com
*/

#include <bits/stdc++.h>
#include "HashTable.h"

using namespace std;

int main() {
	srand(time(NULL));			// Random Number Seed
	HashTable Table;			// Initialize a hash table
	
	if(Table.isEmpty()) {
		cout << "Table is Empty!" << endl;
	}

	for(int i = 0; i < 20; i++) {
		Table.hashCode(rand() % 20 + 1);	// Insert Random Keys
	}

	for(int i = 0; i < 20; i++) {
		Table.get(rand() % 10 + 1);			// Demonstration of Getter Method
	}

	cout << endl;

	return(0);
}