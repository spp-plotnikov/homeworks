#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;

int greatestCommonDivisor(int, int);

int main()
{
    cout << "This application prints all simple irreducible fractions ";
    cout << "made between 0 and 1,  the denominators do not exceed N" << endl;
    cout << "Please enter natural number N" << endl;

    int greatestDenominator = 0;
    cin >> greatestDenominator;
    if (greatestDenominator < 1)
    {
        cout << "Error: invalid value N!" << endl;
    }
    else
    {
        const int maxQuantity = 10000;   //It is assumed that the quantity does not exceed 10000
        int numerator[maxQuantity] = {};
        int denominator[maxQuantity] = {};
        int quantity = 0;
        for (int i = 1; i <= greatestDenominator; i++)
        {
            for (int j = 1; j <= greatestDenominator; j++)
            {
                if (i < j && greatestCommonDivisor(i, j) == 1)
                {
                    quantity++;
                    numerator[quantity] = i;
                    denominator[quantity] = j;
                }
            }
        }
        for (int i = 1; i < quantity; i++)
        {
            for (int j = i + 1; j <= quantity; j++)
            {
                if (numerator[i] * denominator[j] > numerator[j] * denominator[i])
                {
                    swap(numerator[i], numerator[j]);
                    swap(denominator[i], denominator[j]);
                }
            }
        }

        cout << "The result of the execution of the application: " << endl;
        for (int i = 1; i <= quantity; i++)
        {
            cout << numerator[i] << "/" << denominator[i] << " ";
        }
    }

    return 0;
}


int greatestCommonDivisor(int a, int b)
{
    while (a != b)
    {
        if (a > b)
        {
            a -= b;
        }
        else
        {
            b -= a;
        }
    }
    return a;
}
