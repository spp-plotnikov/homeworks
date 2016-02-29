#include "quicksorter.h"
#include <memory>

using namespace std;

void QuickSorter::sort(int *array, int length)
{
    qSortFunction(array, 0, length - 1);
}


void QuickSorter::qSortFunction(int arrayOfElements[], int start, int finish)
{
    int middle = arrayOfElements[(finish + start) / 2];
    int s = start;
    int f = finish;
    while (s <= f)
    {
        while (arrayOfElements[s] < middle)
        {
            s++;
        }
        while (arrayOfElements[f] > middle)
        {
            f--;
        }
        if (s <= f)
        {
            swap(arrayOfElements[s], arrayOfElements[f]);
            s++;
            f--;
        }
    }
    if (start < f)
    {
        qSortFunction(arrayOfElements, start, f);
    }
    if (s < finish)
    {
        qSortFunction(arrayOfElements, s, finish);
    }
}
