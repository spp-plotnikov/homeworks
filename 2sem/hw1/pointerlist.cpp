#include "pointerlist.h"
#include "listnode.h"
#include <iostream>

using namespace std;

PointerList::PointerList()
{
    first = NULL;
}


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
