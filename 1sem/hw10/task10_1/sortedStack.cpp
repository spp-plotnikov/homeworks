#include "sortedStack.h"
#include "HuffmanCoding.h"

struct StackNode
{
	TreeNode *element;
	StackNode *next = nullptr;
};


void removeTop(Stack *stackTop)
{
	StackNode *forRemoval = stackTop->top;
	stackTop->top = forRemoval->next;
	delete forRemoval;
}


TreeNode* pop(Stack *thisStack)
{
	TreeNode *temp = thisStack->top->element;
	removeTop(thisStack);
	return temp;
}


void push(Stack *thisStack, TreeNode *newElement) 
{
	StackNode *newNode = new StackNode;
	newNode->element = newElement;

	StackNode *current = thisStack->top;
	StackNode *previous = current;
	while (current && newElement->weight > current->element->weight)
	{
		previous = current;
		current = current->next;
	}
	newNode->next = current;
	if (isEmpty(thisStack) || current == previous)
	{
		thisStack->top = newNode;
	}
	else
	{
		previous->next = newNode;
	} 
}


bool isEmpty(Stack *thisStack)
{
	return !(thisStack->top);
}


Stack* createSortedStack()
{
	Stack *newStack = new Stack;
	return newStack;
}


void deleteSortedStack(Stack *forRemoval)
{
	while (!isEmpty(forRemoval))
	{
		removeTop(forRemoval);
	}
	delete forRemoval;
}