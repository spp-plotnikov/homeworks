#pragma once
#include "sorter.h"

class QuickSorter : public Sorter
{
public:
    void sort(int *array, int length);
private:
    void qSortFunction(int *arrayOfElements, int start, int finish);
};
