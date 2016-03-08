#pragma once

/// Interface of the module for working with the stack.
/*!
    \author © Sasha Plotnikov Production, Ltd.

    The parent class. Does not have implementation of methods,
    all methods are virtual and implemented in child-classes.
*/

template <typename Type>
class Stack
{
public:
    virtual void push(const Type value) = 0;
    virtual Type pop() = 0;
    virtual Type viewTheTop() const = 0;
    virtual ~Stack() {}
};
