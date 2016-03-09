#pragma once
#include "sorter.h"

/// Implementation of the sorter (quicksort).
/*!
    \author © Sasha Plotnikov Production, Ltd.

    The child class. Inherits from Sorter.
    The class uses a quickSort to implement overridden method sort()
*/

class QuickSorter : public Sorter
{
public:
    /*!
        This function sorts the array of elements.
        \param array The target array
        \param length The length of that array
    */
    void sort(int *array, int length);
private:
    void qSortFunction(int *arrayOfElements, int start, int finish);
};
