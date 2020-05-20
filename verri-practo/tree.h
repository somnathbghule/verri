#ifndef tree_h
#define tree_h
#include <iostream>
#include <verri-practo.h>
using namespace std;
class tree;
class bst;
class node {

	public:
		node (int key=0) {
			right_=NULL;
			left_=NULL;
			key_=key;
		}
	private:
		node *right_;
		node *left_;
		int key_;
	friend class tree;
	friend class bst;
};

class tree {

	public:
		tree();
		~tree();
		node *insert(node *root, int val);
		node *root() { return root_; }
		void root(node *root) { root_=root; }
	private:
		node *root_;
};

class bst :public tree {
	
	public:
		bst();
		node *insert(node *root, int val);
		void inorder(node *root);
		int  totalNodes(node *root);
		bool isBST( node *root );
		~bst();
};

void bst_test();
#endif
