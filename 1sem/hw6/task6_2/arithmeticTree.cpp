#include "arithmeticTree.h"

using namespace std;

struct TreeNode
{
	double value;
	char sign;
	TreeNode *left = nullptr;
	TreeNode *right = nullptr;
};


double calculateTheTree(TreeNode*);
void printTheTree(TreeNode*);
TreeNode* readTheNode(FILE*);


void calculateAndPrintTree(FILE *userInputFile)
{
	TreeNode *root = readTheNode(userInputFile);
	cout << calculateTheTree(root) << endl;
	printTheTree(root);
}


TreeNode* readTheNode(FILE *userInputFile)
{
	char symbol = fgetc(userInputFile);
	while (symbol == ' ' || symbol == ')')
	{
		symbol = fgetc(userInputFile);
	}
	TreeNode *newNode = new TreeNode;
	if (symbol == '(')
	{
		newNode->sign = fgetc(userInputFile);
		newNode->left = readTheNode(userInputFile);
		newNode->right = readTheNode(userInputFile);
	}
	else
	{
		newNode->sign = '$';
		double number = 0;
		while (symbol != ')' && symbol != '\0' && symbol != '\n' && symbol != ' ')
		{
			number *= 10;
			number += (int(symbol) - int('0'));
			symbol = fgetc(userInputFile);
		}
		newNode->value = number;
	}
	return newNode;
}


double calculateTheTree(TreeNode* current)
{
	if (current->sign == '$')
	{
		return current->value;
	}
	else
	{
		double leftValue = calculateTheTree(current->left);
		double rightValue = calculateTheTree(current->right);

		switch (current->sign)
		{
		case '*':
		{
			return leftValue * rightValue;
			break;
		}
		case '/':
		{
			return leftValue / rightValue;
			break;
		}
		case '+':
		{
			return leftValue + rightValue;
			break;
		}
		case '-':
		{
			return leftValue - rightValue;
			break;
		}
		}
	}
}


void printTheTree(TreeNode* currentNode)
{
	if (currentNode->sign == '$')
	{
		cout << currentNode->value;
	}
	else
	{
		cout << '(';
		printTheTree(currentNode->left);
		cout << ' ' << currentNode->sign << ' ';
		printTheTree(currentNode->right);
		cout << ')';
	}
	delete currentNode;
}
