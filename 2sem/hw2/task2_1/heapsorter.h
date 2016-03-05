#pragma once
#include "sorter.h"

class HeapSorter : public Sorter
{
public:
    void sort(int *array, int length);
private:
    void siftDown(int *arrayOfElements, int root, int bottom);
};
