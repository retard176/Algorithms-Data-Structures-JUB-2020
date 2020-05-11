/*
 * Developed by Harit Krishan
 * Algorithms & Data Structures Spring 2020
 * Prof. Dr. Kinga Lipskoch
 * Assistance from geeksforgeeks.com and github.com
 */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

void heapify(int arr[], int size, int mid) {
        int largest = mid;
        int l = 2*mid + 1;
        int r = 2*mid + 2;

        // Must find largest element between children and root

        if(l < size && arr[l] > arr[largest]) {
                largest = l;
        }

        if(r < size && arr[r] > arr[largest]) {
                largest = r;
        }

        if(largest != mid) {
                // Make mid the largest element
                swap(arr[mid], arr[largest]);
                heapify(arr, size, largest);    // Recursively heapify sub-tree
        }
}

void heapsort(int arr[], int n) {

        // First we build the heap

        for(int i = n/2 - 1; i >= 0; i--) {     // Decrement from end of left half
                heapify(arr, n, i);             // Create sub-heaps
        }

        for(int i = n-1; i >= 0; i--) {
                swap(arr[0], arr[i]);           // Move current root to end of array
                heapify(arr, i, 0);             // Create heap of reduced heap
        }
}

