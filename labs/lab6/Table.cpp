#include "Table.h"

int count(node *root) {
	if (root == nullptr)
		return 0;
	return 1 + count(root->left) + count(root->right);
}

int sum(node *root) {
	if (root == nullptr)
		return 0;
	return root->data + sum(root->left) + sum(root->right);
}

int height(node *root) {
	if (root == nullptr)
		return 0;
	int left = height(root->left), right = height(root->right);
	return 1 + (left > right ? left : right);
}
