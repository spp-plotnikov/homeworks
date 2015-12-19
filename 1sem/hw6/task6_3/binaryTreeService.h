#pragma once

struct  BinaryTreeNode
{
	int value;
	int height;
	BinaryTreeNode *leftChild;
	BinaryTreeNode *rightChild;
};


struct BinaryTree
{
	BinaryTreeNode *root;
};


__declspec(dllexport)  BinaryTree* createBinaryTree();
__declspec(dllexport)  bool belongsToTree(BinaryTree*, int);
__declspec(dllexport)  void addElementToTree(BinaryTree*, int);
__declspec(dllexport)  void removeElement(BinaryTree*, int);
__declspec(dllexport)  void preorderTraversal(BinaryTree*);
__declspec(dllexport)  void removeTree(BinaryTree*);

/*
Information for users of this function:
This function prints elements of the tree in Ascending and Descending order.
If you want to print elements in Ascending order you should call the function with an argument of True.
Otherwise - with an argument of False.
*/
__declspec(dllexport)  void inOrderPrint(BinaryTree*, bool);