#pragma once
#include "printer.h"

/// prints the array in spiral order to the console
/*!
    \author © Sasha Plotnikov Production, Ltd.

    This printer prints the numbers from the array of size NxN
    in a spiral starting from the centre. N must be odd.
    Prints data to the console.
    This is the child class. Inherits from Printer.
*/

class ConsolePrinter : public Printer
{
public:
    /*!
        This method prints the elements of the array in spiral order
        \param array Source array
        \param size The size of the array (N)
    */
    void print(int **array, const int size);
};
