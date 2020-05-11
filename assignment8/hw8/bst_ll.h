#include <iostream>

using namespace std;

// First we define functions that will be used in the implementation

struct node {
	int data;
	node* left;
	node* right;
};

node* create_node(int new_data) {
	node* new_node = new node();
	new_node->data = new_data;
	new_node->left = new_node->right = NULL;
	return new_node;
}

node* insert(node* root, int new_data) {
	if(root == NULL) {
		root = create_node(new_data);
	} else if (new_data <= root->data) {
		root->left = insert(root->left, new_data);
	} else {
		root->right = insert(root->right, new_data);
	} 

	return root;
}

// Now we write the algorithm for converting from BST to LL
// Runtime is O(n) since every node is accessed to reassign pointers.
// This is a recursive algorithm which calls itself on a given node's
// children.

void bst_ll(node *root, node **head) {
	if(root == NULL) {
		return;
	}

	static node *prev = NULL;
	
	bst_ll(root->left, head);

	if(prev == NULL) {
		*head = root;
	} else {
		root->left = prev;
		prev->right = root;
	}

	prev = root;

	bst_ll(root->right, head);
}


void print_bst(node *root) {
	if(root != NULL) {
		cout << root->data << " ";
		print_bst(root->left);
		print_bst(root->right);
	}
}


void print_list(node *root) {
	while(root != NULL) {
		cout << root->data << " ";
		root = root->right;
	}
}

int count_nodes(node *root) {
	int counter = 0;
	while(root != NULL) {
		counter++;
		root = root->right;
	}

	return counter;
}


node* ll_bst(node **head, int beg, int end) {
	if(beg > end) {
		return NULL;
	}

	int root_i = beg + (end-beg/2);

	node *c = *head;

	int i = 0;

	while(i < root_i && c->right != NULL) {
		c = c->right;
		i++;
	}

	node *root = create_node(c->data);
	root->left = ll_bst(head, beg, root_i-1);
	root->right = ll_bst(head, root_i+1, end);

	return root;
}

// we can overload this function

node* ll_bst(node *head) {
	int n = count_nodes(head);
	return ll_bst(&head, 0, n-1);
}







