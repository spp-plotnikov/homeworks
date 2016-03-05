#pragma once
#include <iostream>

using namespace std;

class Printer
{
public:
    virtual void print(int **array, const int size) = 0;
    virtual ~Printer() {}
protected:
    void printTheArray(int **array, const int size, ostream &out) const;
    void printTheElements(ostream &out, int **arrayOfDigits, int start, int length) const;
};
