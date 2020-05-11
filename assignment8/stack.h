#include <iostream>


using namespace std;

template <class T>
class Stack {
private:
	struct StackNode {
		T data;
		StackNode *next;
	};
	StackNode *top;
	int size;
	int current_size = 0;

public:
	Stack() {
		this->size = -1;
		top = NULL;
	}
	Stack(int new_size) {
		this->size = new_size;
		top = NULL;
	}
	bool push(T element) {
		if(current_size == size) {
			try {
				throw "Stack full!";
			} catch (char const* a) {
				cerr << "Stack Overflow!" << endl;
				return false;
			}
		} else {
			StackNode *node;
			node = new StackNode;
			node->data = element;
			node->next = NULL;

			if(top != NULL) {
				node->next = top;
			}
			top = node;

			current_size++;
			cout << "Pushing: " << element << endl;
			return true;
		}
	}

	T pop() {
		if(top == NULL) {
			try {
				throw "Stack Empty!";
			} catch(char const* b) {
				cerr << "Stack Underflow!" << endl;
				return false;
			}
		} else {
			StackNode *temp;
			temp = top;
			T out = temp->data;
			cout << "Popping: " << out << endl;
			delete temp;
			top = top->next;
			current_size--;
			return out;
		}
	}	

	bool isEmpty() {
		if(top == NULL) {
			return true;
		} else {
			return false;
		}
	}

	void reverse() {
		if(top == NULL) {
			return;
		}

		StackNode *prev = NULL;
		StackNode *current = NULL;
		StackNode *next = NULL;

		cout << "Reversing Stack" << endl;

		current = top;

		while(current != NULL) {
			next = current->next;
			current->next = prev;
			prev = current;
			current = next;
		}

		top = prev;
	}
};

