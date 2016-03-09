#pragma once
#include <iostream>

using namespace std;

/// prints the array in spiral order
/*!
    \author © Sasha Plotnikov Production, Ltd.

    This Printer prints the numbers from the array of size NxN
    in a spiral starting from the centre. N must be odd.
    This is the parent class. It has two child classes.
*/

class Printer
{
public:
    /*!
        This method prints the elements of the array in spiral order
        \param array Source array
        \param size The size of the array (N)
    */
    virtual void print(int **array, const int size) = 0;
    virtual ~Printer() {}
protected:
    /*!
        This is auxiliary method.
        \param array Source array
        \param size The size of the array (N)
        \param out Output stream
    */
    void printTheArray(int **array, const int size, ostream &out) const;
    /// This is auxiliary method.
    void printTheElements(ostream &out, int **arrayOfDigits, int start, int length) const;
};
