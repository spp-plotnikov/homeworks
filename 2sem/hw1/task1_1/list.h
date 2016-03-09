#pragma once

/// Interface of the module for working with the list.
/*!
    \author © Sasha Plotnikov Production, Ltd.

    The parent class. Does not have implementation of methods,
    all methods are virtual and implemented in child-classes.
*/

class List
{
public:
    List() {}
    virtual void add(int newValue) = 0;
    virtual bool isFound(int target) const = 0;
    virtual void remove(int target) = 0;
    virtual void print() const = 0;
    virtual ~List() {}
};
