#include "listnode.h"

ListNode::ListNode(int newValue, ListNode *newNext)
{
    value = newValue;
    next = newNext;
}


void ListNode::updateNext(ListNode *newNext)
{
    next = newNext;
}


int ListNode::getValue()
{
    return value;
}
