#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;

long long loopFunction(int);
long long recursionFunction(int);

int main()
{
    cout << "This application calculates the Fibonacci number" << endl;
    cout << "Select the method of calculation. 1 - recursively. 2 - iteratively." << endl;

    int method = 0;
    cin >> method;

    if (method != 1 && method != 2)
    {
        cout << "Error: the method is not identified" << endl;
    }
    else
    {
        cout << "Please enter element index" << endl;

        int elementIndex = 0;
        cin >> elementIndex;

        cout << "The result of calculations: ";
        if (method == 1)
        {
            cout << recursionFunction(elementIndex) << endl;
        }
        else
        {
            cout << loopFunction(elementIndex) << endl;
        }
    }
    return 0;
}


long long loopFunction(int elementIndex)
{
    long long current = 1;
    long long previous = 1;
    for (int i = 2; i < elementIndex; i++)  //we start the calculations from the 2nd element
    {
        swap(current, previous);
        current += previous;
    }
    return current;
}


long long recursionFunction(int elementIndex)
{
    if (elementIndex < 3)
    {
        return 1;
    }
    else
    {
        return recursionFunction(elementIndex - 2) + recursionFunction(elementIndex - 1);
    }
}
