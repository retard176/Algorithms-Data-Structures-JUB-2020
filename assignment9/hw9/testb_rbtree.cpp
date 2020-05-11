/*
	Algorithms & Data Structures Spring 2020
	Prof. Dr. Kinga Lipskoch
	Written by Harit Krishan
	Assistance from Github.com, GeeksforGeeks.com
*/

#include <bits/stdc++.h>
#include "rbtree.h"

using namespace std;

int main() {

	RedBlackTree tree_init;

	int arr1[] = {1,2,3,4};

	for(int i = 0; i < 4; i++) {
		tree_init.insert(arr1[i]);
	}

	tree_init.rbtprint_text();

	cout << endl << endl;

	for(int i = 0; i < 4; i++) {
		for(int j = 0; j < 4; j++) {
			if(i != j) {
				// All variations of input
				int temp[4];
				copy(begin(arr1), end(arr1), begin(temp));
				swap(temp[i], temp[j]);
				RedBlackTree tree;
				for(int i = 0; i < 4; i++) {
					tree.insert(temp[i]);
				}

				tree.rbtprint_text();
			}
		}
	}

	cout << endl << endl;

	cout << "Where 0:RED\t1:BLACK\n";

	return 0;
}