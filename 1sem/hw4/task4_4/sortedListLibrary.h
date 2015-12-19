#pragma once

struct ListNode
{
	int value;
	ListNode *next;
};

struct List
{
	ListNode *first;
};

__declspec(dllexport) List createList();
__declspec(dllexport) void printList(List*);
__declspec(dllexport) void addValueToSortedList(List*, int);
__declspec(dllexport) void removeValueFromSortedList(List*, int);
__declspec(dllexport) void removeList(List*);
