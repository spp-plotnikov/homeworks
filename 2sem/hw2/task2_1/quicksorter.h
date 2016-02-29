#pragma once
#include "sorter.h"

class QuickSorter : public Sorter
{
public:
    void sort(int*, int);
private:
    void qSortFunction(int*, int, int);
};
