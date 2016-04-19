#pragma once
#include "deletingfromemptyqueue.h"

using namespace std;

/*!
    \brief The template for working with the priority queue.
    \author © Sasha Plotnikov Production, Ltd.
*/

template <typename Type>
class PriorityQueue
{
public:
    PriorityQueue() {}
    /*!
     * \brief enqueue() adds new element to the queue
     * \param value value of new element
     * \param key priority of new element
     */
    void enqueue(const Type value, const int key);
    /// \returns the value with highest priority and removes it from queue
    Type dequeue();
    bool isEmpty() const;
    ~PriorityQueue();
private:
    /// Class for working with the nodes of queue
    class QueueNode
    {
    public:
        QueueNode(const Type newValue, const int key, QueueNode *newNext, QueueNode *newPrevious);
        Type getValue() const;
        int getKey() const;
        QueueNode* getNext() const;
        QueueNode* getPrevious() const;

        Type value;
        int key;
        QueueNode *next;
        QueueNode *previous;
    };

    QueueNode *front = NULL;
    QueueNode *tail = NULL;
};


//------------------------------------------------------------------------


template <typename Type>
void PriorityQueue<Type>::enqueue(const Type value, const int key)
{
    if (!tail)
    {
        tail = new QueueNode(value, key, NULL, NULL);
        front = tail;
    }
    else
    {
        QueueNode *current = tail;
        QueueNode *tempPrevious = current;
        while (current != NULL &&  current->getKey() > key)
        {
            tempPrevious = current;
            current = current->next;
        }
        QueueNode *newElement = new QueueNode(value, key, current, tempPrevious);
        if (tempPrevious != current)
        {
            tempPrevious->next = newElement;
        }
        else
        {
            newElement->previous = NULL;
            tail = newElement;
        }
        if (!current)
        {
            front = newElement;
        }
        else
        {
            current->previous = newElement;
        }
    }
}


template <typename Type>
Type PriorityQueue<Type>::dequeue()
{
    if (!isEmpty())
    {
        QueueNode *temp = front;
        front = front->getPrevious();
        Type inFront = temp->getValue();
        delete temp;
        return inFront;
    }
    else
    {
        throw DeletingFromEmptyQueue();
    }
}


template <typename Type>
bool PriorityQueue<Type>::isEmpty() const
{
    return (!front);
}


template <typename Type>
PriorityQueue<Type>::~PriorityQueue()
{
    while (!isEmpty())
    {
        dequeue();
    }
}


//------------------------------------------------------------------------


template <typename Type>
PriorityQueue<Type>::QueueNode::QueueNode(const Type newValue, const int newKey, QueueNode *newNext, QueueNode *newPrevious)
{
    value = newValue;
    key = newKey;
    next = newNext;
    previous = newPrevious;
}


template <typename Type>
int PriorityQueue<Type>::QueueNode::getKey() const
{
    return key;
}


template <typename Type>
Type PriorityQueue<Type>::QueueNode::getValue() const
{
    return value;
}


template <typename Type>
typename PriorityQueue<Type>::QueueNode* PriorityQueue<Type>::QueueNode::getNext() const
{
    return next;
}


template <typename Type>
typename PriorityQueue<Type>::QueueNode* PriorityQueue<Type>::QueueNode::getPrevious() const
{
    return previous;
}
