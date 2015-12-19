#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

void reverse(int arrayOfNumbers[], int, int);

int main()
{
    cout << "This application swaps the first M elements and latest N elements in the array" << endl;
    cout << "Please enter M and N" << endl;

    int firstM = 0;
    int lastN = 0;
    cin >> firstM >> lastN;
    int all = firstM + lastN;

    cout << "Please enter (M + N) array elements and press Enter" << endl;

    int arrayOfNumbers[1000] = {}; //It is assumed that the quantity does not exceed 1000
    for (int i = 1; i <= all; i++)
    {
        cin >> arrayOfNumbers[i];
    }

    reverse(arrayOfNumbers, 1, firstM);
    reverse(arrayOfNumbers, firstM + 1, all);
    reverse(arrayOfNumbers, 1, all);

    cout << "The result of the execution of the application: " << endl;
    for (int i = 1; i <= all; i++)
    {
        cout << arrayOfNumbers[i] << " ";
    }
    cout << endl;
    return 0;
}



void reverse(int arrayOfNumbers[], int start, int end)
{
    int middle = (end - start) / 2  + start;  //Defined the middle of the interval
    for (int i = start; i <= middle; i++)
    {
        swap(arrayOfNumbers[i], arrayOfNumbers[end - i + start]);
    }
}
