/*
 * Algorithms & Data Structures Spring 2020
 * Prof. Dr. Kinga Lipskoch
 * Assignment 7 - Counting Sort
 * Developed by Harit Krishan
 * With Assistance from tutorialspoint.com
 */

#include <iostream>
#include <ctime>

using namespace std;

int getMax(int array[], int size) {
	int max = array[1];
	for(int i = 2; i <= size; i++) {
		if(array[i] > max) {
			max = array[i];
		}
	}
	return max;
}

void counting_sort(int *arr, int size) {
	int output[size+1];
	int max = getMax(arr, size);
	int count[max+1];

	for(int i = 0; i <= max; i++) {
		count[i] = 0;
	}

	for(int i = 0; i < size; i++) {
		count[arr[i]]++;
	}

	for(int i = 1; i <= max; i++) {
		count[i] += count[i-1];
	}

	for(int i = size-1; i >= 0; i--) {
		output[count[arr[i]]-1] = arr[i];
		count[arr[i]]--;
	}

	for(int i = 0; i < size; i++) {
		arr[i] = output[i];
	}
}

int main() {

	int arr[] = {9,1,6,7,6,2,1};
	int size = 7;

	cout << "Input Array: ";
	for(int i = 0; i < 7; i++) {
		cout << arr[i] << " ";
	}

	cout << endl;

	clock_t start = clock();
	counting_sort(arr, size);
	clock_t end = clock();

	cout << "Sorted Array: ";

	for(int i = 0; i < 7; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;

	cout << "Execution Time: " << (double)(end-start)/CLOCKS_PER_SEC << "s" << endl;

	return 0;
}




