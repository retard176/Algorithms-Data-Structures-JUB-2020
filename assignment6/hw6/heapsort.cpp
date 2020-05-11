/*
 * Code Developed by Harit Krishan
 * Algorithms & Data Structures Spring 2020
 * Prof. Dr. Kinga Lipskoch
 * Assistance from geeksforgeeks.org
 */

#include <iostream>
#include <ctime>
#include <cstdlib>
#include "heapsort.h"

using namespace std;


int main() {
	int size;
	srand(time(NULL));
	cout << "Enter size of array: ";
	cin >> size;

	int arr[size];

	cout << endl << "Random Array: ";
	for(int i = 0; i < size; i++) {
		arr[i] = rand() % 20 + 1;
		cout << arr[i] << " ";
	}

	cout << endl << "Applying Heap Sort..." << endl;
	heapsort(arr, size);

	cout << "Sorted Array: ";
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;

	return 0;
}





