#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

int main()
{
    cout << "This application displays all the primes up to N" << endl;
    cout << "Please enter N: " << endl;

    int quantity = 0;
    cin >> quantity;

    bool number[100000];  //It is assumed that the quantity does not exceed 100000
    for (int i = 1; i <= quantity; i++)
    {
        number[i] = true;
    }
    for (int i = 2; i <= quantity; i++)
    {
        if (number[i])
        {
            cout << i << " ";
            int k = 2;
            while (i * k <= quantity)
            {
                number[i * k] = false;
                k++;
            }
        }
    }
    return 0;
}
