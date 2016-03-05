#pragma once

class Sorter
{
public:
    virtual void sort(int *array, int length) = 0;
    virtual ~Sorter() {}
};
