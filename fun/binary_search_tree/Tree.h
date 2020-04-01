#ifndef TREE_H
#define TREE_H
template<class T>
class Tree {
public:
	Tree(const T& data);
	~Tree();
	
	Tree* getLeft() const;
	// Returns old left
	Tree* setLeft(Tree *tree);
	
	Tree* getRight() const;
	// Returns old right
	Tree* setRight(Tree *tree);
	
	T getData() const;
	// Returns old data
	T setData(const T &data);
	
	T getSum();
	unsigned int getTotalNodes();
	unsigned int getTotalLeaves();
	unsigned int getHeight();
private:
	void deleteRec(Tree *tree);
	T getSumRec(Tree *tree);
	unsigned int getTotalNodesRec(Tree *tree);
	unsigned int getTotalLeavesRec(Tree *tree);
	unsigned int getHeightRec(Tree *tree);
	
	T data;
	Tree *left, *right;
};

template class Tree<int>;
#endif
