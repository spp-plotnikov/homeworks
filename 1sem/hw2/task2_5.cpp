#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

void heapSortFunction(int arrayOfElements[], int);
void siftDown(int arrayOfElements[], int, int);

int main()
{
    cout << "This application will sort your array ascending very quickly" << endl;
    cout << "Please enter the quantity of elements" << endl;

    int quantity = 0;
    cin >> quantity;

    cout << "Please enter your " << quantity << " elements of the array" << endl;
    int arrayOfElements[1000] = {};  //It is assumed that the quantity does not exceed 1000
    for (int i = 0; i < quantity; i++)
    {
        cin >> arrayOfElements[i];
    }

    heapSortFunction(arrayOfElements, quantity);

    cout << "Result of sorting: " << endl;
    for (int i = 0; i < quantity; i++)
    {
        cout << arrayOfElements[i] << " ";
    }
    cout << endl;

    return 0;
}


void heapSortFunction(int arrayOfElements[], int quantity)
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
