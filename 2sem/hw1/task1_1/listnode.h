#pragma once

class ListNode
{
public:
    int value;
    ListNode *next;
public:
    ListNode(int, ListNode*);
    void updateNext(ListNode*);
    int getValue();
};
