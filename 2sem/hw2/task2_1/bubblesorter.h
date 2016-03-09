#pragma once
#include "sorter.h"

/// Implementation of the sorter (bubblesort, best sorting ever).
/*!
    \author © Sasha Plotnikov Production, Ltd.

    The child class. Inherits from Sorter.
    The class uses a bubbleSort to implement overridden method sort()
*/

class BubbleSorter : public Sorter
{
public:
    /*!
        This function sorts the array of elements.
        \param array The target array
        \param length The length of that array
    */
    void sort(int *array, int length);
};
