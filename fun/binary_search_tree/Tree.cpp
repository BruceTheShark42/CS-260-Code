#include "Tree.h"

template<class T> Tree<T>::Tree(const T& data) : data(data), left(nullptr), right(nullptr) {}

template<class T> Tree<T>::~Tree() { deleteRec(this); }
template<class T> void Tree<T>::deleteRec(Tree<T> *tree) {
	Tree *left = tree->left;
	if (left != nullptr) {
		deleteRec(left);
		delete left;
	}
	Tree *right = tree->right;
	if (right != nullptr) {
		deleteRec(tree->right);
		delete right;
	}
}

template<class T> Tree<T>* Tree<T>::getLeft() const { return left; }
template<class T> Tree<T>* Tree<T>::setLeft(Tree<T> *tree) {
	Tree *oldLeft = left;
	left = tree;
	return oldLeft;
}

template<class T> Tree<T>* Tree<T>::getRight() const { return right; }
template<class T> Tree<T>* Tree<T>::setRight(Tree<T> *tree) {
	Tree *oldRight = right;
	right = tree;
	return oldRight;
}

template<class T> T Tree<T>::getData() const { return data; }
template<class T> T Tree<T>::setData(const T &data) {
	T oldData = this->data;
	this->data = data;
	return oldData;
}

template<class T> T Tree<T>::getSum() { return getSumRec(this); }
template<class T> T Tree<T>::getSumRec(Tree<T> *tree) {
	return tree == nullptr ? 0 : tree->data + getSumRec(tree->left) + getSumRec(tree->right);
}

template<class T> unsigned int Tree<T>::getTotalNodes() { return getTotalNodesRec(this); }
template<class T> unsigned int Tree<T>::getTotalNodesRec(Tree<T> *tree) {
	return tree == nullptr ? 0 : 1 + getTotalNodesRec(tree->left) + getTotalNodesRec(tree->right);
}

template<class T> unsigned int Tree<T>::getTotalLeaves() { return getTotalLeavesRec(this); }
template<class T> unsigned int Tree<T>::getTotalLeavesRec(Tree<T> *tree) {
	if (tree == nullptr)
		return 0;
	if (tree->left == nullptr && tree->right == nullptr)
		return 1;
	return getTotalLeavesRec(tree->left) + getTotalLeavesRec(tree->right);
}

template<class T> unsigned int Tree<T>::getHeight() { return getHeightRec(this); }
template<class T> unsigned int Tree<T>::getHeightRec(Tree<T> *tree) {
	if (tree == nullptr)
		return 0;
	unsigned int leftHeight = getHeightRec(tree->left);
	unsigned int rightHeight = getHeightRec(tree->right);
	return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}
