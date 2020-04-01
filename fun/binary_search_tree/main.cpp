#include <iostream>
#include "Tree.h"

int main() {
	Tree<int> tree(7);
	tree.setLeft(new Tree<int>(9));
	std::cout << "thing: " << tree.getLeft() << '\n';//->setLeft(new Tree<int>(14));
//	tree.getRight()->setRight(new Tree<int>(6));
//	tree.setRight(new Tree<int>(2));
//	std::cout << "Sum: " << tree.getSum() << '\n';
//	std::cout << "Total Nodes: " << tree.getTotalNodes() << '\n';
//	std::cout << "Total Leaves: " << tree.getTotalLeaves() << '\n';
//	std::cout << "Height: " << tree.getHeight() << '\n';
	return 0;
}
