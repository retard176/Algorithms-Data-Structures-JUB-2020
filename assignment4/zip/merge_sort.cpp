/*
 * Code Developed by Harit Krishan
 * Algorithms & Data Structures Spring 2020
 * Instructor: Dr. Kinga Lipskoch
 * Developed with assistance from online sources like github.com, geeksforgeeks.com
 */


#include <iostream>
#include <ctime>
#include <fstream>

using namespace std;

void insertion_sort(int *arr, int low, int high) {
	int key, j;

	for(int i = 0; i < high-low+1; i++) {
		key = arr[i];
		j = i;
		while(j > 0 && arr[j-1] > key) {
			arr[j] = arr[j-1];
			j--;
		}
		arr[j] = key;
	}
}

void merge(int *arr, int low, int high, int mid) {
	int i, j, k;
	int arrb[10000];
	i = k = low;
	j = mid + 1;
	
	while(i <= mid && j <= high) {			// Iterate both sub-arrays	
		if(arr[i] < arr[j]) {			// Lesser of the two selected
			arrb[k] = arr[i];
			k++;
			i++;
		} else {
			arrb[k] = arr[j];
			k++;
			j++;
		}
	}

	while(i <= mid) {			// Remaining (if any) from left sub-array
		arrb[k] = arr[i];
		k++;
		i++;
	}

	while(j <= high) {			// Remaining (if any) from right sub-array
		arrb[k] = arr[j];
		k++;
		j++;
	}

	for(i = low; i < k; i++) {		// Sorted sequnce put inplace of input array
		arr[i] = arrb[i];
	}
}

void merge_sort(int *arr, int low, int high, int k) {

	if(((high - low) + 1) <= k) {
		insertion_sort(arr, low, high);
	} else {
		int mid;
		if(low < high) {
			mid = (low + high)/2;
			merge_sort(arr, low, mid, k);
			merge_sort(arr, mid+1, high, k);
			merge(arr, low, high, mid);
		}
	}
}


int main() {
	int size = 1;
	srand(time(NULL));
	
	ofstream output("acs1.dat");

	while(size <= 1000) {
		int arr[size];
		for(int j = 0; j < size; j++) {
			arr[j] = rand() % 99 + 1;
		}
		//merge_sort(arr, 0, size-1, size/4);
		clock_t start = clock();
		merge_sort(arr, 0, size-1, 1);
		clock_t end = clock();
		// time in ms
		output << size << " " << ((double)(end-start)/CLOCKS_PER_SEC)*1000 << endl;
		size++;
	}

	cout << "Timing results written to 'results.dat' with k = 1" << endl << endl;

	output.close();

	return 0;
}






