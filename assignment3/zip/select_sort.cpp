#include <iostream>
#include <ctime>
#include <cmath>
#include <fstream>

using namespace std;

void swap(int *x, int *y) {
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

void selection_sort(int arr[], int size) {
	int i, j, min_index;

	for(i = 0; i < size-1; i++) {
		min_index = i;

		for(j = i+1; j < size; j++) {
			if(arr[j] < arr[min_index]) {
				min_index = j;
			}
		}
		swap(arr[min_index], arr[i]);
	}
}

void print_array(int arr[], int size) {
	if(size <= 100) {
		int i;
		for(i = 0; i < size; i++) {
			cout << arr[i] << " ";
		}
		cout << endl;
	} else {
		cout << "Array too big to print!" << endl;
	}
}

int main() {
	srand(time(NULL));
	int size = 1;
	//cout << "Enter size of random array: ";
	//cin >> size;
	//int arr[size];
	
	ofstream output("sel_sort_data.txt");

	while(size <= 1000){
	int arr[size];
	for(int i = 0; i < size; i++) {		// Random Number Generator
		arr[i] = rand() % 99 + 1;
	}

/*	cout << "Randomly generated array: ";
	print_array(arr, size);
	cout << endl;
*/	
	cout << "Applying Selection Sort..." << endl;
	clock_t start = clock();
	selection_sort(arr, size);
	clock_t end = clock();

	output << size << " " << ((double)(end-start)/CLOCKS_PER_SEC)*1000 << endl;
	size++;
	}
/*	cout << "Selection Sort Applied [" << ((double)(end-start)/CLOCKS_PER_SEC)*1000 << "ms]\n\n";

	cout << "Sorted Array: ";
	print_array(arr, size);
*/

	return 0;

}
