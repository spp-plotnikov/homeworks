#pragma once

#include "avltree.h"

/*!
 *   \brief Implementation of the module for working with the set
 *   \author © Sasha Plotnikov Production, Ltd.
 *   \warning You must use the data types that can be compared
 *   \details module provides a wide range of possibilities: you can intersect and merge sets
 */

template <typename Type>
class Set
{
public:
    /// \param value will be added to the set
    void add(Type &value);
    /// \returns true if value was successfully removed
    bool remove(Type &value);
    /// \returns true if the set contains the value
    bool find(Type &value) const;
    /// \brief intersect this set with other set
    void setIntersection(Set<Type> &otherSet);
    /// \brief merge this set with other set
    void setUnion(Set<Type> &otherSet);
    ~Set();

private:
    AVLTree<Type> *tree = new AVLTree<Type>();
};


//-------------------------------------------------------


template <typename Type>
Set<Type>::~Set()
{
    delete tree;
}


template <typename Type>
void Set<Type>::add(Type &value)
{
    tree->add(&value);
}


template <typename Type>
bool Set<Type>::remove(Type &value)
{
    if (!find(value))
        return false;
    tree->remove(&value);
    return true;
}


template <typename Type>
bool Set<Type>::find(Type &value) const
{
    return tree->isFound(&value);
}


template <typename Type>
void Set<Type>::setIntersection(Set<Type> &otherSet)
{

}


template <typename Type>
void Set<Type>::setUnion(Set<Type> &otherSet)
{

}


TODO: tests (and for AVLTree)
