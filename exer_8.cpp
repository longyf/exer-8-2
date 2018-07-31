#include <iostream>
#include "BinaryTreeNode.h"
#include <stdexcept>
using namespace std;

template <class T>
void addLeft(BinaryTreeNode<T> *root, BinaryTreeNode<T> *left) {
	root->leftChild = left;
	left->father = root;
}

template <class T>
void addRight(BinaryTreeNode<T> *root, BinaryTreeNode<T> *right) {
	root->rightChild = right;
	right->father = root;
}

template <class T>
BinaryTreeNode<T> *nextNode(BinaryTreeNode<T> *thisNode) {
	if (thisNode == nullptr)
		throw invalid_argument("Invalid inputs.");

	if (thisNode->rightChild == nullptr && thisNode == thisNode->father->leftChild) {
		return thisNode->father;
	}
	else if (thisNode->rightChild != nullptr) {
		BinaryTreeNode<char> *pNode = new BinaryTreeNode<char>('0');
		pNode = thisNode->rightChild;
		while (pNode->leftChild != nullptr) {
			pNode = pNode->leftChild;
		}
		return pNode;
	}
	else {
		BinaryTreeNode<char> *pTemp = new BinaryTreeNode<char>('0');
		pTemp = thisNode;
		while (pTemp->father != nullptr && pTemp != pTemp->father->leftChild) {
			pTemp = pTemp->father;
		}
		if (pTemp->father == nullptr) return nullptr;
		else return pTemp->father;
	}
}

void test1() {
	//construct the binary tree.
	BinaryTreeNode<char> *aNode = new BinaryTreeNode<char> ('a');
	BinaryTreeNode<char> *bNode = new BinaryTreeNode<char> ('b');
	BinaryTreeNode<char> *cNode = new BinaryTreeNode<char> ('c');
	BinaryTreeNode<char> *dNode = new BinaryTreeNode<char> ('d');
	BinaryTreeNode<char> *eNode = new BinaryTreeNode<char> ('e');
	BinaryTreeNode<char> *fNode = new BinaryTreeNode<char> ('f');
	BinaryTreeNode<char> *gNode = new BinaryTreeNode<char> ('g');
	BinaryTreeNode<char> *hNode = new BinaryTreeNode<char> ('h');
	BinaryTreeNode<char> *iNode = new BinaryTreeNode<char> ('i');
	//
	addLeft(aNode, bNode);
	addRight(aNode, cNode);
	//
	addLeft(bNode, dNode);
	addRight(bNode, eNode);
	//
	addLeft(cNode, fNode);
	addRight(cNode, gNode);
	//
	addLeft(eNode, hNode);
	addRight(eNode, iNode);

	//obtain the result.
	cout<<nextNode(dNode)->element<<endl;
	cout<<nextNode(bNode)->element<<endl;
	cout<<nextNode(hNode)->element<<endl;
	cout<<nextNode(eNode)->element<<endl;
	cout<<nextNode(iNode)->element<<endl;
	cout<<nextNode(aNode)->element<<endl;
	cout<<nextNode(fNode)->element<<endl;
	cout<<nextNode(cNode)->element<<endl;
	if (nextNode(gNode) == nullptr) {
		cout<<"nullptr"<<endl;
	}

	delete aNode;
	delete bNode;
	delete cNode;
	delete dNode;
	delete eNode;
	delete fNode;
	delete gNode;
	delete hNode;
	delete iNode;
}

int main() {
	test1();
	return 0;
}
