#include <iostream>
#include <ctime>

using namespace std;

void child_sink(int arr[], int start, int end) {
	int root = start;

	while((2*root + 1) <= end) {
		int child = (2*root) + 1;
		int swap = root;

		if(arr[swap] < arr[child]) {
			swap = child;
		}

		if((child+1) <= end && arr[swap] < arr[child+1]) {
			swap = child + 1;
		}

		if(swap != root) {
			int tmp = arr[root];
			arr[root] = arr[swap];
			arr[swap] = tmp;
			root = swap;
		} else {
			return;
		}
	}
}

void heapify(int arr[], int length) {
	for(int start = (((length-1)-1)/2); start >= 0; start--) {
		child_sink(arr, start, length-1);
	}
}

void heapsort(int arr[], int length) {
	heapify(arr, length);
	int end = length - 1;
	while(end > 0) {
		int tmp = arr[0];
		arr[0] = arr[end];
		arr[end] = tmp;
		end--;
		child_sink(arr, 0, end);
	}
}

int main() {
	int size;
	cout << "Enter array size: ";
	cin >> size;
	cout << endl;
	srand(time(NULL));
	int arr[size];

	cout << "Random Array: ";
	for(int i = 0; i < size; i++) {
		arr[i] = rand() % 50 + 1;
		cout << arr[i] << " ";
	}

	cout << endl << "Applying Heapsort Variant..." << endl;
	clock_t beg = clock();
	heapsort(arr, size);
	clock_t end = clock();

	cout << "Sorted Array : ";
	for(int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}

	cout << endl << "Execution Time: " << (double)(end-beg)/CLOCKS_PER_SEC << "[s]" << endl;

	return 0;
}






