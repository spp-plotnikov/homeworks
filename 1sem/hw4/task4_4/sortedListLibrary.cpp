#include "sortedListLibrary.h"
#include <iostream>

using namespace std;

ListNode* createNewElement(int, ListNode*);

List createList()
{
    List newList = {nullptr};
    return newList;
}


void printList(List *thisList)
{
    ListNode *current = thisList->first;
    if (current == nullptr)
    {
        cout << "The list is empty" << endl;
    }
    else
    {
        while (current != nullptr)
        {
            cout << current->value << " ";
            current = current->next;
        }
    }
}


void addValueToSortedList(List *thisList, int newValue)
{
    ListNode *current = thisList->first;
    if (current == nullptr)
    {
        thisList->first = createNewElement(newValue, NULL);
    }
    else
    {
        ListNode *tempPrevious = current;
        while (current != nullptr &&  current->value <= newValue)
        {
            tempPrevious = current;
            current = current->next;
        }
        ListNode *newElement = createNewElement(newValue, current);
        if (tempPrevious != current)
        {
            tempPrevious->next = newElement;
        }
        else
        {
            thisList->first = newElement;
        }
    }
}


void removeValueFromSortedList(List *thisList, int forRemovalValue)
{
    ListNode *current = thisList->first;
    ListNode *tempPrevious = current;
    bool isFound = false;
    while (current != nullptr)
    {
        if (current->value == forRemovalValue)
        {
            if (current == thisList->first)
            {
                thisList->first = current->next;
                delete current;
            }
            else
            {
                tempPrevious->next = current->next;
                delete current;
            }
            isFound = true;
            break;
        }
        else
        {
            tempPrevious = current;
            current = current->next;
        }
    }
    if (!isFound)
    {
        cout << "This value is not found!" << endl;
    }
}

void removeList(List* thisList)
{
    while (thisList->first != nullptr)
    {
        ListNode *temp = thisList->first->next;
        delete thisList->first;
        thisList->first = temp;
    }
}

ListNode* createNewElement(int newValue, ListNode* newPointer)
{
    ListNode *newElement = new ListNode;
    newElement->value = newValue;
    newElement->next = newPointer;

    return newElement;
}
