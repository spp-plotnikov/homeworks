#pragma once
#include <iostream>
#include "list.h"

class PointerList : public List
{
public:
    PointerList() {}
    void add(int value);
    bool isFound(int target) const;
    void remove(int target);
    void print() const;
    ~PointerList();
private:
    class ListNode
    {
    public:
        ListNode(int, ListNode*);
        void updateNext(ListNode*);
        int getValue();

        int value;
        ListNode *next;
    };

    ListNode *first = NULL;
};
