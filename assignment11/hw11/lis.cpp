/*
	Code Written by Harit Krishan
	Algorithms & Data Structures Spring 2020
	Prof. Dr. Kinga Lipskoch
	Assistance from geeksforgeeks.org
*/

#include <bits/stdc++.h>

using namespace std;

void print_array(vector<int>& vect) {
	for (int x : vect) 
        cout << x << " "; 
    cout << endl; 
}

// Dynamic Programming Approach
// Tabulation Method

void lis(int *arr, int size) {
	vector<vector<int>> L(size);		// create vector of vectors

	L[0].push_back(arr[0]);

	for(int i = 1; i < size; i++) {
		for(int j = 0; j < i; j++) {
			if((arr[i]>arr[j]) && (L[i].size() < L[j].size() + 1)) {
				L[i] = L[j];
			}
		}
		L[i].push_back(arr[i]);
	}

	vector<int> max = L[0];

	for(vector<int> x : L) {
		if(x.size() > max.size()) {
			max = x;
		}
	}

	print_array(max);
}

int main() {
	int arr[] = {8, 3, 6, 50, 10, 8, 100, 30, 60, 40, 80};

	lis(arr, 11);

	return 0;
}