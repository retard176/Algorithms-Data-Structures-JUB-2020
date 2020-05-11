#include <iostream>

using namespace std;

void enqueue(int x) {				// push element into first stack
	s1.push(x);
}

int  dequeue() {
	if(s1.isEmpty()) {
		while(!s1.isEmpty()) {		// transfer from s1 to s2
			s2.push(s1.pop());
		}
	}
	return s2.pop();			// s2 now in reverse order
}

bool isEmpty() {
	if(s1 == NULL && s2 == NULL) {
		return true;
	} else {
		return false;
	}
}
