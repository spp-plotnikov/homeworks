#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

int main()
{
    const int maxSumm = 9 + 9 + 9;
    int sumNumber[maxSumm + 1] = {};
    int luckyTicketsQuantity = 0;

    for (int hundred = 0; hundred <= 9; hundred++)
    {
        for (int ten = 0; ten <= 9; ten++)
        {
            for (int one = 0; one <= 9; one++)
            {
                sumNumber[hundred + ten + one]++;
            }
        }
    }

    for (int i = 0; i <= maxSumm; i++)
    {
        sumNumber[i] *= sumNumber[i];
        luckyTicketsQuantity += sumNumber[i];
    }

    cout << "Do you know how many lucky tickets there? No? I know :) ";
    cout << "There are " << luckyTicketsQuantity << " lucky tickets!" << endl;
    return 0;
}
