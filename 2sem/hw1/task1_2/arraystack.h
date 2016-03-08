#pragma once
#include "stack.h"
#include <iostream>

using namespace std;

/// Implementation of the module for working with the stack (arrays).
/*!
    \author © Sasha Plotnikov Production, Ltd.

    The child class. Inherits from Stack.
    The class uses the arrays to implement Stack functionality
*/

template <typename Type>
class ArrayStack : public Stack<Type>
{
public:
    ArrayStack() {}
    void push(const Type value);
    Type pop();
    Type viewTheTop() const;
    ~ArrayStack();
private:
    /*!
       \brief this method resizes the array

       If the array is full or filled to half, then
       this method increases or reduces its size by half, respectively.
    */
    void resize();

    int size = 32;    ///<  Starting size of the array
    int quantity = 0;
    Type *array = new Type[size + 1];
};


//--------------------------------------


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
