/*
 * Algorithms & Data Structures Spring 2020
 * Prof. Dr. Kinga Lipskoch
 * Assignment 7 - Radix Sort
 * Developed by Harit Krishan
 * With Assistance from tutorialspoint.com
 */

#include <iostream>

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

void counting_sort(int arr[], int n, int exp) { 

    int output[n];
    int i, count[10] = {0}; 
  

    for (i = 0; i < n; i++) {
        count[ (arr[i]/exp)%10 ]++; 
    }
  
    for (i = 1; i < 10; i++) {
        count[i] += count[i - 1]; 
    }
  
    for (i = n - 1; i >= 0; i--) { 
        output[count[ (arr[i]/exp)%10 ] - 1] = arr[i]; 
        count[ (arr[i]/exp)%10 ]--; 
    } 
   
    for (i = 0; i < n; i++) {
        arr[i] = output[i]; 
    }
} 

void radix_sort(int *arr, int size) {
	int max = getMax(arr, size);

	for(int exp = 1; m/exp > 0; exp *= 10) {
		counting_sort(arr, size, exp);
	}

}









