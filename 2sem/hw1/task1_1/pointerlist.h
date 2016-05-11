#pragma once
#include <iostream>
#include "list.h"

/// Implementation of the module for working with the list (pointers).
/*!
    \author © Sasha Plotnikov Production, Ltd.

    The child class. Inherits from List.
    The class uses the pointers to implement List functionality
*/

class PointerList : public List
{
public:
    PointerList() {}
    virtual void add(int value);
    virtual bool isFound(int target) const;
    virtual void remove(int target);
    virtual void print() const;
    virtual ~PointerList();
private:
    /// Class for working with the nodes of list
    class ListNode
    {
    public:
        /*!
           Constructor creates new node with value newValue
           and pointer to the next node newNext
        */
        ListNode(int newValue, ListNode *newNext);
        void updateNext(ListNode *newNext);
        int getValue();

        int value;
        ListNode *next;
    };

    ListNode *first = NULL;
};
