#pragma once

struct  BinaryTreeNode
{
	int value;
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
__declspec(dllexport)  void inOrderPrint(BinaryTree*, bool);
__declspec(dllexport)  void preorderTraversal(BinaryTree*);
__declspec(dllexport)  void removeTree(BinaryTree*);