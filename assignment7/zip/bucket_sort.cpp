/*
 * Algorithms & Data Structures Spring 2020
 * Prof. Dr. Kinga Lipskoch
 * Assignment 7 - Bucket Sort
 * Developed by Harit Krishan
 * With Assistance from tutorialspoint.com
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void bucket_sort(float *arr, int size) {
	vector<float> bucket[size];
	for(int i = 0; i < size; i++) {
		bucket[int(size*arr[i])].push_back(arr[i]);
	}

	for(int i = 0; i < size; i++) {
		sort(bucket[i].begin(), bucket[i].end());
	}

	int j = 0;
	for(int i = 0; i < size; i++) {
		while(!bucket[i].empty()) {
			arr[j++] = *(bucket[i].begin());
			bucket[i].erase(bucket[i].begin());
		}
	}
}

int main() {
	float arr[] = {0.9, 0.1, 0.6, 0.7, 0.6, 0.3, 0.1};
	int size = sizeof(arr)/sizeof(arr[0]);

	cout << "Input Array: ";
	for(int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}

	cout << endl;
	clock_t start = clock();
	bucket_sort(arr, size);
	clock_t end = clock();

	cout << "Sorted Array: ";
	for(int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;

	cout << "Execution Time = " << (double)(end-start)/CLOCKS_PER_SEC << "s" << endl;

	return 0;

}
