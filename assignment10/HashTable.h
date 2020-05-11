/*
	Code Written By Harit Krishan
	Algorithms & Data Structures Spring 2020
	Prof. Dr. Kinga Lipskoch
	Assistance from github.com. geeksforgeeks.com
*/

#include <bits/stdc++.h>

using namespace std;

class Node {
public:
	Node() {}
	int key, value;
	Node(int key, int value) {}

};

class HashTable {
private:
	Node **arr;
	int maxSize, currentSize;

public:
	HashTable() {						// Table Constructor
		arr = new Node* [maxSize];
	}

	HashTable(int new_size) {			// Paramatrized Table Constructor
		this->maxSize = new_size;
		HashTable();
	}

	int hashFunct(int key) {
		return((key % 23) + (key % 7));		// Hash Index Generator
	}

	int hashCode(int new_key) {
		int i = 0, j;

		while(i != maxSize) {
			j = (hashFunct(new_key) + i) % maxSize;

			if(arr[j] != NULL && arr[j]->key == new_key) {
				cout << "Key already in Table!" << endl;
				return(-1);
			}

			if(arr[j] == NULL) {
				insertNode(new_key, j);
				return(j);
			}

			i++;
		}

		cout << "Table Overflow!" << endl;
	}

	// Key and Index as Parameters for Insertion

	void insertNode(int new_key, int new_value) {
		Node *newNode = new Node;
		newNode->key = new_key;
		newNode->value = new_value;
		cout << "Inserting " << new_key << endl;
		arr[new_value] = newNode;
		currentSize++;
	}

	int get(int key) {				// Key Getter Method
		int i = 0, j;

		while(i != maxSize) {
			j = (hashFunct(key) + i) % maxSize;
			if(arr[j] == NULL) {
				break;
			}

			if(arr[j]->key == key) {
				cout << key << " found! Index Position: " << j << endl;
				return(j);
			}

			i++;
		}

		cout << "Key not found!" << endl;
		return(-1);
	}

	bool isEmpty() {				// Empty Test Function
		int i = 0;

		while(i != maxSize) {
			if(arr[i] != NULL) {
				return(false);
			}
			i++;
		}

		return(true);
	}
};