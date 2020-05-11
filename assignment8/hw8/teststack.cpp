#include <iostream>
#include <ctime>
#include <cstdlib>
#include "stack.h"

using namespace std;

int main() {
	Stack<int> stack_a(15);
	Stack<int> stack_b;

	srand(time(NULL));

	cout << "Empty Status Stack A: " << stack_a.isEmpty() << endl;
	cout << "Empty Status Stack B: " << stack_b.isEmpty() << endl;
	for(int i = 0; i < 15; i++) {
		stack_a.push(i);
	}

	stack_a.reverse();

	cout << "Empty Status Stack A: " << stack_a.isEmpty() << endl;
	cout << "Empty Status Stack B: " << stack_b.isEmpty() << endl;
	cout << "Emptying Stack A!" << endl;
	for(int i = 0; i < 15; i++) {
		cout << stack_a.pop() << " ";
	}
	cout << "Empty Status Stack A: " << stack_a.isEmpty() << endl;
	cout << "Empty Status Stack B: " << stack_b.isEmpty() << endl;
	return 0;
}

