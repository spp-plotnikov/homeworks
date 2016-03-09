#pragma once

/// Interface of the sorter.
/*!
    \author © Sasha Plotnikov Production, Ltd.

    The parent class. Does not have implementation of methods,
    all methods are virtual and implemented in child-classes.
*/

class Sorter
{
public:
    /*!
        This function sorts the array of elements.
        \param array The target array
        \param length The length of that array
    */
    virtual void sort(int *array, int length) = 0;
    virtual ~Sorter() {}
};
