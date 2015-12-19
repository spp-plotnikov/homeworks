#include "stackServicesDouble.h"


void removeTop(StackOfDoubles *&newNext)
{
	StackOfDoubles *newStack = newNext;
	newNext = newNext->next;
	delete newStack;
}


double pop(StackOfDoubles *&newNext)
{
	double temp = newNext->value;
	removeTop(newNext);
	return temp;
}


void push(StackOfDoubles *&newNext, const double newValue)
{
	StackOfDoubles *newStack = new StackOfDoubles;
	newStack->value = newValue;
	newStack->next = newNext;
	newNext = newStack;
}