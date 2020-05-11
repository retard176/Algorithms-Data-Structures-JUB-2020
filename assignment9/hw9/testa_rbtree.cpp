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
	int arr[] = {13, 44, 37, 7, 22, 16};
	RedBlackTree tree;
	
	for(int i = 0; i < 6; i++) {
		tree.insert(arr[i]);
		tree.rbtprint_text();
	}

	return 0;
}