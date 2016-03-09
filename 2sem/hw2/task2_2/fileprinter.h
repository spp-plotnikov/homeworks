#pragma once
#include <fstream>
#include "printer.h"

/// prints the array in spiral order to the file
/*!
    \author © Sasha Plotnikov Production, Ltd.

    This printer prints the numbers from the array of size NxN
    in a spiral starting from the centre. N must be odd.
    Prints data to the file that the user chooses.
    This is the child class. Inherits from Printer.
*/

class FilePrinter : public Printer
{
public:
    /*!
        \brief the constructor opens output file stream
        \param theFileName The name of users file
    */
    FilePrinter(char *theFileName);
    /*!
        This method prints the elements of the array in spiral order
        \param array Source array
        \param size The size of the array (N)
    */
    void print(int **array, const int size);
    /// the destructor closes the output file stream
    ~FilePrinter();
private:
    ofstream fout;
};
