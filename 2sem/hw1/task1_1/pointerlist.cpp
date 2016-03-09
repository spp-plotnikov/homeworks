#include "pointerlist.h"
#include <iostream>

using namespace std;

void PointerList::add(int value)
{
    first = new ListNode(value, first);
}


bool PointerList::isFound(int target) const
{
    ListNode *current = first;
    while (current)
    {
        if (current->getValue() == target)
            return true;
        current = current->next;
    }
    return false;
}


void PointerList::remove(int target)
{
    ListNode *current = first;
    ListNode *previous = current;
    while (current)
    {
        if (current->getValue() == target)
        {
            if (current == first)
            {
                first = current->next;
            }
            else
            {
                previous->updateNext(current->next);
            }
            delete current;
            break;
        }
        previous = current;
        current = current->next;
    }
}


void PointerList::print() const
{
    ListNode *current = first;
    while (current)
    {
        cout << current->getValue() << " ";
        current = current->next;
    }
    cout << endl;
}


PointerList::~PointerList()
{
    ListNode *current = first;
    ListNode *temp;
    while (current)
    {
        temp = current->next;
        delete current;
        current = temp;
    }
}


//----------------------------------------------------------------------


PointerList::ListNode::ListNode(int newValue, ListNode *newNext)
{
    value = newValue;
    next = newNext;
}


void PointerList::ListNode::updateNext(ListNode *newNext)
{
    next = newNext;
}


int PointerList::ListNode::getValue()
{
    return value;
}
