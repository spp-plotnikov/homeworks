#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

void qSortFunction(int arrayOfElements[], int, int);

int main()
{
    cout << "This application will sort your array ascending very quickly" << endl;
    cout << "Please enter the quantity of elements" << endl;

    int quantity = 0;
    cin >> quantity;

    cout << "Please enter your " << quantity << " elements of the array" << endl;
    int arrayOfElements[1000] = {};
    for (int i = 1; i <= quantity; i++)
    {
        cin >> arrayOfElements[i];
    }

    qSortFunction(arrayOfElements, 1, quantity);

    cout << "Result of sorting: " << endl;
    for (int i = 1; i <= quantity; i++)
    {
        cout << arrayOfElements[i] << " ";
    }
    cout << endl;

    return 0;
}


void qSortFunction(int arrayOfElements[], int start, int finish)
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
