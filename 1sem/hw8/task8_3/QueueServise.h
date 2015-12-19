#pragma once


struct  QueueNode
{
	int value;
	QueueNode *next = nullptr;
	QueueNode *previous = nullptr;
};

struct Queue
{
	QueueNode *front = nullptr;
	QueueNode *tail = nullptr;
};


__declspec(dllexport)  void pushBack(Queue*, int);
__declspec(dllexport)  int popFront(Queue*);
__declspec(dllexport)  bool isEmpty(Queue*);
