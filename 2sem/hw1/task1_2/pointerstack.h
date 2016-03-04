#pragma once
#include <iostream>
#include "stack.h"
#include "stacknode.h"

using namespace std;

template <typename Type>
class PointerStack : public Stack<Type>
{
public:
    PointerStack();
    void push(const Type);
    Type pop();
    Type viewTheTop() const;
    ~PointerStack();
private:
    StackNode<Type> *top;
};


//-----------------------------------------------


template <typename Type>
PointerStack<Type>::PointerStack()
{
    top = NULL;
}


template <typename Type>
void PointerStack<Type>::push(const Type value)
{
    top = new StackNode<Type>(value, top);
}


template <typename Type>
Type PointerStack<Type>::pop()
{
    Type onTop = viewTheTop();
    if (top)
    {
        StackNode<Type> *temp = top;
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