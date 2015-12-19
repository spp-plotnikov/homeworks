#pragma once
#include <iostream>

struct TreeNode
{
	int weight;
	char symbol;
	bool isSymbol;
	TreeNode *left;
	TreeNode *right;
};


__declspec(dllexport) void compressTheData(FILE*, FILE*);