#pragma once
#include "sorter.h"

class HeapSorter : public Sorter
{
public:
    void sort(int*, int);
private:
    void siftDown(int*, int, int);
};
