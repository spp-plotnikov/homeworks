#pragma once

#include "avltree.h"

/*!
 *   \brief  Interface of the module for working with the sorted set.
 *   \author © Sasha Plotnikov Production, Ltd.
 */

template <typename Type>
class SortedSet
{
public:
    ///  \param newValue will be added to set
    void add(const Type *newValue);
    ///  \param target will be removed from set
    void remove(const Type *target);
    ///  \returns true if set contains target
    bool isFound(const Type *target) const;
    ///  \brief prints content in ascending order
    void displayContent() const;
    ~SortedSet();

    /*!
     * In the sorted set elements must appear only once.
     * If you add one item twice, you will catch this exception.
     */
    class ElementExistsException
    {
    };
private:
    AVLTree<Type> *tree = new AVLTree<Type>();
};


//-----------------------------------------


template <typename Type>
SortedSet<Type>::~SortedSet()
{
    delete tree;
}


template <typename Type>
void SortedSet<Type>::add(const Type *newValue)
{
    if (!isFound(newValue))
    {
        tree->add(newValue);
    }
    else
    {
        throw ElementExistsException();
    }
}


template <typename Type>
void SortedSet<Type>::remove(const Type *target)
{
    tree->remove(target);
}


template <typename Type>
bool SortedSet<Type>::isFound(const Type *target) const
{
    return tree->isFound(target);
}


template <typename Type>
void SortedSet<Type>::displayContent() const
{
    tree->displayContent();
}
