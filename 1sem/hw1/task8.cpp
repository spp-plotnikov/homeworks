#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;

long long loopFunction(long long);
long long recursionFunction(long long);

int main()
{
    cout << "This application calculates the factorial" << endl;
    cout << "Select the method of calculation. 1 - recursively. 2 - iteratively." << endl;

    int method = 0;
    cin >> method;

    if (method != 1 && method != 2)
    {
        cout << "Error: the method is not identified" << endl;
    }
    else
    {
        cout << "Please enter X" << endl;

        long long variableX = 0;
        cin >> variableX;

        cout << "The result of calculations: ";
        if (method == 1)
        {
            cout << recursionFunction(variableX) << endl;
        }
        else
        {
            cout << loopFunction(variableX) << endl;
        }
    }
    return 0;
}


long long loopFunction(long long variableX)
{
    long long result = 1;
    for (int i = 1; i <= variableX; i++)
    {
        result *= i;
    }
    return result;
}


long long recursionFunction(long long variableX)
{
    if (variableX < 2)
    {
        return 1;
    }
    else
    {
        return variableX * recursionFunction(variableX - 1);
    }
}
