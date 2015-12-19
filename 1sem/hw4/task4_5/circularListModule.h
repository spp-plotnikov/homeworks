#pragma once


struct ListNode
{
	int value;
	ListNode *next;
};

struct CircularList
{
	ListNode *first;
};


__declspec(dllexport)  CircularList createCircularList(int n);
__declspec(dllexport)  int findTheFlaviusJosephusPosition(CircularList*, const int);