#pragma once

/// Interface of the module for working with the sorted set.
/*!
    \author © Sasha Plotnikov Production, Ltd.

    The parent class. Does not have implementation of methods,
    all methods are virtual and implemented in child-classes.
*/

template <typename Type>
class SortedSet
{
public:
    virtual void add(Type *newValue) = 0;
    virtual void remove(Type *target) = 0;
    virtual bool isFound(Type *target) const = 0;
    virtual ~SortedSet() {}
};
