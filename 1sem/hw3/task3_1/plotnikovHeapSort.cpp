#include "plotnikovHeapSort.h"

using namespace std;

__declspec(dllexport) void siftDown(int arrayOfElements[], int, int);

void heapSortFunction(int arrayOfElements[], int quantity)
{
	for (int i = (quantity / 2) - 1; i >= 0; i--)
	{
		siftDown(arrayOfElements, i, quantity);
	}
	for (int i = quantity - 1; i >= 1; i--)
	{
		int t = arrayOfElements[0];
		arrayOfElements[0] = arrayOfElements[i];
		arrayOfElements[i] = t;
		siftDown(arrayOfElements, 0, i);
	}
}

void siftDown(int arrayOfElements[], int root, int bottom)
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
			int t = arrayOfElements[root];
			arrayOfElements[root] = arrayOfElements[maxChild];
			arrayOfElements[maxChild] = t;
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
