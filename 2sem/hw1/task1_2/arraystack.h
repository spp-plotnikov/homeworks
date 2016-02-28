#pragma once
#include "stack.h"
#include <iostream>

using namespace std;

template <typename Type>
class ArrayStack : public Stack<Type>
{
public:
    ArrayStack();
    void push(const Type);
    Type pop();
    Type viewTheTop() const;
    ~ArrayStack();
private:
    int size;
    int quantity;
    Type *array;
private:
    void resize();
};


//--------------------------------------


template <typename Type>
ArrayStack<Type>::ArrayStack()
{
    size = 32;
    quantity = 0;
    array = new Type[size + 1];
}


template <typename Type>
void ArrayStack<Type>::push(const Type value)
{
    array[quantity] = value;
    quantity++;
    if (quantity >= size)
    {
        size *= 2;
        resize();
    }
}


template <typename Type>
Type ArrayStack<Type>::pop()
{
    Type temp = viewTheTop();
    if (quantity > 0)
        quantity--;
    if (size > 32 && quantity == size / 2 - 1)
    {
        size /= 2;
        resize();
    }
    return temp;
}


template <typename Type>
Type ArrayStack<Type>::viewTheTop() const
{
    if (quantity > 0)
    {
        return array[quantity - 1];
    }
    else
    {
        return NULL;     //  How to report a bug?
    }
}


template <typename Type>
ArrayStack<Type>::~ArrayStack()
{
    delete []array;
}


template <typename Type>
void ArrayStack<Type>::resize()
{
    Type *temp = new Type[size + 1];
    for (int i = 0; i < quantity; i++)
    {
        temp[i] = array[i];
    }
    delete []array;
    array = temp;
}
