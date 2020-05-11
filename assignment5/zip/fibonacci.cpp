/*
 * Code Developed by Harit Krishan
 * Algorithms & Data Structures Spring 2020
 * Assignment 5
 */

#include <iostream>
#include "fibonacci.h"
#include <ctime>
#include <fstream>

using namespace std;


int main() {
	double fib_recur, fib_clos, fib_bu, fib_mat;

	// Need to time the implementation of algorithm.
	// Use clock_t class from <ctime>


	double time_threshold = 0.001;	// if longer than 4s, exit
	double t = 0.0;
	unsigned long int n = 0;
	ofstream recur_result("results_recur.dat");
	ofstream recur("recur.dat");
	if(!recur_result.is_open())
		cout << "Error Opening File!" << endl;

	if(!recur.is_open()) 
		cout << "Error Opening File!" << endl;

	while(t <= time_threshold) {
		clock_t rec = clock();
		fib_recur = fibonacci_recursion(n);
		clock_t rec2 = clock();
		t = (double)(rec2-rec)/(CLOCKS_PER_SEC);
		
		recur << n << " " << t << endl;
		recur_result << n << " " << fib_recur << endl;
		n++;
	}


	cout << n << " fibonacci numbers computed using recursion (naive) method.\n\n";
	cout << "Output written to files." << endl << endl;

	recur_result.close();
	recur.close();

	t = 0.0;
	n = 0;
	ofstream closed_result("results_closed.dat");
	ofstream closed("closed.dat");

	if(!closed_result.is_open()) 
		cout << "Error Opening File!" << endl;

	if(!closed.is_open()) 
		cout << "Error Opening File!" << endl;



	while(t <= time_threshold) {
		clock_t c = clock();
		fib_clos = fibonacci_closed(n);
		clock_t c2 = clock();
		t = (double)(c2-c)/(CLOCKS_PER_SEC);
		
		closed << n << " " << t << endl;
		closed_result << n << " " << fib_clos << endl;
		n++;
	}


	cout << n << " fibonacci numbers computed using closed form method.\n\n";
	cout << "Output written to files." << endl << endl;

	closed_result.close();
	closed.close();

	t = 0.0;
	n = 0;
	ofstream bu_result("results_bottom_up.dat");
	ofstream bu("bottom_up.dat");

	if(!bu_result.is_open()) 
		cout << "Error Opening File!" << endl;

	if(!bu.is_open()) 
		cout << "Error Opening File!" << endl;



	while(n <= 70771) {
		clock_t bup = clock();
		fib_bu = fibonacci_bottom_up(n);
		clock_t bup2 = clock();
		t = (double)(bup2-bup)/(CLOCKS_PER_SEC);
		
		bu << n << " " << t << endl;
		bu_result << n << " " << fib_bu << endl;
		n++;
	}


	cout << n << " fibonacci numbers computed using bottom-up method.\n\n";
	cout << "Output written to files." << endl << endl;

	bu_result.close();
	bu.close();

	t = 0.0;
	n = 0;
	ofstream mat_result("results_matrix.dat");
	ofstream mat("matrix.dat");

	if(!mat_result.is_open()) 
		cout << "Error Opening File!" << endl;

	if(!mat.is_open()) 
		cout << "Error Opening File!" << endl;



	while(t <= time_threshold) {
		clock_t matr = clock();
		fib_mat = fibonacci_matrix(n);
		clock_t matr2 = clock();
		t = (double)(matr2-matr)/(CLOCKS_PER_SEC);
		
		mat << n << " " << t << endl;
		mat_result << n << " " << fib_mat << endl;
		n++;
	}


	cout << n << " fibonacci numbers computed using matrix method.\n\n";
	cout << "Output written to files." << endl << endl;

	mat_result.close();
	mat.close();

	t = 0.0;
	n = 0;

	return 0;
}








