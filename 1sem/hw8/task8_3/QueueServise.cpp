#include "QueueServise.h"


void pushBack(Queue *thisQueue, int newValue)
{
	QueueNode *newNode = new QueueNode;
	newNode->value = newValue;
	newNode->next = thisQueue->front;
	thisQueue->front = newNode;
	if (newNode->next == nullptr)
	{
		thisQueue->tail = newNode;
	}
	else
	{
		newNode->next->previous = newNode;
	}
}


int popFront(Queue *thisQueue)
{
	if (!isEmpty(thisQueue))
	{
		QueueNode *temp = thisQueue->tail;
		thisQueue->tail = temp->previous;
		int currentValue = temp->value;
		if (thisQueue->tail != nullptr)
		{
			thisQueue->tail->next = nullptr;
		}
		else
		{
			thisQueue->front = nullptr;
		}
		delete temp;
		return currentValue;
	}
}


bool isEmpty(Queue *thisQueue)
{
	return (thisQueue->front == nullptr);
}
