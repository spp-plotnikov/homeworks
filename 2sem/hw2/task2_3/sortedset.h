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
    virtual void add(const Type *newValue) = 0;
    virtual void remove(const Type *target) = 0;
    virtual bool isFound(const Type *target) const = 0;
    virtual void displayContent() const = 0;
    virtual ~SortedSet() {}
};
