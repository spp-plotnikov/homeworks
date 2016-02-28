#pragma once

template <typename Type>
class StackNode
{
public:
    Type value;
    StackNode *next;
public:
    StackNode(const Type, StackNode*);
    Type getValue();
    StackNode* getNext();
};


//--------------------------------


template <typename Type>
StackNode<Type>::StackNode(const Type newValue, StackNode *newNext)
{
    value = newValue;
    next = newNext;
}


template <typename Type>
Type StackNode<Type>::getValue()
{
    return value;
}


template <typename Type>
StackNode<Type>* StackNode<Type>::getNext()
{
    return next;
}
