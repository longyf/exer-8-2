#ifndef binary_tree_node_h
#define binary_tree_node_h

template <class T>
struct BinaryTreeNode {
	T element;
	BinaryTreeNode<T> *leftChild;
	BinaryTreeNode<T> *rightChild;
	BinaryTreeNode<T> *father;
	BinaryTreeNode(T val) : element(val), leftChild(nullptr), rightChild(nullptr), father(nullptr) {};
};
#endif
