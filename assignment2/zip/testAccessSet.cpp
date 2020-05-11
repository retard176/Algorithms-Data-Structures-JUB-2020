/*
 * Algorithms & Data Structures Spring 2020
 * Assignment 2
 * Harit Krishan
 * h.krishan@jacobs-university.de
 */

#include <iostream>
#include <set>
#include "Access.h"

using namespace std;

int main() {
	Access obj;
	obj.activate(1234);
	obj.activate(9999);
	obj.activate(9876);
	
	int input = 0;

	cout << "Enter Access Code: ";
	scanf("%d", &input);
		
	while(1) {
		if(obj.isactive(input)) {
			cout << "Door Opened Successfully!" << endl;
			obj.deactivate(input);
			break;
		} else {
			cout << "Access Denied. Enter Access Code: ";
			scanf("%d", &input);
		}
	}

	obj.deactivate(9999);
	cout << "Access code 9999 deactivated!" << endl;
	obj.activate(1111);
	cout << "Access code 1111 activated!" << endl;

	cout << "Enter Access Code: ";
	scanf("%d", &input);

	while(1) {
		if(obj.isactive(input)) {
			cout << "Door Opened Successfully!" << endl;
			break;
		} else {
			cout << "Access Denied. Enter Access Code: ";
			scanf("%d", &input);
		}
	}

	return 0;
}
