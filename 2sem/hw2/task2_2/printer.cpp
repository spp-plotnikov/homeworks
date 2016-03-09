#include <iostream>
#include "printer.h"

using namespace std;

void Printer::printTheArray(int **array, const int size, ostream &out) const
{
    out << "The original array:" << endl;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            out << array[i][j] << ' ';
        }
        out << endl;
    }

    out << "Bypass on spiral: " << endl;
    const int centre = size / 2;
    out << array[centre][centre] << ' ';
    if (centre > 0)
    {
        printTheElements(out, array, centre - 1, 2);
    }
    out << endl;
}


void Printer::printTheElements(ostream &out, int **arrayOfDigits, int start, int length) const
{
    if (start >= 0)
    {
        for (int i = 1; i <= length; i++)
        {
            out << arrayOfDigits[start][start + i] << ' ';
        }
        for (int i = 1; i <= length; i++)
        {
            out << arrayOfDigits[start + i][start + length] << ' ';
        }
        for (int i = 1; i <= length; i++)
        {
            out << arrayOfDigits[start + length][start + length - i] << ' ';
        }
        for (int i = 1; i <= length; i++)
        {
            out << arrayOfDigits[start + length - i][start] << ' ';
        }
        printTheElements(out, arrayOfDigits, start - 1, length + 2);
    }
}
