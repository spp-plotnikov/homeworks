#pragma once

struct TreeNode;
struct StackNode;

struct Stack
{
	StackNode *top = nullptr;
};

__declspec(dllexport) void push(Stack*, TreeNode*);
__declspec(dllexport) TreeNode* pop(Stack*);
__declspec(dllexport) bool isEmpty(Stack*);
__declspec(dllexport) Stack* createSortedStack();
__declspec(dllexport) void deleteSortedStack(Stack*);