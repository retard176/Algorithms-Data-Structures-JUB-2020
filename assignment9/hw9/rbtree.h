/*
	Algorithms & Data Structures Spring 2020
	Prof. Dr. Kinga Lipskoch
	Written by Harit Krishan
	Assistance from Github.com, GeeksforGeeks.com
*/


#include <bits/stdc++.h>

using namespace std;

enum Color{RED, BLACK};

struct Node {
	int data;
	Color color;
	Node *left, *right, *parent;
};

class RedBlackTree {
	private:
		Node* root;

	protected:
		void rotateLeft(Node *&root, Node *&a) {
			//cout << "Applying Left Rotation!" << endl;
			Node *p = a->right;
			a->right = p->left;

			if(a->right != NULL) {
				a->right->parent = a;
			}

			p->parent = a->parent;

			if(a->parent == NULL) {
				this->root = p;
			} else if (a == a->parent->left) {
				a->parent->left = p;
			} else {
				a->parent->right = p;
			}

			p->left = a;
			a->parent = p;
		}

		void rotateRight(Node *&root, Node *&a) {
			//cout << "Applying Right Rotation!" << endl;
			Node *p = a->left;
			a->left = p->right;

			if(a->left != NULL) {
				a->left->parent = a;
			}

			p->parent = a->parent;

			if(a->parent == NULL) {
				root = p;
			} else if(a == a->parent->left) {
				a->parent->left = p;
			} else {
				a->parent->right = p;
			}

			p->right = a;
			a->parent = p;
		}

		Node* createNode(int new_data) {
			Node *newNode = new Node;
			newNode->data = new_data;
			newNode->color = RED;
			newNode->parent = NULL;
			newNode->left = NULL;
			newNode->right = NULL;
			return newNode;
		}

		Node* bstinsert(Node* &root, Node* &newNode) {
			if(root == NULL) {
				return newNode;
			}

			if(newNode->data < root->data) {
				root->left = bstinsert(root->left, newNode);
				root->left->parent = root;
			} else if (newNode->data > root->data) {
				root->right = bstinsert(root->right, newNode);
				root->right->parent = root;
			}

			return root;
		}

		void transplant(Node* &root, Node *&a, Node *&b) {
			if(b == NULL) {
				return;
			}

			if(a->parent == NULL) {
				root = b;
			} else if(a != NULL && a == b->parent->left) {
				a->parent->left = b;
			} else {
				a->parent->right = b;
			}

			if(b != NULL) 
				b->parent = a->parent;
		}

		Node* treemin(Node * node) {
			Node *min = node;
			while(min->left != NULL) {
				min = min->left;
			}

			return min;
		}

		void deletefix(Node *&root, Node *&x) {
			cout << "Fixing Order of Tree!" << endl;
			Node *w;
			while(x != NULL && x->color == BLACK) {
				if(x == x->parent->left) {
					w = x->parent->right;
					if(w != NULL && w->color == RED) {
						w->color = BLACK;
						x->parent->color = RED;
						rotateLeft(root, x->parent);
						w = x->parent->right;
					}


					if(w->left->color == BLACK && w->right->color == BLACK) {
						w->color = RED;
						x = x->parent;
					} else if(w->right->color == BLACK) {
						w->left->color = BLACK;
						w->color = RED;
						rotateRight(root, w);
						w = x->parent->right;
					}

					w->color = x->parent->color;
					x->parent->color = BLACK;
					w->right->color = BLACK;
					rotateLeft(root, x->parent);
					x = root;
				} else {
					w = x->parent->left;

					if(w != NULL && w->color == RED) {
						w->color = BLACK;
						x->parent->color = RED;
						rotateRight(root, x->parent);
						w = x->parent->left;
					}

					if(w->right->color == BLACK && w->left->color == BLACK) {
						w->color = RED;
						x = x->parent;
					} else if(w->left->color == BLACK) {
						w->right->color = BLACK;
						w->color = RED;
						rotateLeft(root, w);
						w = x->parent->left;
					}
				}

				w->color = x->parent->color;
				x->parent->color = BLACK;
				w->left->color = BLACK;
				rotateRight(root, x->parent);
				x = root;
			}

			if(x != NULL)
				x->color = BLACK;
		}

		

	public:
		RedBlackTree() {
			cout << "\nTree Created!\n" << endl;
			root = NULL;
		}

		void insertfix(Node* &root, Node* &z) {
			Node *parent = nullptr;
			Node *grandparent = nullptr;

			while((z != root) && (z->color == RED) && (z->parent != nullptr) && 
				(z->parent->color == RED)) {
				parent = z->parent;
				grandparent = z->parent->parent;

				if(parent == grandparent->left) {
					Node *uncle = grandparent->right;
			/*
				Case 1: RED UNCLE -- Recolor parent & uncle
			*/
					if(uncle != nullptr && uncle->color == RED) {
						grandparent->color = RED;
						parent->color = BLACK;
						uncle->color = BLACK;
						z = grandparent;
					} else {
				/*
					Case 2: RIGH CHILD -- Left Rotate
				*/
						if (z == parent->right) {
							z = parent;
							rotateLeft(root, parent);
							parent = z->parent;					
						}
				/*
					Case 3: LEFT CHILD -- Right Rotate
				*/
						parent->color = BLACK;
						grandparent->color = RED;
						rotateRight(root, grandparent);
						z = parent;
					}
				} else {
					Node *uncle = grandparent->left;
			/*
				Case 1: RED UNCLE -- Recolor parent & uncle
			*/
					if(uncle != nullptr && uncle->color == RED) {
						grandparent->color = RED;
						parent->color = BLACK;
						uncle->color = BLACK;
						z = grandparent;
					} else {
				/*
					Case 2: RIGH CHILD -- Left Rotate
				*/
						if (z == parent->left) {
							rotateRight(root, parent);
							z = parent;
							parent = z->parent;					
						}
				/*
					Case 3: LEFT CHILD -- Right Rotate
				*/	
						parent->color = BLACK;
						grandparent->color = RED;
						rotateLeft(root, grandparent);
						z = parent;
					}
				}
			}

			root->color = BLACK;
		}

		void insert(int new_data) {
			Node *newNode;
			newNode = createNode(new_data);
			root = bstinsert(root, newNode);
			//cout << endl << new_data << " inserted!" << endl;
			insertfix(root, newNode);
		}

		void del(Node * j) {
			if(j == NULL) 
				return;

			Node* p = search(j->data);
			Node *node = search(j->data);
			Color p_orig = p->color;
			Node* x;

			if(node->left == NULL) {
				x = node->right;
				transplant(this->root, node, node->right);
			} else if (node->right == NULL) {
				x = node->left;
				transplant(this->root, node, node->left);
			} else {
				p = treemin(node->right);
				p_orig = p->color;
				x = p->right;

				if(p->parent == node && x != NULL) {
					x->parent = p;
				} else {
					transplant(this->root, p, p->right);
					p->right = node->right;

					if(p->right != NULL) {
						p->right->parent = p;
					}
				}
				transplant(this->root, p, node);
				p->left = node->left;
				if(p->left != NULL) {
					p->left->parent = p;
				}

				p->color = node->color;
			}

			if(p_orig == BLACK) {
				deletefix(this->root, x);
			}
		}

		Node * predecessor(const Node *&node) {
			Node *temp = NULL;

			if(node->right != NULL)  {
				temp = node->left;

				while(temp->right != NULL) {
					temp = temp->right;
				}
			} else {
				temp = node->right;

				while(temp->left != NULL) {
					temp = temp->left;
				}
			}

			return temp;
		}

		Node * successor(const Node *&node) {
			Node *temp = NULL;

			if(node->left != NULL) {
				temp = node->left;

				while(temp->right != NULL) {
					temp = temp->right;
				}
			} else {
				temp = node->right;

				while(temp->left != NULL) {
					temp = temp->right;
				}
			}
			return temp;
		}

		Node * getMinimum() {
			if(root == NULL) 
				throw "Tree is Empty!";

			Node *min = root;

			while(min->left != NULL) {
				min = min->left;
			}

			return min;
		}

		Node * getMaximum() {
			if(root == NULL) {
				throw "Tree is Empty!";
			}

			Node *max = root;

			while(max->right != NULL) {
				max = max->right;
			}

			return max;
		}

		Node * search(int key) {
			Node *p = root;
			int flag = 0;

			if(root == NULL) {
				cout << "Tree is Empty!" << endl;
				return root;
			}

			while(p != NULL && flag == 0) {
				if(p->data == key) {
					flag = 1;
				}

				if(flag == 0) {
					if(p->data < key)
						p = p->right;
					else 
						p = p->left;
				}
			}

			if(flag == 0) {
				cout << "Element not found!" << endl;
				return root;
			} else {
				return p;
			}
		}

		void rbtprint_text() {
			rbtprint_text(this->root);
		}

		void rbtprint_text(Node* &node)const {
			if (node == NULL)
				return;

			if (node->parent == NULL) {
				cout << node->data << "(" << node->color << ") is root" << endl;
			} else if(node->parent->left==node) {
				cout << node->data << "(" << node->color << ") is "<<node->parent->data <<"'s "<<"left child" << endl;
			} else {
				cout << node->data << "(" << node->color << ") is " << node->parent->data << "'s " << "right child" << endl;
			}

			rbtprint_text(node->left);
			rbtprint_text(node->right);

		}

		void order() {
			order(this->root);
		}

		void order(Node* &root) {
			if(root == NULL) 
				return;

			if(root->color == BLACK)
				cout << root->data << "B ";
			else if(root->color == RED)
				cout << root->data << "R ";

			order(root->left);
			order(root->right);
		}


};
