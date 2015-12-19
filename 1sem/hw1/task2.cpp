#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

long long division(long long, long long);

int main()
{
    cout << "This application returns the integer division A by B" << endl;
    cout << "Please enter A and B" << endl;

    long long variableA = 0;
    long long variableB = 0;
    cin >> variableA >> variableB;

    if (variableB == 0)
    {
        cout << "Error: division by zero" << endl;
    }
    else
    {
        cout << "The result of calculations: ";
        long long i = 0;
        if (variableA * variableB > 0)
        {
            i = division(variableA, variableB);
        }
        else if (variableA * variableB < 0)
        {
            i = - division(variableA, variableB);
        }
        cout << i << endl;
    }
    return 0;
}

long long division(long long variableA, long long variableB)
{
    variableA = abs(variableA);
    variableB = abs(variableB);
    long long i = 0;
    while (variableA - variableB >= 0)
    {
        variableA -= variableB;
        i++;
    }
    return i;
}
