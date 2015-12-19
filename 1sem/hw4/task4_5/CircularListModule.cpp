#include "circularListModule.h"

ListNode* fillOutList(int, ListNode*);


CircularList createCircularList(int n)
{
	ListNode *newElement = new ListNode;
	newElement->value = 1;
	newElement->next = fillOutList(n, newElement);
	CircularList newList = {newElement};
	return newList;
}


ListNode* fillOutList(int n, ListNode* following)
{
	if (n == 1)
	{
		return following;
	}
	else
	{
		ListNode *newElement = new ListNode;
		newElement->value = n;
		newElement->next = following;
		fillOutList(n - 1, newElement);
	}
}


int findTheFlaviusJosephusPosition(CircularList* warriors, const int m)
{
	if (warriors->first == warriors->first->next)
	{
		return warriors->first->value;
	}
	else
	{
		ListNode *current = warriors->first;
		ListNode *tempPrevious = current;
		for (int i = 1; i < m; i++)
		{
			tempPrevious = current;
			current = current->next;
		}
		tempPrevious->next = current->next;
		delete current;
		*warriors = {tempPrevious->next};

		findTheFlaviusJosephusPosition(warriors, m);
	}
}