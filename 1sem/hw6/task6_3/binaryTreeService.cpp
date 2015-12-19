#include "binaryTreeService.h"
#include <iostream>

using namespace std;


BinaryTreeNode* addNewElement(BinaryTreeNode*, int);
BinaryTreeNode* deleteElement(BinaryTreeNode*, int);
BinaryTreeNode* findMinElement(BinaryTreeNode*);
BinaryTreeNode* rotateRight(BinaryTreeNode*);
BinaryTreeNode* rotateLeft(BinaryTreeNode*);
BinaryTreeNode* balance(BinaryTreeNode*);
BinaryTreeNode* removeMinElement(BinaryTreeNode*);
void inAscendingOrderPrint(BinaryTreeNode*);
void inDescendingOrderPrint(BinaryTreeNode*);
void preorderTraversal(BinaryTreeNode*);
void updateHeight(BinaryTreeNode*);
int balanceFactor(BinaryTreeNode*);
int height(BinaryTreeNode*);


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
		newNode->height = 1;
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
	return balance(parentNode);
}


void removeElement(BinaryTree* thisTree, int forRemoval)
{
	thisTree->root = deleteElement(thisTree->root, forRemoval);
}


BinaryTreeNode* deleteElement(BinaryTreeNode* current, int forRemoval)
{
	if (current != nullptr)
	{
		if (forRemoval < current->value)
		{
			current->leftChild = deleteElement(current->leftChild, forRemoval);
		}
		else if (forRemoval > current->value)
		{
			current->rightChild = deleteElement(current->rightChild, forRemoval);
		}
		else
		{
			BinaryTreeNode *left = current->leftChild;
			BinaryTreeNode *right = current->rightChild;
			delete current;
			if (right == nullptr)
			{
				return left;
			}
			BinaryTreeNode *minElement = findMinElement(right);
			minElement->rightChild = removeMinElement(right);
			minElement->leftChild = left;
			return balance(minElement);
		}
		return balance(current);
	}
	else
	{
		return nullptr;
	}
}


BinaryTreeNode* removeMinElement(BinaryTreeNode *current)
{
	if (current->leftChild == 0)
	{
		return current->rightChild;
	}
	current->leftChild = removeMinElement(current->leftChild);
	return balance(current);
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


int height(BinaryTreeNode *node)
{
	return node ? node->height : 0;
}


int balanceFactor(BinaryTreeNode *node)
{
	return height(node->rightChild) - height(node->leftChild);
}


void updateHeight(BinaryTreeNode *node)
{
	int heightLeft = height(node->leftChild);
	int heightRight = height(node->rightChild);
	node->height = ((heightLeft > heightRight) ? heightLeft : heightRight) + 1;
}


BinaryTreeNode* balance(BinaryTreeNode* p)
{
	updateHeight(p);

	if (balanceFactor(p) == 2)
	{
		if (balanceFactor(p->rightChild) < 0)
			p->rightChild = rotateRight(p->rightChild);

		return rotateLeft(p);
	}

	if (balanceFactor(p) == -2)
	{
		if (balanceFactor(p->leftChild) > 0)
			p->leftChild = rotateLeft(p->leftChild);

		return rotateRight(p);
	}

	return p;
}


BinaryTreeNode* rotateRight(BinaryTreeNode* root)
{
	BinaryTreeNode* pivot = root->leftChild;
	root->leftChild = pivot->rightChild;
	pivot->rightChild = root;
	updateHeight(root);
	updateHeight(pivot);
	return pivot;
}


BinaryTreeNode* rotateLeft(BinaryTreeNode* root)
{
	BinaryTreeNode* pivot = root->rightChild;
	root->rightChild = pivot->leftChild;
	pivot->leftChild = root;
	updateHeight(root);
	updateHeight(pivot);
	return pivot;
}
