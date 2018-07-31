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
	//inOrder
	if (thisNode == nullptr)
		throw invalid_argument("Invalid inputs.");

	if (thisNode->rightChild != nullptr) {
		//with right child.
		BinaryTreeNode<char> *pNode = thisNode->rightChild;
		while (pNode->leftChild != nullptr) {
			pNode = pNode->leftChild;
		}
		return pNode;
	}
	else if (thisNode->rightChild == nullptr && thisNode->father == nullptr) {
		//without right child, without father.
		return nullptr;
	}
	else if (thisNode->rightChild == nullptr && thisNode == thisNode->father->leftChild) {
		//without right child, being the left child of father.
		return thisNode->father;
	}
	else {
		//without right child, being the right child of father.
		BinaryTreeNode<char> *pTemp = thisNode;
		while (pTemp->father != nullptr && pTemp != pTemp->father->leftChild) {
			pTemp = pTemp->father;
		}
		//being the last node.
		if (pTemp->father == nullptr) return nullptr;
		else return pTemp->father;
	}
}

template<class T>
BinaryTreeNode<T> *nextNodePre(BinaryTreeNode<T> *thisNode) {
	//preOrder
	if (thisNode == nullptr)
		throw invalid_argument("Invalid inputs.");

	if (thisNode->leftChild != nullptr) {
		//左子树不为空，返回左子树。
		return thisNode->leftChild;
	}

	else if (thisNode->father == nullptr || thisNode->rightChild != nullptr) {
		//左子树为空，且右子树不为空，或者左子树为空，没有父节点，返回右子树。
		return thisNode->rightChild;
	}

	else if (thisNode == thisNode->father->leftChild) {
		//叶节点，有父节点，同时是父节点的左子树。返回父节点的右子树，如果父节点没有右子树，就找父节点的父节点，知道找到一个有右子树的父节点，将右子树返回。如果实在找不到就返回nullptr。
		BinaryTreeNode<T> *pTemp = thisNode;
		while (pTemp->father != nullptr) {
			pTemp = pTemp->father;
			if (pTemp->rightChild != nullptr) {
				return pTemp->rightChild;
			}
		}
		return pTemp->rightChild;
	}

	else {
		//叶节点，有父节点，同时是父节点的右子树。则往上找，找到某一层父节点，该节点是其父节点的左子树，如果该节点的父节点有右子树，则返回右子树，否则就继续往上找，实在找不到就返回nullptr。
		BinaryTreeNode<T> *pTemp = thisNode;
		while (pTemp->father != nullptr && pTemp->father->father != nullptr) {
			pTemp = pTemp->father;
			if (pTemp == pTemp->father->leftChild && pTemp->father->rightChild != nullptr) {
				return pTemp->father->rightChild;
			}
		}
		return nullptr;
	}
}

template <class T>
void print(BinaryTreeNode<T> *pNode) {
	if (pNode != nullptr) {
		cout<<pNode->element<<endl;
	}
	else {
		cout<<"nullptr"<<endl;
	}
}

void test1() {
	cout<<"test1:"<<endl;
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

void test2() {
	cout<<"test2:"<<endl;
	BinaryTreeNode<char> *a = new BinaryTreeNode<char> ('a');
	BinaryTreeNode<char> *b = new BinaryTreeNode<char> ('b');
	BinaryTreeNode<char> *c = new BinaryTreeNode<char> ('c');

	addLeft(a, b);
	addLeft(b, c);

	cout<<nextNode(c)->element<<endl;
	cout<<nextNode(b)->element<<endl;
	if (nextNode(a) == nullptr) {
		cout<<"nullptr"<<endl;
	}
	delete a;
	delete b;
	delete c;
}

void test3() {
	cout<<"test3:"<<endl;
	BinaryTreeNode<char> *a = new BinaryTreeNode<char> ('a');
	BinaryTreeNode<char> *b = new BinaryTreeNode<char> ('b');
	BinaryTreeNode<char> *c = new BinaryTreeNode<char> ('c');

	addRight(a, b);
	addRight(b, c);

	cout<<nextNode(a)->element<<endl;
	cout<<nextNode(b)->element<<endl;
	if (nextNode(c) == nullptr) {
		cout<<"nullptr"<<endl;
	}
	delete a;
	delete b;
	delete c;
}

void test4() {
	cout<<"test4:"<<endl;
	BinaryTreeNode<char> *a = new BinaryTreeNode<char> ('a');
	if (nextNode(a) == nullptr) {
		cout<<"nullptr"<<endl;
	}
	delete a;
}

void test5() {
	cout<<"test5:"<<endl;
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
	cout<<nextNodePre(aNode)->element<<endl;
	cout<<nextNodePre(bNode)->element<<endl;
	cout<<nextNodePre(dNode)->element<<endl;
	cout<<nextNodePre(eNode)->element<<endl;
	cout<<nextNodePre(hNode)->element<<endl;
	cout<<nextNodePre(iNode)->element<<endl;
	cout<<nextNodePre(cNode)->element<<endl;
	cout<<nextNodePre(fNode)->element<<endl;
	if (nextNodePre(gNode) == nullptr) {
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

void test6() {
	cout<<"test6:"<<endl;
	BinaryTreeNode<char> *a = new BinaryTreeNode<char> ('a');
	BinaryTreeNode<char> *b = new BinaryTreeNode<char> ('b');
	BinaryTreeNode<char> *c = new BinaryTreeNode<char> ('c');

	addLeft(a, b);
	addLeft(b, c);

	print(nextNodePre(a));
	print(nextNodePre(b));
	print(nextNodePre(c));

	delete a;
	delete b;
	delete c;
}

void test7() {
	cout<<"test7:"<<endl;
	BinaryTreeNode<char> *a = new BinaryTreeNode<char> ('a');
	BinaryTreeNode<char> *b = new BinaryTreeNode<char> ('b');
	BinaryTreeNode<char> *c = new BinaryTreeNode<char> ('c');

	addRight(a, b);
	addRight(b, c);

	print(nextNodePre(a));
	print(nextNodePre(b));
	print(nextNodePre(c));

	delete a;
	delete b;
	delete c;
}

void test8() {
	cout<<"test8:"<<endl;
	BinaryTreeNode<char> *a = new BinaryTreeNode<char> ('a');
	print(nextNodePre(a));

	delete a;
}

int main() {
/*	test1();
	test2();
	test3();
	test4();*/
	test5();
	test6();
	test7();
	test8();
	return 0;
}
