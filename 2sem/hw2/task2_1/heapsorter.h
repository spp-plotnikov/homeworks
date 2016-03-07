#pragma once
#include "sorter.h"

/// Implementation of the sorter (heapsort).
/*!
    \author © Sasha Plotnikov Production, Ltd.

    The child class. Inherits from Sorter.
    The class uses a heapSort to implement overridden method sort()
*/

class HeapSorter : public Sorter
{
public:
    /*!
        This function sorts the array of elements.
        \param array The target array
        \param length The length of that array
    */
    void sort(int *array, int length);
private:
    void siftDown(int *arrayOfElements, int root, int bottom);
};
