#include "table.h"

//Please put the impelementation of the required functions here

int sumOfLeafNodes(node *root) {
	if (root) {
		if (!root->left && !root->right)
			return root->data;
		
		int sum = 0;
		if (root->left)
			sum = sumOfLeafNodes(root->left);
		if (root->right)
			sum += sumOfLeafNodes(root->right);
		return sum;
	}
	return 0;
}

void copyEven(node *root, node *&newRoot) {
	if (root) { // if the node exists
		if (root->data % 2 == 0) { // if the node's data is even
			insert(newRoot, root->data);
		}
		copyEven(root->left, newRoot);
		copyEven(root->right, newRoot);
	}
}

void insert(node *&root, int data) {
	if (root) {
		if (data < root->data) {
			if (root->left) insert(root->left, data);
			else makeNewNode(root->left, data);
		} else { // groups equal nodes with greater than nodes
			if (root->right) insert(root->right, data);
			else makeNewNode(root->right, data);
		}
	} else {
		makeNewNode(root, data);
	}
}

void makeNewNode(node *&n, int data) {
	n = new node();
	n->data = data;
	n->left = n->right = nullptr;
}
