/*
 * Developed by Harit Krishan
 * Algorithms & Data Structures Spring 2020
 * Prof. Dr. Kinga Lipskoch
 * Assistance from geeksforgeeks.com and github.com
 */


#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void illustrate(int arr[], int size) {
	cout << "Iteration result : ";
	for(int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

void bubblesort(int arr[], int size) {
	int i, j;
	for(i = 0; i < size-1; i++) {
		for(j = 0; j < size-i-1; j++) {	

			/* After i iterations, the last i elements are in sorted order.
			 * we compare successive elements and correct the order.
			 */

			if(arr[j] > arr[j+1]) {
				swap(arr[j], arr[j+1]);
				cout << "Swapping " << arr[j];
				cout << " and " << arr[j+1] << endl;	
			}
			illustrate(arr, size);
		}
	}
}


int main() {
	int size;
	cout << "Enter size of array: ";
	cin >> size;
	int arr[size];
	srand(time(NULL));

	cout << "Random Array : ";

	for(int i = 0; i < size; i++) {
		arr[i] = rand() % 20 + 1;
		cout << arr[i] << " ";
	}
	cout << endl << "Applying Bubblesort..." << endl;

	bubblesort(arr, size);

	cout << endl << "Sorted Array : ";

	for(int j = 0; j < size; j++) {
		cout << arr[j] << " ";
	}
	
	cout << endl;
	return 0;
}


