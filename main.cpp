#include <iostream>
#include "BinaryTree.h"
using namespace std;

int main() {

	//Construct the binary tree.
	BinaryTree<char> tree(9);
	tree.addNodeL(0,1);
	tree.addNodeR(0,2);
	tree.addNodeL(1,3);
	tree.addNodeR(1,4);
	tree.addNodeL(2,5);
	tree.addNodeR(2,6);
	tree.addNodeL(5,7);
	tree.addNodeR(5,8);

	tree.setElement(0,'a');
	tree.setElement(1,'b');
	tree.setElement(2,'c');
	tree.setElement(3,'d');
	tree.setElement(4,'e');
	tree.setElement(5,'f');
	tree.setElement(6,'g');
	tree.setElement(7,'h');
	tree.setElement(8,'i');

	if (tree.empty()) 
		return 0;

	tree.preOrder();
	tree.inOrder();
	tree.postOrder();
	tree.levelOrder();

	cout<<"The height of BinaryTree is: "<<tree.height()<<endl;
	return 0;
}
