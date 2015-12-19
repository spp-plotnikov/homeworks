#include "binaryTreeService.h"
#include <iostream>

using namespace std;


BinaryTreeNode* addNewElement(BinaryTreeNode*, int);
BinaryTreeNode* deleteElement(BinaryTreeNode*, int);
BinaryTreeNode* findMinElement(BinaryTreeNode*);
void inAscendingOrderPrint(BinaryTreeNode*);
void inDescendingOrderPrint(BinaryTreeNode*);
void preorderTraversal(BinaryTreeNode*);


BinaryTree* createBinaryTree()
{
	BinaryTree *newTree = new BinaryTree;
	newTree->root = nullptr;
	return newTree;
}


void addElementToTree(BinaryTree *thisTree, int newValue)
{
	thisTree->root = addNewElement(thisTree->root, newValue);
}


BinaryTreeNode* addNewElement(BinaryTreeNode *parentNode, int newValue)
{
	if (parentNode == nullptr)
	{
		BinaryTreeNode *newNode = new BinaryTreeNode;
		newNode->value = newValue;
		newNode->leftChild = nullptr;
		newNode->rightChild = nullptr;
		return newNode;
	}
	else if (newValue < parentNode->value)
	{
		parentNode->leftChild = addNewElement(parentNode->leftChild, newValue);
	}
	else if (newValue > parentNode->value)
	{
		parentNode->rightChild = addNewElement(parentNode->rightChild, newValue);
	}
	return parentNode;
}


void removeElement(BinaryTree* thisTree, int forRemoval)
{
	thisTree->root = deleteElement(thisTree->root, forRemoval);
}


BinaryTreeNode* deleteElement(BinaryTreeNode* parentNode, int forRemoval)
{
	if (parentNode != nullptr)
	{
		if (forRemoval < parentNode->value)
		{
			parentNode->leftChild = deleteElement(parentNode->leftChild, forRemoval);
		}
		else if (forRemoval > parentNode->value)
		{
			parentNode->rightChild = deleteElement(parentNode->rightChild, forRemoval);
		}
		else if (parentNode->leftChild != nullptr && parentNode->rightChild != nullptr)
		{
			parentNode->value = findMinElement(parentNode->rightChild)->value;
			parentNode->rightChild = deleteElement(parentNode->rightChild, parentNode->value);
		}
		else
		{
			if (parentNode->leftChild != nullptr)
			{
				BinaryTreeNode *temp = parentNode->leftChild;
				delete parentNode;
				parentNode = temp;
			}
			else
			{
				BinaryTreeNode *temp = parentNode->rightChild;
				delete parentNode;
				parentNode = temp;
			}
		}
	}
	return parentNode;
}


void preorderTraversal(BinaryTree* thisTree)
{
	preorderTraversal(thisTree->root);
}


void preorderTraversal(BinaryTreeNode* current)
{
	if (current != nullptr)
	{
		cout << " (" << current->value;
		preorderTraversal(current->leftChild);
		preorderTraversal(current->rightChild);
		cout << ")";
	}
	else
	{
		cout << " null";
	}
}


BinaryTreeNode* findMinElement(BinaryTreeNode* thisNode)
{
	while (thisNode->leftChild != nullptr)
	{
		thisNode = thisNode->leftChild;
	}
	return thisNode;
}


bool belongsToTree(BinaryTree* thisTree, int targetValue)
{
	BinaryTreeNode* current = thisTree->root;
	while (current != nullptr)
	{
		if (current->value > targetValue)
		{
			current = current->leftChild;
		}
		else if (current->value < targetValue)
		{
			current = current->rightChild;
		}
		else
		{
			return true;
			break;
		}
	}
	return false;
}


void inOrderPrint(BinaryTree* thisTree, bool isAscending)
{
	/*
	Information for users of this function:
	This function prints elements of the tree in Ascending and Descending order.
	If you want to print elements in Ascending order you should call the function with an argument of True.
	Otherwise - with an argument of False.
	*/

	if (thisTree->root == nullptr)
	{
		cout << "The tree has no elements!" << endl;
	}
	else
	{
		(isAscending) ? inAscendingOrderPrint(thisTree->root) : inDescendingOrderPrint(thisTree->root);
		cout << endl;
	}
}


void inAscendingOrderPrint(BinaryTreeNode* current)
{
	if (current != nullptr)
	{
		inAscendingOrderPrint(current->leftChild);
		cout << current->value << " ";
		inAscendingOrderPrint(current->rightChild);
	}
}


void inDescendingOrderPrint(BinaryTreeNode* current)
{
	if (current != nullptr)
	{
		inDescendingOrderPrint(current->rightChild);
		cout << current->value << " ";
		inDescendingOrderPrint(current->leftChild);
	}
}


void removeTree(BinaryTree* forRemovalTree)
{
	while (forRemovalTree->root != nullptr)
	{
		removeElement(forRemovalTree, forRemovalTree->root->value);
	}
	delete forRemovalTree;
}