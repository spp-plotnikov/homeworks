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
    /*!
    * \param sizeOfArray is incremented by the size of the array
    * \returns pointer to array containing content of set in ascending order
    * \warning you must delete an array (it is dynamic)
    */
    Type* getContent(int &sizeOfArray);
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
    int array1Size = 0;
    int array2Size = 0;
    Type *array1 = tree->toPresentContentInArray(array1Size);
    Type *array2 = otherSet.getContent(array2Size);

    delete tree;
    tree = new AVLTree<Type>();

    int i = 0;
    int j = 0;
    while (i < array1Size && j < array2Size)
    {
        if (array1[i] == array2[j])
        {
            add(array1[i]);
            i++;
            j++;
        }
        else if (array1[i] < array2[j])
        {
            i++;
        }
        else
        {
            j++;
        }
    }

    delete []array1;
    delete []array2;
}


template <typename Type>
void Set<Type>::setUnion(Set<Type> &otherSet)
{
    int arraySize = 0;
    Type *array = otherSet.tree->toPresentContentInArray(arraySize);
    for (int i = 0; i < arraySize; i++)
        add(array[i]);
    delete []array;
}


template <typename Type>
Type* Set<Type>::getContent(int &sizeOfArray)
{
    return tree->toPresentContentInArray(sizeOfArray);
}
