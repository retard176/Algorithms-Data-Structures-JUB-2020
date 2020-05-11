#include <iostream>
#include <ctime>
#include <cstdlib>
#include "bst_ll.h"

using namespace std;

int main() {
	srand(time(NULL));

	node* tree;
	tree = NULL;

	for(int i = 0; i < 15; i++) {
		tree = insert(tree, rand() % 20 + 1);
	}

	cout << "Printing Tree: ";
	print_bst(tree);
	cout << endl;

	node *list = NULL;

	bst_ll(tree, &list);
	cout << "Printing List: ";
	print_list(list);
	cout << endl;
	tree = ll_bst(list);
	print_bst(tree);
	cout << endl;

	return 0;
}
