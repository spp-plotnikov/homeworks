#include "heapsorter.h"
#include <memory>

using namespace std;

void HeapSorter::sort(int arrayOfElements[], int quantity)
{
    for (int i = (quantity / 2) - 1; i >= 0; i--)
    {
        siftDown(arrayOfElements, i, quantity);
    }
    for (int i = quantity - 1; i >= 1; i--)
    {
        swap(arrayOfElements[0], arrayOfElements[i]);
        siftDown(arrayOfElements, 0, i);
    }
}


void HeapSorter::siftDown(int arrayOfElements[], int root, int bottom)
{
    int left = 2 * root + 1;
    int right = left + 1;
    int maxChild = left;
    while (maxChild < bottom)
    {
        if (right < bottom)
        {
            if (arrayOfElements[left] < arrayOfElements[right])
            {
                maxChild = right;
            }
        }
        if (arrayOfElements[root] < arrayOfElements[maxChild])
        {
            swap(arrayOfElements[root], arrayOfElements[maxChild]);
        }
        else
        {
            break;
        }
        root = maxChild;
        left = 2 * root + 1;
        right = left + 1;
        maxChild = left;
    }
}
