#pragma once
#include <iostream>
#include "stack.h"

using namespace std;

template <typename Type>
class PointerStack : public Stack<Type>
{
public:
    PointerStack() {}
    void push(const Type value);
    Type pop();
    Type viewTheTop() const;
    ~PointerStack();
private:
    class StackNode
    {
    public:
        StackNode(const Type newValue, StackNode *newNext);
        Type getValue();
        StackNode* getNext();

        Type value;
        StackNode *next;
    };

    StackNode *top = NULL;
};


//-----------------------------------------------


template <typename Type>
void PointerStack<Type>::push(const Type value)
{
    top = new StackNode(value, top);
}


template <typename Type>
Type PointerStack<Type>::pop()
{
    Type onTop = viewTheTop();
    if (top)
    {
        StackNode *temp = top;
        top = top->getNext();
        delete temp;
    }
    return onTop;
}


template <typename Type>
Type PointerStack<Type>::viewTheTop() const
{
    if (!top)
        return NULL;     //  How to report a bug?
    return top->getValue();
}


template <typename Type>
PointerStack<Type>::~PointerStack()
{
    while (top)
        pop();
}


//-----------------------------------------------


template <typename Type>
PointerStack<Type>::StackNode::StackNode(const Type newValue, StackNode *newNext)
{
    value = newValue;
    next = newNext;
}


template <typename Type>
Type PointerStack<Type>::StackNode::getValue()
{
    return value;
}


template <typename Type>
typename PointerStack<Type>::StackNode* PointerStack<Type>::StackNode::getNext()
{
    return next;
}
