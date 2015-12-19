#include "stackServices.h"

char viewTheTop(Stack *&signs)
{
	return signs->symbol;
}


void removeTop(Stack *&newNext)
{
	Stack *newStack = newNext;
	newNext = newNext->next;
	delete newStack;
}


char pop(Stack *&newNext)
{
	char temp = newNext->symbol;
	removeTop(newNext);
	return temp;
}


void push(Stack *&newNext, const char newSign)
{
	Stack *newStack = new Stack;
	newStack->symbol = newSign;
	newStack->next = newNext;
	newNext = newStack;
}
