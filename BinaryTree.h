#ifndef binary_tree_h
#define binary_tree_h
#include <iostream>
#include <stdexcept>
#include <sstream>
#include <list>
#include "BinaryTreeNode.h"
using namespace std;

template <class T>
class BinaryTree {
	public:
		BinaryTree(BinaryTreeNode<T> *r=NULL):root(r){}
		BinaryTree(int node_num);
		~BinaryTree();

		void addNodeL(int i, int j);
		void addNodeR(int i, int j);
		void setElement(int i, T theElement);
		bool empty() const {
			return theSize==0;
		}
		int size() const {
			return theSize;
		}
		void preOrder();
		void inOrder();
		void postOrder();
		void levelOrder();
		int height() {
			return height(root);
		}

	private:
		BinaryTreeNode<T> *root;
		int theSize;
		void preOrder(BinaryTreeNode<T> *parent);
		void inOrder(BinaryTreeNode<T> *parent);
		void postOrder(BinaryTreeNode<T> *parent);
		void levelOrder(BinaryTreeNode<T> *parent);
		int height(BinaryTreeNode<T> *parent);
};

//make the array<BinaryTreeNode<T>> [node_num]
template <class T>
BinaryTree<T>::BinaryTree(int node_num) {
	if (node_num<=0) {
		ostringstream s;
		s<<"Number of nodes is: "<<node_num<<", must be larger than 1."<<endl;
		throw invalid_argument(s.str());
	}

	root=new BinaryTreeNode<T>[node_num];
	theSize=node_num;
}

//delete the array
template <class T>
BinaryTree<T>::~BinaryTree() {
	if (root!=NULL) delete []root;
}

//set the elements of the tree
template <class T>
void BinaryTree<T>::setElement(int i, T theElement) {
	root[i].element=theElement;
}

//join father and left child	
template <class T>
void BinaryTree<T>::addNodeL(int i, int j) {
	root[i].leftChild=&root[j];
	root[j].father=&root[i];
}

//join father and right child
template <class T>
void BinaryTree<T>::addNodeR(int i, int j) {
    root[i].rightChild=&root[j];
    root[j].father=&root[i];
}

//Pre-order output
template <class T>
void BinaryTree<T>::preOrder() {
	cout<<"Pre-order output:"<<endl;
	preOrder(root);
	cout<<endl;
}

template <class T>
void BinaryTree<T>::preOrder(BinaryTreeNode<T> *root) {
	if (root!=NULL) {
		cout<<root->element<<" ";
		preOrder(root->leftChild);
		preOrder(root->rightChild);
	}
}

//In-order output
template <class T>
void BinaryTree<T>::inOrder() {
    cout<<"In-order output:"<<endl;
    inOrder(root);
	cout<<endl;
}

template <class T>
void BinaryTree<T>::inOrder(BinaryTreeNode<T> *root) {
	if (root!=NULL) {
	    inOrder(root->leftChild);
	    cout<<root->element<<" ";
	    inOrder(root->rightChild);
	}
}

//Post-order output
template <class T>
void BinaryTree<T>::postOrder() {
    cout<<"Post-order output:"<<endl;
    postOrder(root);
	cout<<endl;
}

template <class T>
void BinaryTree<T>::postOrder(BinaryTreeNode<T> *root) {
    if (root!=NULL) {
        postOrder(root->leftChild);
        postOrder(root->rightChild);
        cout<<root->element<<" ";
    }
}

//Level-order output
template <class T>
void BinaryTree<T>::levelOrder() {
	cout<<"Level-order output:"<<endl;
	levelOrder(root);
	cout<<endl;
}

template <class T>
void BinaryTree<T>::levelOrder(BinaryTreeNode<T> *root) {
	list<BinaryTreeNode<T> *> list1;
	while (root!=NULL) {
		cout<<root->element<<" ";
		if (root->leftChild!=NULL) list1.push_back(root->leftChild);
		if (root->rightChild!=NULL) list1.push_back(root->rightChild);

		if (list1.empty()) return;

		root=list1.front();
		list1.pop_front();
	}
}

//The height of tree
template <class T>
int BinaryTree<T>::height(BinaryTreeNode<T> *root) {
	if (root==NULL) return 0;

	int hl=height(root->leftChild);
	int hr=height(root->rightChild);

	return hl>hr ? ++hl:++hr;
}

#endif
