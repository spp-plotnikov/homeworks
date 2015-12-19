#include "binaryTreeService.h"
#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;

void displayComments();

int main()
{
	BinaryTree *tree = createBinaryTree();
	displayComments();

	int userCommand = 0;
	int value = 0;
	bool isNotNull = true;
	do
	{
		cin >> userCommand;
		isNotNull = userCommand != 0;
		switch (userCommand)
		{
		case 1:
		{
			cout << "Enter the value you want to add." << endl;
			cin >> value;
			addElementToTree(tree, value);
			break;
		}
		case 2:
		{
			cout << "Enter the value you want to remove." << endl;
			cin >> value;
			removeElement(tree, value);
			break;
		}
		case 3:
		{
			cout << "Enter the value you want to find in the tree." << endl;
			cin >> value;
			if (belongsToTree(tree, value))
			{
				cout << "There is" << endl;
			}
			else
			{
				cout << "There no" << endl;
			}
			break;
		}
		case 4:
		{
			cout << "Values are printed in ascending order:" << endl;
			inOrderPrint(tree, true);
			break;
		}
		case 5:
		{
			cout << "Values are printed in descending order:" << endl;
			inOrderPrint(tree, false);
			break;
		}
		case 6:
		{
			cout << "Values are printed in preorder:" << endl;
			preorderTraversal(tree);
			cout << endl;
			break;
		}

		default:
		{
			if (isNotNull)
			{
				cout << "Error: Unknown command!" << endl;
			}
			break;
		}
		}
		if (isNotNull)
		{
			cout << "You can continue" << endl;
		}
	} while (isNotNull);

	removeTree(tree);
	return 0;
}

void displayComments()
{
	cout << "------------------------------------" << endl;
	cout << "This program is for working with binary search tree." << endl;
	cout << "You can use following comands:" << endl;
	cout << "0 - exit" << endl;
	cout << "1 - add new element" << endl;
	cout << "2 - remove the element" << endl;
	cout << "3 - check that the value belongs to the tree" << endl;
	cout << "4 - print in ascending order" << endl;
	cout << "5 - print in descending order" << endl;
	cout << "6 - print in preorder (Node LeftSubtree(...) RightSubtree(...))" << endl;
	cout << "------------------------------------" << endl;
	cout << "You can get started" << endl;
}