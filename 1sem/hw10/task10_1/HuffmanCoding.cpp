#include "HuffmanCoding.h"
#include "sortedStack.h"
#include <stdio.h>
#include <cstring>
#include <climits>

void frequenciesCalculation(int*, FILE*);
void encodeByUsingTree(TreeNode*, FILE*, FILE*);
void preorderTraversal(TreeNode*, FILE*);
void createCodes(char**, TreeNode*, char*, int);
void deleteCodes(char**);
TreeNode* createHuffmanTree(int*);
void deleteTree(TreeNode*);
TreeNode* newNode(bool, char, TreeNode*, TreeNode*, int);

void compressTheData(FILE* input, FILE* output)
{
	int frequencies[UCHAR_MAX] = {};
	frequenciesCalculation(frequencies, input);
	TreeNode *top = createHuffmanTree(frequencies);
	preorderTraversal(top, output);
	fprintf(output, "\n");
	encodeByUsingTree(top, input, output);
	deleteTree(top);
}


void preorderTraversal(TreeNode *current, FILE *output)
{
	if (current != nullptr)
	{
		fprintf(output, " (");
		if (current->isSymbol)
		{
			fprintf(output, "%c", current->symbol);
		}
		else
		{
			fprintf(output, "node");
		}
		preorderTraversal(current->left, output);
		preorderTraversal(current->right, output);
		fprintf(output, ")");
	}
	else
	{
		fprintf(output, " null");
	}
}


void createCodes(char **arrayOfCodes, TreeNode *current, char *code, int length)
{
	length++;
	if (current->isSymbol)
	{
		if (code[0] == '\0')
		{
			strcat(code, "0");
			length++;
		}
		arrayOfCodes[current->symbol + CHAR_MAX] = new char[length];
		strcpy(arrayOfCodes[current->symbol + CHAR_MAX], code);
	}
	else
	{
		strcat(code, "0");
		createCodes(arrayOfCodes, current->left, code, length);
		code[length] = '\0';
		code[length - 1] = '1';
		createCodes(arrayOfCodes, current->right, code, length);
	}
}


void deleteCodes(char** arrayOfCodes)
{
	for (int i = 0; i < UCHAR_MAX; i++)
	{
		if (arrayOfCodes[i])
		{
			delete []arrayOfCodes[i];
		}
	}
}


void deleteTree(TreeNode* current)
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


void frequenciesCalculation(int *frequencies, FILE *input)
{
	const int shift = CHAR_MAX;    // Because char can take on negative values.
	int symbol = 0;
	while (!feof(input))
	{
		symbol = int(fgetc(input)) + shift;
		frequencies[symbol]++;
	}
	frequencies[EOF + shift] = 0;  // Get rid of the EOF character
	rewind(input);
}


void encodeByUsingTree(TreeNode *top, FILE *input, FILE *output)
{
	char *arrayOfCodes[UCHAR_MAX] = {};
	char temp[UCHAR_MAX] = {};
	createCodes(arrayOfCodes, top, temp, 0);
	int symbol = 0;
	while (!feof(input))
	{
		symbol = int(fgetc(input)) + CHAR_MAX;
		if (!feof(input))
		{
			fprintf(output, arrayOfCodes[symbol]);
		}
	}
	deleteCodes(arrayOfCodes);
}


TreeNode* createHuffmanTree(int *frequencies)
{
	const int shift = CHAR_MAX;    // Because char can take on negative values.
	Stack *forTree = createSortedStack();
	for (int i = 0; i < UCHAR_MAX; i++)
	{
		if (frequencies[i] != 0)
		{
		    char symbol = char(i - shift);
			TreeNode *node = newNode(true, symbol, nullptr, nullptr, frequencies[i]);
			push(forTree, node);
		}
	}

	TreeNode *leftChild = nullptr;
	TreeNode *rightChild = nullptr;
	TreeNode *top = nullptr;
	while (!isEmpty(forTree))
	{
		leftChild = pop(forTree);
		if (isEmpty(forTree))
		{
			top = leftChild;
			break;
		}
		rightChild = pop(forTree);
		int newWeight = leftChild->weight + rightChild->weight;
		TreeNode *node = newNode(false, '\0', leftChild, rightChild, newWeight);
		push(forTree, node);
	}
	deleteSortedStack(forTree);
	return top;
}


TreeNode* newNode(bool isSymbol, char symbol, TreeNode *left, TreeNode *right, int weight)
{
    TreeNode *node = new TreeNode;
    node->isSymbol = isSymbol;
    node->left = left;
    node->right = right;
    node->symbol = symbol;
    node->weight = weight;
    return node;
}
