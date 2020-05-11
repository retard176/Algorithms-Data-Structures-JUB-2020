/*
 * Code Developed by Harit Krishan
 * Algorithms & Data Structures Spring 2020
 * Assignment 5
 */

#include <iostream>
#include <ctime>
#include <cmath>

using namespace std;

double fibonacci_recursion(unsigned int n) {
	unsigned int fib;
	if(n == 1) {
		return 1;
	} else if (n == 0) {
		return 0;
	}

	fib = fibonacci_recursion(n - 1) + fibonacci_recursion(n - 2);

	return fib;
}


// Below I define a function for implementing exponents.

double exp_n(double base, double power) {
	if(power != 0) {
		return (base*exp_n(base, power - 1));
	} else {
		return 1;
	}
}

double fibonacci_closed(unsigned int n) {
	double fi1, fi2, fi3, fib;

	fi1 = (1+sqrt(5))/2;
	fi2 = (1-sqrt(5))/2;
	fi3 = ((exp_n(fi1, n)) - (exp_n(fi2, n)));
	fib = (fi3/sqrt(5));
	

	return fib;
}

double fibonacci_bottom_up(unsigned int n) {
	unsigned int i;
	double fib[n];

	fib[0] = 0;
	fib[1] = 1;

	for(i = 2; i <= n; i++) {
		fib[i] = fib[i-1] + fib[i-2];
	}

	return fib[n];
}

// Next two functions are helper functions for the matrix implementation of
// computing a fibonacci number.
// -> multiply()
// -> power()


void multiply(double F[2][2], double M[2][2]) {
	double x = F[0][0]*M[0][0] + F[0][1]*M[1][0];
	double y = F[0][0]*M[0][1] + F[0][1]*M[1][1];
	double z = F[1][0]*M[0][0] + F[1][1]*M[1][0];
	double w = F[1][0]*M[0][1] + F[1][1]*M[1][1];

	F[0][0] = x;
	F[0][1] = y;
	F[1][0] = z;
	F[1][1] = w;
}

void power(double F[2][2], double n) {
	int i;
	double M[2][2] = {{1,1}, {1,0}};
	for(i = 2; i <= n; i++) {
		multiply(F, M);
	}
}


double fibonacci_matrix(unsigned int n) {
	double F[2][2] = {{1,1},{1,0}};
	if(n == 0) {
		return 0;
	}
	power(F, n-1);
	return F[0][0];
}



int main() {

	cout << fibonacci_bottom_up(4) << endl;
	cout << fibonacci_bottom_up(3) << endl;
	cout << fibonacci_bottom_up(7) << endl;
	return 0;
}








