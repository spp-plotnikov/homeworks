#include "pointerlist.h"

using namespace std;

void PointerList::add(int value)
{
    first = new ListNode(value, first);
    count++;
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
            count--;
            break;
        }
        previous = current;
        current = current->next;
    }
}


int PointerList::length() const
{
    return count;
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
