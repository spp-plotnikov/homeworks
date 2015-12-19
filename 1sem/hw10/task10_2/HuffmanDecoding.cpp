#include "HuffmanDecoding.h"
#include <stdio.h>

struct TreeNode
{
	char symbol;
	bool isSymbol;
	TreeNode *left;
	TreeNode *right;
};

TreeNode* scanTheTree(FILE*);
void decodeByUsingTree(TreeNode*, FILE*, FILE*);
void deleteTree(TreeNode*);
void convert(TreeNode*, FILE*, FILE*);


void decompressTheData(FILE *input, FILE *output)
{
	TreeNode *top = scanTheTree(input);
	decodeByUsingTree(top, input, output);
	deleteTree(top);
}


void deleteTree(TreeNode *current)
{
	if (current->left != nullptr)
	{
		deleteTree(current->left);
	}
	if (current->right != nullptr)
	{
		deleteTree(current->right);
	}
	delete current;
}


TreeNode* scanTheTree(FILE *input)
{
	char symbol = fgetc(input);
	while (symbol == ' ' || symbol == ')')
	{
		symbol = fgetc(input);
	}
	TreeNode *newNode = new TreeNode;
	if (symbol == '(')
	{
		newNode->symbol = fgetc(input);
		newNode->isSymbol = true;
		if (newNode->symbol == 'n' && fgetc(input) == 'o')
		{
			newNode->isSymbol = false;
			for (int i = 1; i <= 3; i++)  // Get rid of the "node" word
			{
				fgetc(input);
			}
		}
		newNode->left = scanTheTree(input);
		newNode->right = scanTheTree(input);
	}
	else
	{
		newNode->symbol = symbol;
		newNode->isSymbol = true;
		if (newNode->symbol == 'n' && fgetc(input) == 'u')
		{
			for (int i = 1; i <= 3; i++)  // Get rid of the "null" word
			{
				fgetc(input);
			}
			delete newNode;
			return nullptr;
		}
	}
	return newNode;
}


void decodeByUsingTree(TreeNode *top, FILE *input, FILE *output)
{
	if (!(top->isSymbol))
	{
		while (!feof(input))
		{
			convert(top, input, output);
		}
	}
	else
	{
		while (!feof(input))
		{
			if (fgetc(input) == '0')
			{
				fprintf(output, "%c", top->symbol);
			}
		}
	}
}


void convert(TreeNode *current, FILE *input, FILE *output)
{
	if (current->isSymbol)
	{
		fprintf(output, "%c", current->symbol);
	}
	else
	{
		char symbol = fgetc(input);
		if (symbol == '0')
		{
			convert(current->left, input, output);
		}
		else if (symbol == '1')
		{
			convert(current->right, input, output);
		}
	}
}
