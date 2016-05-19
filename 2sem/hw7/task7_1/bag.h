#pragma once

#include "avltree.h"

/*!
 *   \brief  Interface of the module for working with the multiset
 *   \author © Sasha Plotnikov Production, Ltd.
 */
class Bag
{
public:
    /// \param value will be added to bag
    void add(int value);
    /// \returns  true if value was successfully removed
    bool remove(int value);
    /// \returns true if the multiset contains the value
    bool find(int value) const;
    /// \returns the number of such values
    unsigned int getCount(int value) const;
    /*!
    * \param arraySize is incremented by the size of the array
    * \returns pointer to array containing content of multiset in ascending order
    * \warning you must delete an array (it is dynamic)
    */
    int* getContent(int &arraySize) const;
    ~Bag();

private:
    AVLTree<int> *tree = new AVLTree<int>();
};
