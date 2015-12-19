#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

long long raisingToAPowerPlus(long long, long long);
long double raisingToAPowerMinus(long long, long long);

int main()
{
    cout << "This application returns the result of raising  to a power a^n" << endl;
    cout << "Please enter A and N" << endl;

    long long base = 0;
    long long exponent = 0;
    cin >> base >> exponent;

    cout << "The result of calculations: ";
    if (exponent >= 0)
    {
        cout << raisingToAPowerPlus(base, exponent);
    }
    else
    {
        cout << raisingToAPowerMinus(base, exponent);
    }

    return 0;
}


long long raisingToAPowerPlus(long long base, long long exponent)
{
    long long result = 1;
    for (int i = 1; i <= exponent; i++)
    {
        result *= base;
    }

    return result;
}


long double raisingToAPowerMinus(long long base, long long exponent)
{
    long double result = raisingToAPowerPlus(base, abs(exponent));
    result = 1 / result;
    return result;
}
